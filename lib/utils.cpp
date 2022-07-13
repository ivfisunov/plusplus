#include <iostream>
#include "utils.h"

namespace utils {
// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char sep)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(sep);
    while (stop != std::string::npos) {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(sep, start);
    }
    r.push_back(str.substr(start));
    return r;
}

void print(const IpPool &pool)
{
    for (const auto &ip : pool) {
        std::cout << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3] << std::endl;
    }
}

void sortIpPool(IpPool &pool)
{
    auto comp = [](const std::vector<std::string> &a, const std::vector<std::string> &b) -> bool {
        for (int i = 0; i < 4; ++i) {
            if (a.at(i) == b.at(i))
                continue;
            return std::stoi(a.at(i)) > std::stoi(b.at(i));
        }
        return false;
    };

    std::sort(pool.begin(), pool.end(), comp);
}

IpPool filter(const IpPool &pool, const u_int32_t byte)
{
    IpPool newPool{};
    for (const auto &ip : pool) {
        if (std::stoi(ip.at(0)) == byte) {
            newPool.emplace_back(ip);
        }
    }
    return newPool;
}

IpPool filter(const IpPool &pool, const u_int32_t firstByte, u_int32_t secondByte)
{
    IpPool newPool{};
    for (const auto &ip : pool) {
        if (std::stoi(ip.at(0)) == firstByte && std::stoi(ip.at(1)) == secondByte) {
            newPool.emplace_back(ip);
        }
    }
    return newPool;
}

IpPool filter_any(const IpPool &pool, const u_int32_t byte)
{
    IpPool newPool{};
    for (const auto &ip : pool) {
        for (auto it = ip.begin(); it != ip.end(); ++it) {
            if (std::stoi(*it) == byte) {
                newPool.emplace_back(ip);
                break;
            }
        }
    }
    return newPool;
}

}  // namespace utils