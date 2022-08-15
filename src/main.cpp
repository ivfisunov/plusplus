#include "print_ip.h"

using namespace print_ip;

int main(int, char**)
{
    print(makeIp(int8_t(-1)));
    print(makeIp(int16_t(0)));
    print(makeIp(int32_t(2130706433)));
    print(makeIp(int64_t(8875824491850138409)));
    print(makeIp(std::string{"Hello, World!"}));
    print(makeIp(std::vector<int>{100, 200, 300, 400}));
    print(makeIp(std::list<short>{400,300, 200, 100}));

    return 0;
}
