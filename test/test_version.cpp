#include <gtest/gtest.h>

#include "version.h"

namespace {

TEST(VersionTest, Version_should_be_positive)
{
    EXPECT_TRUE(version() > 0);
}

}  // namespace
