#pragma once

#include <cstdint>
#include <map>
#include <vector>

template<typename ValueType, uint32_t N>
class Iter
{
  private:
    using IterType = typename std::map<std::vector<uint32_t>, ValueType>::iterator;

  public:
    Iter(IterType it)
      : iter(it)
    {
    }

    ~Iter() = default;

    bool operator==(const Iter& rhs) const
    {
        return iter == rhs.iter;
    }

    bool operator!=(const Iter& rhs) const
    {
        return iter != rhs.iter;
    }

    auto operator++()
    {
        iter++;
        return *this;
    }

    template<std::size_t... Is>
    auto create_tuple_impl(
        std::index_sequence<Is...>, const std::vector<uint32_t>& keys, ValueType value)
    {
        return std::make_tuple(keys[Is]..., value);
    }

    template<std::size_t Size>
    auto create_tuple(const std::vector<uint32_t>& keys, ValueType value)
    {
        return create_tuple_impl(std::make_index_sequence<Size>{}, keys, value);
    }

    auto operator*()
    {
        const auto& [k, v] = *iter;
        return create_tuple<N>(k, v);
    }

  private:
    IterType iter;
};
