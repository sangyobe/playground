/*!
 \file      gridMapBoxIterator.h
 \brief     Iterator to iterate Gridmap within the user specified shape sub-region.
 \author    Sangyup (Sean) Yi, sean.yi@hyundai.com
 \date      2024. 06. 20
 \version   1.0.0
 \copyright RoboticsLab ART All rights reserved.
*/

#ifndef DTCONTROL_GRIDMAPBOXITERATOR_H_
#define DTCONTROL_GRIDMAPBOXITERATOR_H_

#include "gridMap.h"

namespace dtControl
{

template <typename GridMapType>
class GridMapBoxIterator
{
public:
    typedef typename GridMapType::Index IndexType;

    /**
     * Constructor
     * @param gridmap
     * @param start Wrapped start(left-bottom) index of the box sub-region.
     * @param end Wrapped end(right-top) index of the box sub-region.
    */
    GridMapBoxIterator(GridMapType &gridmap, const typename GridMapType::Index start, const typename GridMapType::Index end)
        : _gridmap(gridmap), _start_index(start), _end_index(end)
    {
        _gridmap.UnwrapIndex(_start_index);
        _gridmap.UnwrapIndex(_end_index);
        _size = (_end_index - _start_index) + 1;
        assert(_size(0) > 0 && _size(1) > 0);
        _size_lin = _size(0) * _size(1);

        _index_lin = 0;
        _index = _start_index;
        _gridmap.WrapIndex(_index);
    }
    ~GridMapBoxIterator() {}

    /**
     * Get wrapped index.
     * @return Wrapped index.
     */
    typename GridMapType::Index &operator*()
    {
        return _index;
    }

    GridMapBoxIterator &operator++()
    {
        _index_lin++;
        _index(0) = _index_lin / _size(1);
        _index(1) = _index_lin % _size(1);
        _index += _start_index;
        _gridmap.WrapIndex(_index);
        return *this;
    }

    bool operator==(const GridMapBoxIterator &ref)
    {
        return (ref._index_lin == this->_index_lin);
    }

    bool operator!=(const GridMapBoxIterator &ref)
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
    typename GridMapType::Index _start_index;
    typename GridMapType::Index _end_index;
    uint16_t _size_lin;
    uint16_t _index_lin;
};

} // namespace dtControl

#endif // DTCONTROL_GRIDMAPBOXITERATOR_H_