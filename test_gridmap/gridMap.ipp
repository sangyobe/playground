// #include "algorithm/robotParam.h"
namespace dtControl
{

template <uint16_t m_col, uint16_t m_row, typename m_type>
const m_type GridMap<m_col, m_row, m_type>::NAN_VAL = 0.0; // NAN;

template <uint16_t m_col, uint16_t m_row, typename m_type>
GridMap<m_col, m_row, m_type>::GridMap()
{
    // const dt::Utils::Conf &conf = RobotParam::Get().conf();
    this->_resolution = 0.05; //conf["gridmap"]["resolution"].toDouble();
    this->_size(0) = m_col * _resolution;
    this->_size(1) = m_row * _resolution;
    this->_dim(0) = m_col;
    this->_dim(1) = m_row;
    this->_centerIndex(0) = ((m_col) >> 1);
    this->_centerIndex(1) = ((m_row) >> 1);
    this->_centerPosition(0) = (m_type)this->_centerIndex(0) * this->_resolution + (0.5 * this->_resolution);
    this->_centerPosition(1) = (m_type)this->_centerIndex(1) * this->_resolution + (0.5 * this->_resolution);
    this->_topRightPosition(0) = (this->_centerIndex(0) * this->_resolution) + ((m_col + 1) >> 1) * this->_resolution;
    this->_topRightPosition(1) = (this->_centerIndex(1) * this->_resolution) + ((m_row + 1) >> 1) * this->_resolution;
    this->_bottomLeftPosition(0) = (this->_centerIndex(0) * this->_resolution) - ((m_col) >> 1) * this->_resolution;
    this->_bottomLeftPosition(1) = (this->_centerIndex(1) * this->_resolution) - ((m_row) >> 1) * this->_resolution;
    this->_r.SetZero();

    // add some default layers
    AddLayer("hmap");
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
GridMap<m_col, m_row, m_type>::GridMap(const std::vector<std::string> layerNames)
{
    // const dt::Utils::Conf &conf = RobotParam::Get().conf();
    this->_resolution = 0.05; //conf["gridmap"]["resolution"].toDouble();
    this->_size(0) = m_col * _resolution;
    this->_size(1) = m_row * _resolution;
    this->_dim(0) = m_col;
    this->_dim(1) = m_row;
    this->_centerIndex(0) = ((m_col) >> 1);
    this->_centerIndex(1) = ((m_row) >> 1);
    this->_centerPosition(0) = (m_type)this->_centerIndex(0) * this->_resolution + (0.5 * this->_resolution);
    this->_centerPosition(1) = (m_type)this->_centerIndex(1) * this->_resolution + (0.5 * this->_resolution);
    this->_topRightPosition(0) = (this->_centerIndex(0) * this->_resolution) + ((m_col + 1) >> 1) * this->_resolution;
    this->_topRightPosition(1) = (this->_centerIndex(1) * this->_resolution) + ((m_row + 1) >> 1) * this->_resolution;
    this->_bottomLeftPosition(0) = (this->_centerIndex(0) * this->_resolution) - ((m_col) >> 1) * this->_resolution;
    this->_bottomLeftPosition(1) = (this->_centerIndex(1) * this->_resolution) - ((m_row) >> 1) * this->_resolution;
    this->_r.SetZero();

    for (auto layer : layerNames)
        AddLayer(layer);
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
GridMap<m_col, m_row, m_type>::GridMap(const std::vector<std::string> layerNames, const Index centerIndex)
{
    // const dt::Utils::Conf &conf = RobotParam::Get().conf();
    this->_resolution = 0.05; //conf["gridmap"]["resolution"].toDouble();
    this->_size(0) = m_col * _resolution;
    this->_size(1) = m_row * _resolution;
    this->_dim(0) = m_col;
    this->_dim(1) = m_row;
    this->_centerIndex = centerIndex;
    this->_centerPosition(0) = (m_type)this->_centerIndex(0) * this->_resolution + (0.5 * this->_resolution);
    this->_centerPosition(1) = (m_type)this->_centerIndex(1) * this->_resolution + (0.5 * this->_resolution);
    this->_topRightPosition(0) = (this->_centerIndex(0) * this->_resolution) + ((m_col + 1) >> 1) * this->_resolution;
    this->_topRightPosition(1) = (this->_centerIndex(1) * this->_resolution) + ((m_row + 1) >> 1) * this->_resolution;
    this->_bottomLeftPosition(0) = (this->_centerIndex(0) * this->_resolution) - ((m_col) >> 1) * this->_resolution;
    this->_bottomLeftPosition(1) = (this->_centerIndex(1) * this->_resolution) - ((m_row) >> 1) * this->_resolution;
    this->_r.SetZero();

    for (auto layer : layerNames)
        AddLayer(layer);
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
GridMap<m_col, m_row, m_type>::~GridMap()
{
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
const typename GridMap<m_col, m_row, m_type>::Size &GridMap<m_col, m_row, m_type>::GetSize() const
{
    return _size;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
m_type GridMap<m_col, m_row, m_type>::GetWidth() const
{
    // return (m_col * _resolution);
    return this->_size(0);
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
m_type GridMap<m_col, m_row, m_type>::GetHeight() const
{
    // return (m_row * _resolution);
    return this->_size(1);
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
m_type GridMap<m_col, m_row, m_type>::GetLeft() const
{
    return this->_bottomLeftPosition(0);
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
m_type GridMap<m_col, m_row, m_type>::GetRight() const
{
    return this->_topRightPosition(0);
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
m_type GridMap<m_col, m_row, m_type>::GetBottom() const
{
    return this->_bottomLeftPosition(1);
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
m_type GridMap<m_col, m_row, m_type>::GetTop() const
{
    return this->_topRightPosition(1);
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
bool GridMap<m_col, m_row, m_type>::GetIndexFromPosition(const Position position, Index &index) const
{
    if (!IsValid(position))
        return false;

    // convert position to cell index
    Position lpos = position - _r;
    index(0) = (lpos(0) >= 0 ? ((int)(lpos(0) / this->_resolution) % m_col) : ((int)(lpos(0) / this->_resolution) % m_col + m_col - 1));
    index(1) = (lpos(1) >= 0 ? ((int)(lpos(1) / this->_resolution) % m_row) : ((int)(lpos(1) / this->_resolution) % m_row + m_row - 1));
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
    position += _r;

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
        if ((this->_centerPosition(0) + this->_r(0)) < position(0))
        {
            begin(0) = this->_centerIndex(0) - (m_col >> 1);
            end(0) = centerIndex(0) - (m_col >> 1);
        }
        else
        {
            begin(0) = centerIndex(0) - (m_col >> 1);
            end(0) = this->_centerIndex(0) - (m_col >> 1);
        }

        if ((this->_centerPosition(1) + this->_r(1)) < position(1))
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

        int idx;
        for (auto &kv : _layers)
        {
            idx = begin(0);
            while (idx != end(0))
            {
                // gridmap 의 column은 dtMatrix의 row!
                kv.second.SetFillRow((uint16_t)idx, NAN_VAL);
                idx++;
                if (idx >= m_col) idx = 0;
            }

            idx = begin(1);
            while (idx != end(1))
            {
                // gridmap 의 row은 dtMatrix의 column!
                kv.second.SetFillCol((uint16_t)idx, NAN_VAL);
                idx++;
                if (idx >= m_row) idx = 0;
            }
        }

        // 아래 코드 순서 주의!
        // center index를 업데이트하기 전에, 현재 center index기준으로 새로운 center index의 position을 구해야 함.
        Position centerPosition;
        GetPositionFromIndex(centerIndex, centerPosition);
        this->_centerPosition = centerPosition - this->_r;
        this->_centerIndex = centerIndex;
        this->_topRightPosition = this->_centerPosition - 0.5 * this->_resolution;
        this->_topRightPosition(0) += ((m_col + 1) >> 1) * this->_resolution;
        this->_topRightPosition(1) += ((m_row + 1) >> 1) * this->_resolution;
        this->_bottomLeftPosition = this->_centerPosition - 0.5 * this->_resolution;
        this->_bottomLeftPosition(0) -= ((m_col) >> 1) * this->_resolution;
        this->_bottomLeftPosition(1) -= ((m_row) >> 1) * this->_resolution;
    }

    return true;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
void GridMap<m_col, m_row, m_type>::MoveCenterPosition(const Position position)
{
    Position lpos = position - _r;

    this->_centerIndex(0) = (lpos(0) >= 0 ? ((int)(lpos(0) / this->_resolution) % m_col) : ((int)(lpos(0) / this->_resolution) % m_col + m_col - 1));
    this->_centerIndex(1) = (lpos(1) >= 0 ? ((int)(lpos(1) / this->_resolution) % m_row) : ((int)(lpos(1) / this->_resolution) % m_row + m_row - 1));

    this->_centerPosition(0) = (lpos(0) >= 0 ? ((m_type)((int)(lpos(0) / this->_resolution) + 0.5) * this->_resolution) : ((m_type)((int)(lpos(0) / this->_resolution) - 0.5) * this->_resolution));
    this->_centerPosition(1) = (lpos(1) >= 0 ? ((m_type)((int)(lpos(1) / this->_resolution) + 0.5) * this->_resolution) : ((m_type)((int)(lpos(1) / this->_resolution) - 0.5) * this->_resolution));

    this->_topRightPosition = this->_centerPosition - 0.5 * this->_resolution;
    this->_topRightPosition(0) += ((m_col + 1) >> 1) * this->_resolution;
    this->_topRightPosition(1) += ((m_row + 1) >> 1) * this->_resolution;
    this->_bottomLeftPosition = this->_centerPosition - 0.5 * this->_resolution;
    this->_bottomLeftPosition(0) -= ((m_col) >> 1) * this->_resolution;
    this->_bottomLeftPosition(1) -= ((m_row) >> 1) * this->_resolution;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
void GridMap<m_col, m_row, m_type>::GetCenterPosition(Position &position) const
{
    position = (this->_centerPosition + this->_r);
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
typename GridMap<m_col, m_row, m_type>::Position GridMap<m_col, m_row, m_type>::GetCenterPosition() const
{
    Position position = (this->_centerPosition + this->_r);
    return position;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
void GridMap<m_col, m_row, m_type>::GetCenterIndex(Index &index) const
{
    index = this->_centerIndex;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
typename GridMap<m_col, m_row, m_type>::Index GridMap<m_col, m_row, m_type>::GetCenterIndex() const
{
    Index index = this->_centerIndex;
    return index;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
void GridMap<m_col, m_row, m_type>::GetStartIndex(Index &index) const
{
    index = this->_centerIndex;
    index(0) -= (m_col >> 1);
    index(1) -= (m_row >> 1);
    WrapIndex(index);
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
typename GridMap<m_col, m_row, m_type>::Index GridMap<m_col, m_row, m_type>::GetStartIndex() const
{
    Index index = this->_centerIndex;
    index(0) -= (m_col >> 1);
    index(1) -= (m_row >> 1);
    WrapIndex(index);
    return index;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
void GridMap<m_col, m_row, m_type>::SetMapDisplacement(const Position &r)
{
    _r = r;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
typename GridMap<m_col, m_row, m_type>::Position GridMap<m_col, m_row, m_type>::GetMapDisplacement() const
{
    return _r;
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
void GridMap<m_col, m_row, m_type>::ResetLayerData(const std::string &key, const Index index)
{
    typename std::unordered_map<std::string, Layer>::iterator itr = _layers.find(key);
    if (itr != _layers.end())
    {
        (itr->second)(index(0), index(1)) = NAN_VAL;
    }
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
void GridMap<m_col, m_row, m_type>::ResetLayerData(const std::string &key)
{
    typename std::unordered_map<std::string, Layer>::iterator itr = _layers.find(key);
    if (itr != _layers.end())
    {
        (itr->second).SetFill(NAN_VAL);
    }
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
    mat.SetFill(NAN_VAL);
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
void GridMap<m_col, m_row, m_type>::BoundPosition(Position &position) const
{
    Position lpos = position - this->_r;

    if (lpos(0) < this->_bottomLeftPosition(0))
        lpos(0) = this->_bottomLeftPosition(0);
    else if (lpos(0) >= this->_topRightPosition(0))
        lpos(0) = this->_topRightPosition(0) - 1e-6;

    if (lpos(1) < this->_bottomLeftPosition(1))
        lpos(1) = this->_bottomLeftPosition(1);
    else if (lpos(1) >= this->_topRightPosition(1))
        lpos(1) = this->_topRightPosition(1) - 1e-6;

    position = lpos + this->_r;
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
bool GridMap<m_col, m_row, m_type>::IsValid(const Index &index, bool wrapped) const
{
    if (wrapped)
    {
        return (
            index(0) >= 0 &&
            index(0) < m_col &&
            index(1) >= 0 &&
            index(1) < m_row);
    }
    else
    {
        return (
            index(0) >= (this->_centerIndex(0) - (m_col >> 1)) &&
            index(0) < (this->_centerIndex(0) + ((m_col + 1) >> 1)) &&
            index(1) >= (this->_centerIndex(1) - (m_row >> 1)) &&
            index(1) < (this->_centerIndex(1) + ((m_row + 1) >> 1)));
    }
}

template <uint16_t m_col, uint16_t m_row, typename m_type>
bool GridMap<m_col, m_row, m_type>::IsValid(const Position &position) const
{
    Position lpos = position - this->_r;
    // check if position is in the local gridmap range
    if ((lpos(0) < this->_bottomLeftPosition(0)) || (lpos(0) >= this->_topRightPosition(0)))
        return false; // out of range
    if ((lpos(1) < this->_bottomLeftPosition(1)) || (lpos(1) >= this->_topRightPosition(1)))
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
                        printf("[[%7.3f]] ", (m_type)layer(index(0), index(1)));
                    }
                    else
                    {
                        printf("%7.3f ", (m_type)layer(index(0), index(1)));
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
            printf("map displacement: %.3f , %.3f (m)\n", _r(0), _r(1));
            printf("center index: %d , %d\n", _centerIndex(0), _centerIndex(1));
            printf("center position (wrt map frame): %.3f , %.3f (m)\n", _centerPosition(0), _centerPosition(1));

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