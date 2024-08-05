/*!
 \file      gridMap.h
 \brief     Gridmap which holds information in 2D grid cells.
 \author    Sangyup (Sean) Yi, sean.yi@hyundai.com
 \date      2024. 06. 12
 \version   1.0.0
 \copyright RoboticsLab ART All rights reserved.
*/

#ifndef DTCONTROL_GRIDMAP_H_
#define DTCONTROL_GRIDMAP_H_

// #include "algorithm/robotMacro.h"
#define DOF2 (2)
#define DOF3 (3)
typedef double SYSREAL;
#include <cassert>
#include <cmath>
#include <dtCore/type.h>
#include <dtMath/dtMath.h>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

namespace dtControl
{
using dt::Math::Matrix;
using dt::Math::Vector;
/**
 * GridMap
 *
 *
 * This represents 2D gridmap.
 * Gridmap can be composed of multiple grid layers.
 * Internal data structure for 2D grid is dtMatrix.
 * To minimize memory copy while updating map data, cell indexing is implemented based on 2D ring buffer.
 */
template <uint16_t m_col, uint16_t m_row, typename m_type>
class GridMap
{
public:
    typedef m_type ValueType;
    typedef Vector<DOF2, m_type> Position;      //<! 2D position (x, y) in meter.
    typedef Vector<DOF2, m_type> Size;          //<! size of the map (width, height) in meter.
    typedef Vector<DOF2, int> Index;            //<! cell index (x, y) in the grid map.
    typedef Vector<DOF2, int> Dimension;        //<! cell size(dimension) in x and y direction.
    typedef Matrix<m_col, m_row, m_type> Layer; //<! grid index상의 (x, y)는 dtMatrix에는 (x행, y열)에 저장되며, 따라서 x축 크기(m_col)는 dtMatrix의 행 갯수, y축 크기(m_row)는 열 갯수에 해당됨.
    static const m_type NAN_VAL;                //<! NAN or user-defined double

public:
    GridMap();
    GridMap(const std::vector<std::string> layerNames);
    GridMap(const std::vector<std::string> layerNames, const Index centerIndex);
    ~GridMap();
    const uint16_t col() const { return m_col; }            //<! number of columns in x-direction.
    const uint16_t row() const { return m_row; }            //<! number of rows in y-direction.
    const m_type resolution() const { return _resolution; } //<! cell resolution in meter.

public:                        // properties
    dt::TimeStamp updateTime;  //<! map updated(acquired) time
    dt::TimeStamp receiveTime; //<! data receive time
public:
    /**
     * Get map size(width and height).
     * @return map size in meter.
     */
    const Size &GetSize() const;

    /**
     * Get map width in x direction.
     * @return map width in meter.
     */
    m_type GetWidth() const;

    /**
     * Get map height in y direction.
     * @return map height in meter.
     */
    m_type GetHeight() const;

    /**
     * Get map's far left position.
     * @return map's far left position in meter.
     */
    m_type GetLeft() const;

    /**
     * Get map's far right position.
     * @return map's far right position in meter.
     */
    m_type GetRight() const;

    /**
     * Get map's bottom limit position.
     * @return map's bottom limit position in meter.
     */
    m_type GetBottom() const;

    /**
     * Get map's top limit position.
     * @return map's top limit position in meter.
     */
    m_type GetTop() const;

    /**
     * Get cell index from position.
     * @param[in] position the position in the global frame.
     * @param[out] index the cell index.
     * @return true if position is in the current grid map indexing boundary and it is succeeded to get the corresponding cell index.
     */
    bool GetIndexFromPosition(const Position position, Index &index) const;

    /**
     * Get position from index.
     * @param[in] index the cell index.
     * @param[out] position the position of the cell in the global frame.
     * @return true if succeed to get corresponding position, false if index is out of grid map range.
     */
    bool GetPositionFromIndex(const Index index, Position &position) const;

    /**
     * Set center position.
     * New center position and cell index are caclulated.
     * The new center position is set as the calculated center of the center cell.
     * It invalidates cell data in columns and rows out-of-range due to this SetCenterPosition() function call.
     * @param[in] position new center position to set.
     * @return true if new center position is set.
     */
    bool SetCenterPosition(const Position position);

    /**
     * Move center position and index.
     * New center position and cell index are caclulated.
     * The new center position is set as the calculated center of the center cell.
     * Compared with SetCenterPosition(), it does not invalidate cell data.
     * @param[in] position new center position to set.
     */
    void MoveCenterPosition(const Position position);

    /**
     * Get current center position.
     * @param[out] position center position.
     */
    void GetCenterPosition(Position &position) const;

    /**
     * Get current center position.
     * @return center position.
     */
    Position GetCenterPosition() const;

    /**
     * Get current center cell index.
     * @param[out] index center index.
     */
    void GetCenterIndex(Index &index) const;

    /**
     * Get current center cell index.
     * @return center index.
     */
    Index GetCenterIndex() const;

    /**
     * Get current start cell index.
     * @param[out] index start index.
     */
    void GetStartIndex(Index &index) const;

    /**
     * Get current start cell index.
     * @param[out] index start index.
     * @return start index.
     */
    Index GetStartIndex() const;

    /**
     * Set map frame displacement.
     * @param[out] r map displacement.
     */
    void SetMapDisplacement(const Position &r);

    /**
     * Get map frame displacement.
     * @return map displacement.
     */
    Position GetMapDisplacement() const;

    /**
     * Set layer data.
     * @param[in] key the name of the data layer.
     * @param[in] index the cell index.
     * @param[in] value cell value to set
     */
    void SetLayerData(const std::string &key, const Index index, m_type value);

    /**
     * Get layer data.
     * @param[in] key the name of the data layer.
     * @param[in] index the cell index.
     * @param[out] value cell value
     * @return true if getting cell value succeded.
     */
    bool GetLayerData(const std::string &key, const Index index, m_type &value);

    /**
     * Reset layer data.
     * @param[in] key the name of the data layer.
     * @param[in] index the cell index.
     */
    void ResetLayerData(const std::string &key, const Index index);

    /**
     * Reset whole layer data.
     * @param[in] key the name of the data layer.
     */
    void ResetLayerData(const std::string &key);

    /**
     * Get layer for read-only with its name.
     * @param[in] key the name of the layer.
     * @return the read-only reference to the layer object.
     * @throw std::out_of_range if no map layer with the name is present.
     */
    const Layer &GetLayer(const std::string &key) const;

    /**
     * Get layer with its name.
     * @param[in] key the name of the layer.
     * @return the reference to the layer object.
     * @throw std::out_of_range if no map layer with the name is present.
     */
    Layer &GetLayer(const std::string &key);

    /**
     * Print gridmap information and it's layers values.
     * @param[in] key the name of the new layer. If it is empty string, print values for all layers.
     */
    void Print(const std::string &key = "") const;

public:
    /**
     * Check if a layer exists.
     * @param[in] key the name of the layer.
     * @return true if a layer named \'layer\' exists.
     */
    bool IsExist(const std::string &key) const;

    /**
     * Add an empty layer. All values are set as NAN.
     * @param[in] key the name of the new layer.
     * @return false if a layer named \'layer\' already exists.
     */
    bool AddLayer(const std::string &key);

    /**
     * Add a layer with data.
     * @param[in] key the name of the new layer.
     * @param[in] data initial data of the new layer.
     * @return false if a layer named \'layer\' already exists.
     */
    bool AddLayer(const std::string &key, Layer &&data);

    /**
     * Wrap index to be bounded in the valid range, (0, row-1) for x and (0, col-1) for y direction.
     * @param[in/out] index Index to be rounded.
     */
    void WrapIndex(Index &index) const;

    /**
     * Unwrap index to be in range [centerIndex(0)-row/2, centerIndex(0)+row/2) for x and [centerIndex(1)-col/2, centerIndex(1)+col/2) for y direction.
     * @param[in/out] index Index to be rounded.
     */
    void UnwrapIndex(Index &index) const;

    /**
     * Bound input position within current gridmap boundary.
     * @param[in/out] position Input position.
     */
    void BoundPosition(Position &position) const;

    /**
     * Check if the given index is in the valid gridmap region.
     * @param[in] index index to check if it is in the valid region.
     * @param[in] wrapped whether the given index is wrapped or not.
     * @return true if the index is in the valid region.
     */
    bool IsValid(const Index &index, bool wrapped = true) const;

    /**
     * Check if the given position is in the valid gridmap region.
     * @param[in] position position to check if it is in the valid region.
     * @return true if the position is in the valid region.
     */
    bool IsValid(const Position &position) const;

private:
    m_type _resolution;                             //<! cell resolution in meter.
    Size _size;                                     //<! map width and height in meter.
    Dimension _dim;                                 //<! cell dimension.
    Position _centerPosition;                       //<! center position wrt map frame in meter.
    Position _topRightPosition;                     //<! top-right position wrt map frame in meter.
    Position _bottomLeftPosition;                   //<! bottom-left position wrt map frame in meter.
    Index _centerIndex;                             //<! center index.
    std::unordered_map<std::string, Layer> _layers; //<! cell data layers.
    Position _r;                                    //<! map displacement wrt global frame
};

} // namespace dtControl

#include "gridMap.ipp"

#endif // DTCONTROL_GRIDMAP_H_
