#include <gtest/gtest.h>

#include "print_ip.h"

namespace {

TEST(TestPrintIp, TestPrintIp)
{
    EXPECT_EQ(print_ip::makeIp(int8_t(-1)), std::string{"255"});
    EXPECT_EQ(print_ip::makeIp(int16_t(0)), std::string{"0.0"});
    EXPECT_EQ(print_ip::makeIp(int32_t(2130706433)), std::string{"127.0.0.1"});
    EXPECT_EQ(print_ip::makeIp(int64_t(8875824491850138409)), std::string{"123.45.67.89.101.112.131.41"});
    EXPECT_EQ(print_ip::makeIp(std::string{"Hello there!"}), std::string{"Hello there!"});
    EXPECT_EQ(print_ip::makeIp(std::vector<int>{100, 200, 300, 400}), std::string{"100.200.300.400"});
    EXPECT_EQ(print_ip::makeIp(std::list<short>{400,300, 200, 100}), std::string{"400.300.200.100"});
}

}  // namespace
