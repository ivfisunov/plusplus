#include <iostream>
#include <map>
#include <vector>

#include "alloc.h"

int fact(int n)
{
    return (n == 0) || (n == 1) ? 1 : n * fact(n - 1);
}

template<typename T>
void print(const T& m)
{
    for (const auto& [k, v] : m) {
        std::cout << k << " " << v << std::endl;
    }
}

int main(int, char**)
{
    std::map<int, int> generalAllocMap{};
    for (int i = 0; i < 10; ++i) {
        generalAllocMap[i] = fact(i);
    }
    print(generalAllocMap);

    std::map<int, int, std::less<int>, alloc::CustomAllocator<std::pair<const int, int>>>
        customAllocMap{};
    for (int i = 0; i < 10; ++i) {
        customAllocMap[i] = fact(i);
    }
    print(customAllocMap);

    return 0;
}
