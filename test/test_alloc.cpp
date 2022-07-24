#include <gtest/gtest.h>
#include <cstdlib>

#include "alloc.h"

namespace {

class AllocTest : public ::testing::Test
{
  protected:
    alloc::CustomAllocator<int, 10> m_customAllocator{};
};


TEST_F(AllocTest, ThrowBadLengthException)
{
    EXPECT_THROW(m_customAllocator.allocate(15), std::bad_array_new_length);
}

TEST_F(AllocTest, ThrowBadAllocException)
{
    for (int i = 0; i < 10; ++i)
        m_customAllocator.allocate(1);

    EXPECT_THROW(m_customAllocator.allocate(1), std::bad_alloc);
}

TEST_F(AllocTest, UseWithVector)
{
    std::vector<int, alloc::CustomAllocator<int, 5>> v{};
    v.reserve(5);
    for(int i = 0; i < 5; ++i)
        v.push_back(i);
    
    EXPECT_EQ(v.size(), 5);

    EXPECT_THROW(v.push_back(666), std::bad_alloc);
}

}  // namespace
