#include <iostream>
#include <gtest/gtest.h>
#include <limits.h>

TEST(LongLimitTest, Maximum) {
    EXPECT_EQ(LONG_MAX, 2147483647);
}