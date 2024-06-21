// #include "algorithm/robotParam.h"

namespace dtControl
{

template <uint16_t m_col, uint16_t m_row, typename m_type>
GridMap<m_col, m_row, m_type>::GridMap()
{
    // const dtCore::dtConf &conf = RobotParam::Get().conf();
    this->_resolution = 0.05; //conf["gridmap"]["resolution"].toDouble();
    this->_width = m_col * _resolution;
    this->_height = m_row * _resolution;
    this->_centerIndex.SetZero();
    this->_centerPosition.SetFill(0.5*this->_resolution);
    this->_topRightPosition(0) = ((m_col + 1) >> 1) * this->_resolution;
    this->_topRightPosition(1) = ((m_row + 1) >> 1) * this->_resolution;
    this->_bottomLeftPosition(0) = -((m_col) >> 1) * this->_resolution;
    this->_bottomLeftPosition(1) = -((m_row) >> 1) * this->_resolution;

    AddLayer("height_map");
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
GridMap<m_col, m_row, m_type>::~GridMap()
{
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
m_type GridMap<m_col, m_row, m_type>::GetWidth() const
{
    // return (m_col * _resolution);
    return this->_width;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
m_type GridMap<m_col, m_row, m_type>::GetHeight() const
{
    // return (m_row * _resolution);
    return this->_height;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
bool GridMap<m_col, m_row, m_type>::GetIndexFromPosition(const Position position, Index &index) const
{
    if (!IsValid(position))
        return false;

    // convert position in map frame to cell index
    index(0) = (position(0) >= 0 ? ((int)(position(0) / this->_resolution) % m_col) : ((int)(position(0) / this->_resolution) % m_col + m_col - 1));
    index(1) = (position(1) >= 0 ? ((int)(position(1) / this->_resolution) % m_row) : ((int)(position(1) / this->_resolution) % m_row + m_row - 1));
    return true;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
bool GridMap<m_col, m_row, m_type>::GetPositionFromIndex(const Index index, Position &position) const
{
    // wrapped index인지 체크한다.
    // assert(index(0) >= 0 && index(0) < m_col);
    // assert(index(1) >= 0 && index(1) < m_row);

    // 입력된 index를 유효한 unwrapped index로 바꾸기 위해 1회 wrap & unwrap 해준다.
    Index cellIndex;
    cellIndex(0) = index(0);
    cellIndex(1) = index(1);
    WrapIndex(cellIndex);
    UnwrapIndex(cellIndex);

    position(0) = this->_centerPosition(0) + (cellIndex(0) - this->_centerIndex(0)) * this->_resolution;
    position(1) = this->_centerPosition(1) + (cellIndex(1) - this->_centerIndex(1)) * this->_resolution;

    return true;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
bool GridMap<m_col, m_row, m_type>::SetCenterPosition(const Position position)
{
    Index centerIndex;
    if (!GetIndexFromPosition(position, centerIndex))
    {
        printf("GridMap::SetCenterPosition(): position is not valid.");
        return false;
    }

    if (this->_centerIndex != centerIndex)
    {
        // if center index moved,
        // invalidate cells which are out of local map range,
        // and update the center index
        Index begin, end;
        if (this->_centerPosition(0) < position(0))
        {
            begin(0) = this->_centerIndex(0) - (m_col >> 1);
            end(0) = centerIndex(0) - (m_col >> 1);
        }
        else
        {
            begin(0) = centerIndex(0) - (m_col >> 1);
            end(0) = this->_centerIndex(0) - (m_col >> 1);
        }

        if (this->_centerPosition(1) < position(1))
        {
            begin(1) = this->_centerIndex(1) - (m_row >> 1);
            end(1) = centerIndex(1) - (m_row >> 1);
        }
        else
        {
            begin(1) = centerIndex(1) - (m_row >> 1);
            end(1) = this->_centerIndex(1) - (m_row >> 1);
        }

        WrapIndex(begin);
        WrapIndex(end);

        SYSREAL zero_row[m_col], zero_col[m_row];
        std::fill(zero_row, zero_row + m_col, 0.0 /*NAN*/);
        std::fill(zero_col, zero_col + m_row, 0.0 /*NAN*/);
        int idx;
        for (auto &kv : _layers)
        {
            idx = begin(0);
            while (idx != end(0))
            {
                // gridmap 의 column은 dtMatrix의 row!
                kv.second.SetRowVec((uint16_t)idx, &zero_col[0], (size_t)(sizeof(zero_col[0]) * m_row));
                // kv.second.SetRowVec((uint16_t)idx, 0.0 /*NAN*/);
                idx++;
                if (idx >= m_col) idx = 0;
            }

            idx = begin(1);
            while (idx != end(1))
            {
                // gridmap 의 row은 dtMatrix의 column!
                kv.second.SetColVec((uint16_t)idx, &zero_row[0], (size_t)(sizeof(zero_row[0]) * m_col));
                // kv.second.SetColVec((uint16_t)idx, 0.0/*NAN*/);
                idx++;
                if (idx >= m_row) idx = 0;
            }
        }

        // 아래 코드 순서 주의!
        // center index를 업데이트하기 전에, 현재 center index기준으로 새로운 center index의 position을 구해야 함.
        Position centerPosition;
        GetPositionFromIndex(centerIndex, centerPosition); 
        this->_centerPosition = centerPosition;
        this->_centerIndex = centerIndex;
        this->_topRightPosition = centerPosition - 0.5 * this->_resolution;
        this->_topRightPosition(0) += ((m_col + 1) >> 1) * this->_resolution;
        this->_topRightPosition(1) += ((m_row + 1) >> 1) * this->_resolution;
        this->_bottomLeftPosition = centerPosition - 0.5 * this->_resolution;
        this->_bottomLeftPosition(0) -= ((m_col) >> 1) * this->_resolution;
        this->_bottomLeftPosition(1) -=((m_row) >> 1) * this->_resolution;
    }

    return true;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
void GridMap<m_col, m_row, m_type>::GetCenterPosition(Position &position) const
{
    position = this->_centerPosition;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
void GridMap<m_col, m_row, m_type>::GetCenterIndex(Index &index) const
{
    index = this->_centerIndex;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
void GridMap<m_col, m_row, m_type>::SetLayerData(const std::string &key, const Index index, m_type value)
{
    typename std::unordered_map<std::string, Layer>::iterator itr = _layers.find(key);
    if (itr != _layers.end())
    {
        (itr->second)(index(0), index(1)) = value;
    }
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
bool GridMap<m_col, m_row, m_type>::GetLayerData(const std::string &key, const Index index, m_type &value)
{
    assert(index(0) >= 0 && index(0) < m_col);
    assert(index(1) >= 0 && index(1) < m_row);

    if (index(0) < 0 || index(0) >= m_col) return false;
    if (index(1) < 0 || index(1) >= m_row) return false;

    typename std::unordered_map<std::string, Layer>::iterator itr = _layers.find(key);
    if (itr == _layers.end())
        return false;

    value = (itr->second)(index(0), index(1));
    return true;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
const typename GridMap<m_col, m_row, m_type>::Layer &GridMap<m_col, m_row, m_type>::GetLayer(const std::string &key) const
{
    typename std::unordered_map<std::string, Layer>::const_iterator itr = _layers.find(key);
    if (itr != _layers.end())
    {
        return itr->second;
    }
    else
    {
        throw std::out_of_range("GridMap::GetLayer(...) : No map layer of name '" + key + "' available.");
    }
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
typename GridMap<m_col, m_row, m_type>::Layer &GridMap<m_col, m_row, m_type>::GetLayer(const std::string &key)
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

template <uint16_t m_col, uint16_t m_row, typename m_type>
bool GridMap<m_col, m_row, m_type>::IsExist(const std::string &key) const
{
    return (_layers.find(key) != _layers.end());
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
bool GridMap<m_col, m_row, m_type>::AddLayer(const std::string &key)
{
    if (IsExist(key)) return false;

    Layer mat;
    mat.SetFill(0.0 /*NAN*/);
    _layers.insert(std::make_pair(key, mat));
    return true;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
bool GridMap<m_col, m_row, m_type>::AddLayer(const std::string &key, Layer &&data)
{
    if (IsExist(key)) return false;

    _layers.insert(std::make_pair(key, data));
    return true;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
void GridMap<m_col, m_row, m_type>::WrapIndex(Index &index) const
{
    index(0) = index(0) % m_col;
    index(1) = index(1) % m_row;
    if (index(0) < 0) index(0) += m_col;
    if (index(1) < 0) index(1) += m_row;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
void GridMap<m_col, m_row, m_type>::UnwrapIndex(Index &index) const
{
    assert(index(0) >= 0 && index(0) < m_col); // check if input index is wrapped index.
    assert(index(1) >= 0 && index(1) < m_row);

    if (index(0) < (this->_centerIndex(0) - (m_col >> 1))) index(0) += m_col;
    else if (index(0) >= (this->_centerIndex(0) + ((m_col + 1) >> 1))) index(0) -= m_col; // m_col 이 홀수인 경우, index(0) 최대값은 centerIndex + (m_col / 2)에 1을 더한 값임.

    if (index(1) < (this->_centerIndex(1) - (m_row >> 1))) index(1) += m_row;
    else if (index(1) >= (this->_centerIndex(1) + ((m_row + 1) >> 1))) index(1) -= m_row; // m_row 가 홀수인 경우, cellIndex(1) 최대값은 centerIndex + (m_row / 2)에 1을 더한 값임.
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
bool GridMap<m_col, m_row, m_type>::IsValid(const Position &position) const
{
    // check if position is in the local gridmap range
    if ((position(0) < this->_bottomLeftPosition(0)) || (position(0) >= this->_topRightPosition(0)))
        return false; // out of range
    if ((position(1) < this->_bottomLeftPosition(1)) || (position(1) >= this->_topRightPosition(1)))
        return false; // out of range

    return true;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
void GridMap<m_col, m_row, m_type>::Print(const std::string &key) const
{
    try
    {
        if (!key.empty())
        {
            // print layer data
            const Layer &layer = GetLayer(key);
            printf("[%s]:\n", key.c_str());
            // layer.Print();
            for (int irow = (_centerIndex(1) + (int)((m_row + 1) >> 1) - 1); irow >= (_centerIndex(1) - (int)(m_row >> 1)); irow--)
            {
                for (int icol = (_centerIndex(0) - (int)(m_col >> 1)); icol < (_centerIndex(0) + (int)((m_col + 1) >> 1)); icol++)
                {
                    Index index;
                    index(0) = icol;
                    index(1) = irow;
                    WrapIndex(index);
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