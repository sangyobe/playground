// #include "algorithm/robotParam.h"

namespace dtControl
{

template <uint16_t m_row, uint16_t m_col, typename m_type>
GridMap<m_row, m_col, m_type>::GridMap()
{
    // const dtCore::dtConf &conf = RobotParam::Get().conf();
    this->_resolution = 0.05; //conf["gridmap"]["resolution"].toDouble();
    this->_width = m_row * _resolution;
    this->_height = m_col * _resolution;

    AddLayer("height_map");
}

template <uint16_t m_row, uint16_t m_col, typename m_type>
GridMap<m_row, m_col, m_type>::~GridMap()
{
}

template <uint16_t m_row, uint16_t m_col, typename m_type>
m_type GridMap<m_row, m_col, m_type>::GetWidth()
{
    // return (m_row * _resolution);
    return this->_width;
}

template <uint16_t m_row, uint16_t m_col, typename m_type>
m_type GridMap<m_row, m_col, m_type>::GetHeight()
{
    // return (m_col * _resolution);
    return this->_height;
}

template <uint16_t m_row, uint16_t m_col, typename m_type>
bool GridMap<m_row, m_col, m_type>::GetIndexFromPosition(Position position, Index &index)
{
    // check if position is in the local gridmap range
    // #ifndef NDEBUG
    //     assert((position(0) < this->_centerPosition(0) + 0.5 * this->_width) && (position(0) >= this->_centerPosition(0) - 0.5 * this->_width) && "GridMap::GetIndexFromPosition(...), position.x are not in the local gridmap range.");
    //     assert((position(1) < this->_centerPosition(1) + 0.5 * this->_height) && (position(1) >= this->_centerPosition(1) - 0.5 * this->_height) && "GridMap::GetIndexFromPosition(...), position.y are not in the local gridmap range.");
    // #else
    if ((position(0) >= this->_centerPosition(0) + 0.5 * this->_width) || (position(0) < this->_centerPosition(0) - 0.5 * this->_width))
        return false;
    if ((position(1) >= this->_centerPosition(1) + 0.5 * this->_height) || (position(1) < this->_centerPosition(1) - 0.5 * this->_height))
        return false;
    // #endif

    // convert position in map frame to cell index
    index(0) = (position(0) >= 0 ? ((int)(position(0) / this->_resolution) % m_col) : ((int)(position(0) / this->_resolution) % m_col + m_col - 1));
    index(1) = (position(1) >= 0 ? ((int)(position(1) / this->_resolution) % m_row) : ((int)(position(1) / this->_resolution) % m_row + m_row - 1));
    return true;
}

template <uint16_t m_row, uint16_t m_col, typename m_type>
bool GridMap<m_row, m_col, m_type>::GetPositionFromIndex(Index index, Position &position)
{
    // assert(index(0) >= 0 && index(0) < m_row);
    // assert(index(1) >= 0 && index(1) < m_col);
    AdjustIndex(index);

    position(0) = this->_centerPosition(0) + index(0) * this->_resolution;
    position(1) = this->_centerPosition(1) + index(1) * this->_resolution;

    if (index(0) < (this->_centerIndex(0) - 0.5 * m_col)) position(0) += _width;
    if (index(0) >= (this->_centerIndex(0) + 0.5 * m_col)) position(0) -= _width;

    if (index(1) < (this->_centerIndex(1) - 0.5 * m_row)) position(1) += _height;
    if (index(1) >= (this->_centerIndex(1) + 0.5 * m_row)) position(1) -= _height;

    return true;
}

template <uint16_t m_row, uint16_t m_col, typename m_type>
bool GridMap<m_row, m_col, m_type>::SetCenterPosition(Position position)
{
    Index centerIndex;
    if (!GetIndexFromPosition(position, centerIndex))
        return false;

    if (this->_centerIndex != centerIndex)
    {
        // if center index moved,
        // invalidate cells out of local map range,
        // and update the center index
        Index from, to;
        if (this->_centerPosition(0) < position(0))
        {
            from(0) = this->_centerIndex(0) + (m_col >> 1);
            to(0) = centerIndex(0) + (m_col >> 1);
        }
        else
        {
            from(0) = centerIndex(0) + (m_col >> 1);
            to(0) = this->_centerIndex(0) + (m_col >> 1);
        }

        if (this->_centerPosition(1) < position(1))
        {
            from(1) = this->_centerIndex(1) + (m_row >> 1);
            to(1) = centerIndex(1) + (m_row >> 1);
        }
        else
        {
            from(1) = centerIndex(1) + (m_row >> 1);
            to(1) = this->_centerIndex(1) + (m_row >> 1);
        }

        AdjustIndex(from);
        AdjustIndex(to);

        SYSREAL zero_row[m_col], zero_col[m_row];
        std::fill(zero_row, zero_row + m_col, NAN);
        std::fill(zero_col, zero_col + m_row, NAN);
        int idx;
        for (auto &kv : _layers)
        {
            idx = from(0);
            while (idx != to(0))
            {
                kv.second.SetColVec((uint16_t)idx, &zero_col[0], (size_t)(sizeof(zero_col[0]) * m_row));
                // kv.second.SetColVec((uint16_t)idx, NAN);
                idx++;
                if (idx >= m_col) idx = 0;
            }

            idx = from(1);
            while (idx != to(1))
            {
                kv.second.SetRowVec((uint16_t)idx, &zero_row[0], (size_t)(sizeof(zero_row[0]) * m_col));
                // kv.second.SetRowVec((uint16_t)idx, NAN);
                idx++;
                if (idx >= m_row) idx = 0;
            }
        }

        this->_centerIndex = centerIndex;
    }

    this->_centerPosition = position;

    return true;
}

template <uint16_t m_row, uint16_t m_col, typename m_type>
void GridMap<m_row, m_col, m_type>::GetCenterPosition(Position &position)
{
    position = this->_centerPosition;
}

template <uint16_t m_row, uint16_t m_col, typename m_type>
void GridMap<m_row, m_col, m_type>::GetCenterIndex(Index &index)
{
    index = this->_centerIndex;
}

template <uint16_t m_row, uint16_t m_col, typename m_type>
void GridMap<m_row, m_col, m_type>::SetLayerData(const std::string &key, Index index, m_type value)
{
    typename std::unordered_map<std::string, Layer>::iterator itr = _layers.find(key);
    if (itr != _layers.end())
    {
        (itr->second)(index(0), index(1)) = value;
    }
}

template <uint16_t m_row, uint16_t m_col, typename m_type>
const typename GridMap<m_row, m_col, m_type>::Layer &GridMap<m_row, m_col, m_type>::GetLayer(const std::string &key) const
{
    typename std::unordered_map<std::string, Layer>::iterator itr = _layers.find(key);
    if (itr != _layers.end())
    {
        return itr->second;
    }
    else
    {
        throw std::out_of_range("GridMap::GetLayer(...) : No map layer of name '" + key + "' available.");
    }
}

template <uint16_t m_row, uint16_t m_col, typename m_type>
typename GridMap<m_row, m_col, m_type>::Layer &GridMap<m_row, m_col, m_type>::GetLayer(const std::string &key)
{
    typename std::unordered_map<std::string, Layer>::iterator itr = _layers.find(key);
    if (itr != _layers.end())
    {
        return itr->second;
    }
    else
    {
        throw std::out_of_range("GridMap::GetLayer(...) : No map layer of name '" + key + "' available.");
    }
}

template <uint16_t m_row, uint16_t m_col, typename m_type>
bool GridMap<m_row, m_col, m_type>::IsExist(const std::string &key)
{
    return (_layers.find(key) != _layers.end());
}

template <uint16_t m_row, uint16_t m_col, typename m_type>
bool GridMap<m_row, m_col, m_type>::AddLayer(const std::string &key)
{
    if (IsExist(key)) return false;

    Layer mat;
    mat.SetFill(NAN);
    _layers.insert(std::make_pair(key, mat));
    return true;
}

template <uint16_t m_row, uint16_t m_col, typename m_type>
bool GridMap<m_row, m_col, m_type>::AddLayer(const std::string &key, Layer &&data)
{
    if (IsExist(key)) return false;

    _layers.insert(std::make_pair(key, data));
    return true;
}

template <uint16_t m_row, uint16_t m_col, typename m_type>
void GridMap<m_row, m_col, m_type>::AdjustIndex(Index &index)
{
    index(0) = index(0) - (int)(index(0) / m_col) * m_col;
    index(1) = index(1) - (int)(index(1) / m_row) * m_row;
    if (index(0) < 0) index(0) += m_col;
    if (index(1) < 0) index(1) += m_row;
}

template <uint16_t m_row, uint16_t m_col, typename m_type>
void GridMap<m_row, m_col, m_type>::Print(const std::string &key)
{
    try
    {
        if (!key.empty())
        {
            // print layer data
            Layer &layer = GetLayer(key);
            printf("[%s]:\n", key.c_str());
            // layer.Print();
            uint16_t m_row_2 = (m_row >> 1);
            uint16_t m_col_2 = (m_col >> 1);
            for (int irow = (_centerIndex(1) + (int)(m_row_2)-1); irow >= (_centerIndex(1) - (int)(m_row_2)); irow--)
            {
                for (int icol = (_centerIndex(0) - (int)(m_col_2)); icol < (_centerIndex(0) + (int)(m_col_2)); icol++)
                {
                    Index index;
                    index(0) = icol;
                    index(1) = irow;
                    AdjustIndex(index);
                    if (_centerIndex == index)
                    {
                        printf("[[%7.7f]] ", (m_type)layer(index(1), index(0)));
                    }
                    else
                    {
                        printf("%7.7f ", (m_type)layer(index(1), index(0)));
                    }
                }
                printf("\n");
            }
            printf("\n");
        }
        else
        {
            printf("-------------------------------------------------\n");
            printf("resolution: %.3f (m)\n", _resolution);
            printf("dimention: %d x %d\n", m_row, m_col);
            printf("size: %.3f x %.3f (m)\n", GetWidth(), GetHeight());
            printf("center index: %d , %d\n", _centerIndex(0), _centerIndex(1));
            printf("center position: %.3f , %.3f (m)\n", _centerPosition(0), _centerPosition(1));

            for (const std::pair<std::string, Layer> &kv : _layers)
            {
                if (kv.first.empty()) continue;
                Print(kv.first);
                printf("\n");
            }
        }
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

} // namespace dtControl