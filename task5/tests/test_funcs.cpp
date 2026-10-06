#include <gtest/gtest.h>
#include "funcs.h"

// simple::add
TEST(SimpleAdd, Positive) 
{
    EXPECT_EQ(simple::add(2, 3), 5);
}

TEST(SimpleAdd, Negative) 
{
    EXPECT_EQ(simple::add(-2, -3), -5);
}

TEST(SimpleAdd, Zero) 
{
    ASSERT_EQ(simple::add(0, 0), 0);
}

// modified::add
TEST(ModifiedAdd, AtLeastSum) 
{
    for (int i = 0; i < 20; ++i)
        EXPECT_GE(modified::add(2, 3), 5);
}

TEST(ModifiedAdd, WithinRange) 
{
    for (int i = 0; i < 20; ++i)
        EXPECT_LE(modified::add(2, 3), 105);
}

// wrong
TEST(SimpleAdd, FailExpect) 
{
    EXPECT_EQ(simple::add(2, 3), 999);
    EXPECT_EQ(simple::add(2, 3), 5);
}

TEST(SimpleAdd, FailAssert) {
    ASSERT_EQ(simple::add(2, 3), 999);
    EXPECT_EQ(simple::add(2, 3), 5);
}