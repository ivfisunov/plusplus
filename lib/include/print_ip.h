#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <type_traits>

namespace print_ip {

template<typename T>
struct is_string
{
    static constexpr bool value = false;
};
template<>
struct is_string<std::string>
{
    static constexpr bool value = true;
};

template<typename T>
struct is_vector : public std::false_type
{
    static constexpr bool value = false;
};
template<typename T>
struct is_vector<std::vector<T>> : public std::true_type
{
    static constexpr bool value = true;
};

template<typename T>
struct is_list : public std::false_type
{
    static constexpr bool value = false;
};
template<typename T>
struct is_list<std::list<T>> : public std::true_type
{
    static constexpr bool value = true;
};


template<
    typename Container,
    typename Fake = std::enable_if_t<is_vector<Container>::value || is_list<Container>::value>>
std::string makeIp(const Container& ip)
{
    std::string res{};
    for (auto it = ip.begin(); it != ip.end(); ++it) {
        res += std::to_string(*it);
        if (it != --ip.end())
            res += ".";
    }
    return res;
}

template<typename Int, typename Fake = std::enable_if_t<std::is_integral_v<Int>, void>>
std::string makeIp(Int ip)
{
    std::string res{};
    using UInt = std::make_unsigned_t<Int>;
    // typedef std::make_unsigned<Int>::type UInt;
    UInt uIp = static_cast<UInt>(ip);
    auto bytesNumber = sizeof(UInt);

    if (bytesNumber == 1) {
        int value = 0;
        for (std::size_t i = 0; i < 8; ++i)
            value += uIp & (1 << i);
        res += std::to_string(value);
        return res;
    }

    std::size_t cur_shift = 8 * (bytesNumber - 1);
    UInt mask = UInt(255) << cur_shift;
    for (; mask != 0; mask >>= 8, cur_shift -= 8) {
        res += std::to_string(((mask & uIp) >> cur_shift));
        if (cur_shift != 0)
            res += ".";
    }
    return res;
}

template<typename String, typename Fake = std::enable_if_t<is_string<String>::value>>
std::string makeIp(const String& ip, Fake* = nullptr)
{
    return ip;
}

void print(std::string str)
{
    std::cout << str << std::endl;
}

}  // namespace print_ip
