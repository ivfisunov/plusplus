#pragma once

#include <vector>
#include <string>
#include <algorithm>

using IpPool = std::vector<std::vector<std::string>>;

namespace utils {

std::vector<std::string> split(const std::string &str, char sep);

void print(const IpPool &pool);

void sortIpPool(IpPool &pool);

IpPool filter(const IpPool &pool, const u_int32_t byte);

IpPool filter(const IpPool &pool, const u_int32_t firstByte, u_int32_t secondByte);

IpPool filter_any(const IpPool &pool, const u_int32_t byte);

}  // namespace utils