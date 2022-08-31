#pragma once

#include <cstdint>
#include <map>
#include <vector>
#include <cassert>
#include <stdexcept>

#include "matrix_iterator.h"

template<typename ValueType, ValueType defaultValue, uint32_t N = 2>
class Matrix
{
  public:
    Matrix()
    {
        assert((N > 1) && "Matrix should be 2d minimum");
        m_defaultValue = defaultValue;
        m_coords_tmp.reserve(N);
    }

    uint32_t size()
    {
        return m_size;
    }

    auto& operator=(ValueType val)
    {
        if (m_coords_tmp.size() != 0) {
            throw std::range_error("Matrix range error");
        }

        if (val != m_defaultValue) {
            if (m_matrix.find(m_coords_final) == m_matrix.end()) {
                m_size++;
            }
            m_matrix[m_coords_final] = val;
        } else {
            if (m_matrix.find(m_coords_final) != m_matrix.end()) {
                m_size--;
                m_matrix.erase(m_coords_final);
            }
        }
        return *this;
    }

    auto& operator[](const uint32_t& n)
    {
        m_coords_tmp.push_back(n);
        m_dimentionalCounter++;
        if (m_dimentionalCounter == N) {
            if (m_matrix.find(m_coords_tmp) == m_matrix.end()) {
                m_value = defaultValue;
            } else {
                m_value = m_matrix[m_coords_tmp];
            }
            m_dimentionalCounter = 0;
            m_coords_final = m_coords_tmp;
            m_coords_tmp.clear();
        }
        return *this;
    }

    operator auto()
    {
        return m_value;
    }

    auto begin()
    {
        return Iter<ValueType, N>(m_matrix.begin());
    }

    auto end()
    {
        return Iter<ValueType, N>(m_matrix.end());
    }

  private:
    std::map<std::vector<uint32_t>, ValueType> m_matrix;
    std::vector<uint32_t> m_coords_tmp;
    std::vector<uint32_t> m_coords_final;

    uint32_t m_size{0};
    ValueType m_defaultValue;
    u_int32_t m_dimentionalCounter{0};
    ValueType m_value{};
};


/////////////////////////////////////
// Build template map of maps
//
// template<typename ValueType, uint32_t Size>
// struct MapBuilder
// {
//     typedef std::map<uint32_t, typename MapBuilder<ValueType, Size - 1>::type> type;
// };
// template<typename ValueType>
// struct MapBuilder<ValueType, 1>
// {
//     typedef std::map<uint32_t, ValueType> type;
// };
// template<typename ValueType, uint32_t Size>
// using MatrixType = typename MapBuilder<ValueType, Size>::type;
