/*!
 \file      gridMapCircleIterator.h
 \brief     Iterator to iterate Gridmap within the user specified circle shape sub-region.
 \author    Sangyup (Sean) Yi, sean.yi@hyundai.com
 \date      2024. 06. 20
 \version   1.0.0
 \copyright RoboticsLab ART All rights reserved.
*/

#ifndef DTCONTROL_GRIDMAPCIRCLEITERATOR_H_
#define DTCONTROL_GRIDMAPCIRCLEITERATOR_H_

#include "gridMap.h"

namespace dtControl
{

template <typename GridMapType>
class GridMapCircleIterator
{
public:
    typedef typename GridMapType::Index IndexType;

    /**
     * Constructor
     * @param gridmap
     * @param center Center position.
     * @param radius Radius in meter.
    */
    GridMapCircleIterator(GridMapType &gridmap, const typename GridMapType::Position center, const typename GridMapType::ValueType radius)
        : _gridmap(gridmap), _center(center), _radius(radius)
    {
        _gridmap.GetIndexFromPosition(_center, _center_index);
        _gridmap.UnwrapIndex(_center_index);
        _start_index = _center_index - (int)(_radius / gridmap.resolution()) - 1;
        _end_index = _center_index + (int)(_radius / gridmap.resolution()) + 1;
        _size = (_end_index - _start_index) + 1;
        assert(_size(0) > 0 && _size(1) > 0);
        _size_lin = _size(0) * _size(1);
        _index_lin = 0;
        _index = _start_index;
        _gridmap.WrapIndex(_index);

        // search the first valid index which is in the given circle
        while (!IsEnd())
        {
            if (_gridmap.IsValid(_index))
            {
                typename GridMapType::Position cell_center;
                _gridmap.GetPositionFromIndex(_index, cell_center);
                typename GridMapType::ValueType _cell_distance = sqrt((center - cell_center).dot(center - cell_center));
                if (_cell_distance <= _radius)
                    break;
            }
            ++(*this);
        }
    }

    // copy constructor
    GridMapCircleIterator(const GridMapCircleIterator &ref)
        : _gridmap(ref._gridmap)
    {
        this->_size = ref._size;
        this->_index = ref._index;
        this->_start_index = ref._start_index;
        this->_end_index = ref._end_index;
        this->_center = ref._center;
        this->_center_index = ref._center_index;
        this->_radius = ref._radius;
        this->_size_lin = ref._size_lin;
        this->_index_lin = ref._index_lin;
    }

    // destructor
    ~GridMapCircleIterator() {}

    typename GridMapType::Index &operator*()
    {
        return _index;
    }
    GridMapCircleIterator &operator++()
    {
        if (IsEnd())
            return *this;

        _index_lin++;
        _index(0) = _index_lin / _size(1);
        _index(1) = _index_lin % _size(1);
        _index += _start_index;
        _gridmap.WrapIndex(_index);

        if (_gridmap.IsValid(_index))
        {
            typename GridMapType::Position cell_center;
            _gridmap.GetPositionFromIndex(_index, cell_center);
            typename GridMapType::ValueType _cell_distance = sqrt((_center - cell_center).dot(_center - cell_center));
            if (_cell_distance <= _radius)
                return *this;
        }

        return ++(*this);
    }
    GridMapCircleIterator operator++(int)
    {
        GridMapCircleIterator tmp(*this);
        operator++();
        return tmp;
    }
    bool operator==(const GridMapCircleIterator &ref)
    {
        return (ref._index_lin == this->_index_lin);
    }
    bool operator!=(const GridMapCircleIterator &ref)
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

    typename GridMapType::Position _center;
    typename GridMapType::Index _center_index;
    typename GridMapType::ValueType _radius;
    uint16_t _size_lin;
    uint16_t _index_lin;
};

} // namespace dtControl

#endif // DTCONTROL_GRIDMAPCIRCLEITERATOR_H_