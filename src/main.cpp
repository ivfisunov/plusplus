#include <iostream>
#include <vector>
#include <algorithm>

#include "utils.h"


int main(int, char **)
{
    IpPool ipPool{};

    for (std::string line; std::getline(std::cin, line);) {
        std::vector<std::string> ip = utils::split(line, '\t');
        ipPool.push_back(utils::split(ip.at(0), '.'));
    }

    utils::sortIpPool(ipPool);
    utils::print(ipPool);

    IpPool filteredPool1 = utils::filter(ipPool, 1);
    utils::print(filteredPool1);

    IpPool filteredPool2 = utils::filter(ipPool, 46, 70);
    utils::print(filteredPool2);

    IpPool filteredPoolAny = utils::filter_any(ipPool, 46);
    utils::print(filteredPoolAny);


    return 0;
}
