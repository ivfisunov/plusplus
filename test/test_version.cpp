#include <gtest/gtest.h>

#include "utils.h"

namespace {

IpPool ipPool{
    {"50", "10", "0", "5"},
    {"236", "1", "4", "200"},
    {"10", "110", "1", "1"},
    {"50", "10", "0", "0"},
    {"1", "1", "1", "1"},
    {"236", "1", "4", "209"},
    {"10", "145", "1", "155"},
    {"0", "0", "0", "0"},
    {"10", "110", "1", "55"},
    {"236", "1", "4", "200"},
    {"10", "110", "2", "1"},
};

IpPool ipPoolSorted{
    {"236", "1", "4", "209"},
    {"236", "1", "4", "200"},
    {"236", "1", "4", "200"},
    {"50", "10", "0", "5"},
    {"50", "10", "0", "0"},
    {"10", "145", "1", "155"},
    {"10", "110", "2", "1"},
    {"10", "110", "1", "55"},
    {"10", "110", "1", "1"},
    {"1", "1", "1", "1"},
    {"0", "0", "0", "0"},
};

IpPool filteredByFirstByte{
    {"50", "10", "0", "5"},
    {"50", "10", "0", "0"},
};

IpPool filteredByTwoBytes{
    {"10", "110", "2", "1"},
    {"10", "110", "1", "55"},
    {"10", "110", "1", "1"},
};

IpPool filteredByAnyByte{
    {"236", "1", "4", "209"},
    {"236", "1", "4", "200"},
    {"236", "1", "4", "200"},
    {"10", "145", "1", "155"},
    {"10", "110", "2", "1"},
    {"10", "110", "1", "55"},
    {"10", "110", "1", "1"},
    {"1", "1", "1", "1"},
};

TEST(SortTest, Ip_vector_should_be_sorted)
{
    utils::sortIpPool(ipPool);

    EXPECT_EQ(ipPool, ipPoolSorted);
}

TEST(Filter, Filter_by_first_byte)
{
    utils::sortIpPool(ipPool);
    IpPool pool = utils::filter(ipPool, 50);

    EXPECT_EQ(pool, filteredByFirstByte);
}

TEST(Filter, Filter_by_two_bytes)
{
    utils::sortIpPool(ipPool);
    IpPool pool = utils::filter(ipPool, 10, 110);

    EXPECT_EQ(pool, filteredByTwoBytes);
}

TEST(Filter, Filter_by_any_byte)
{
    utils::sortIpPool(ipPool);
    IpPool pool = utils::filter_any(ipPool, 1);

    EXPECT_EQ(pool, filteredByAnyByte);
}

TEST(Filter_negative, Filter_by_any_byte_should_return_empty)
{
    utils::sortIpPool(ipPool);
    IpPool pool = utils::filter_any(ipPool, 222);

    EXPECT_EQ(pool, IpPool{});
}

}  // namespace
