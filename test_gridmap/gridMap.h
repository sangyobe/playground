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
#include <dtMath/dtMath.h>
#include <stdexcept>
#include <string>
#include <unordered_map>

namespace dtControl
{

template <uint16_t m_row, uint16_t m_col, typename m_type>
class GridMap
{
public:
    GridMap();
    ~GridMap();
    const uint16_t col() const { return m_col; }
    const uint16_t row() const { return m_row; }

    typedef dtMath::dtVector<DOF2, m_type> Position;
    typedef dtMath::dtVector<DOF2, int> Index;
    typedef dtMath::dtMatrix<m_row, m_col, m_type> Layer;

public:
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
     * Get cell index from position.
     * @param[in] position the position in the map frame.
     * @param[out] index the cell index.
     * @return true if position is in the grid map boundary and succeed to get coresponding cell index.
     */
    bool GetIndexFromPosition(const Position position, Index &index) const;

    /**
     * Get cell center position from index.
     * @param[in] index the cell index.
     * @param[out] position the center position of the cell in the map frame.
     * @return true if succeed to get coresponding position in the map frame. false if index is out of grid map range.
     */
    bool GetPositionFromIndex(const Index index, Position &position) const;

    /**
     * Set center position.
     * New center position and cell index are caclulated.
     * The new center position is set as the calculated center of the center cell.
     * @param[in] position new center position to set.
     * @return true if new center position is set.
     */
    bool SetCenterPosition(const Position position);

    /**
     * Get current center position.
     * @param[out] position center position.
     */
    void GetCenterPosition(Position &position) const;

    /**
     * Get current center cell index.
     * @param[out] index center index.
     */
    void GetCenterIndex(Index &index) const;

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

private:
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

private:
    m_type _resolution;                             //<! cell resolution in meter.
    Position _centerPosition;                       //<! center position in meter.
    Index _centerIndex;                             //<! center index.
    m_type _width;                                  //<! map width in x-direction in meter.
    m_type _height;                                 //<! map height in y-direction in meter.
    std::unordered_map<std::string, Layer> _layers; //<! cell data layers.
};

} // namespace dtControl

#include "gridMap.ipp"

#endif // DTCONTROL_GRIDMAP_H_
