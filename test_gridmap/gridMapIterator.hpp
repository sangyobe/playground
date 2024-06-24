/*!
 \file      gridMapIterator.h
 \brief     Iterator to iterate Gridmap indexes.
 \author    Sangyup (Sean) Yi, sean.yi@hyundai.com
 \date      2024. 06. 20
 \version   1.0.0
 \copyright RoboticsLab ART All rights reserved.
*/

#ifndef DTCONTROL_GRIDMAPITERATOR_H_
#define DTCONTROL_GRIDMAPITERATOR_H_

#include "gridMap.h"

namespace dtControl
{

template <typename GridMapType>
class GridMapIterator
{
public:
    GridMapIterator(GridMapType &gridmap) : _gridmap(gridmap)
    {
        _size(0) = gridmap.col();
        _size(1) = gridmap.row();
        _size_lin = _size(0) * _size(1);
        _index.SetZero();
        _index_lin = 0;
    }
    ~GridMapIterator() {}

    typename GridMapType::Index &operator*()
    {
        return _index;
    }
    GridMapIterator &operator++()
    {
        _index_lin++;
        _index(0) = _index_lin / _size(1);
        _index(1) = _index_lin % _size(1);
        return *this;
    }
    bool operator==(const GridMapIterator &ref)
    {
        return (ref._index_lin == this->_index_lin);
    }
    bool operator!=(const GridMapIterator &ref)
    {
        return (ref._index_lin != this->_index_lin);
    }
    bool IsBegin() const
    {
        return (_index_lin == 0);
    }
    bool IsEnd() const
    {
        return (_index_lin == _size_lin);
    }

private:
    GridMapType &_gridmap;
    typename GridMapType::Index _size;
    typename GridMapType::Index _index;
    uint16_t _size_lin;
    uint16_t _index_lin;
};

} // namespace dtControl

#endif // DTCONTROL_GRIDMAPITERATOR_H_