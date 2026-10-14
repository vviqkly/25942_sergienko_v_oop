#include <gtest/gtest.h>
#include "t_funcs.h"

// simple
TEST(SimpleAdd, IntPositive)
{
    EXPECT_EQ((simple::add<int>(2, 3)), 5);
}

TEST(SimpleAdd, IntNegative)
{
    EXPECT_EQ((simple::add<int>(-2, -3)), -5);
}

TEST(SimpleAdd, IntZero)
{
    ASSERT_EQ((simple::add<int>(0, 0)), 0);
}

TEST(SimpleAdd, DoublePositive)
{
    EXPECT_DOUBLE_EQ((simple::add<double>(2.5, 3.5)), 6.0);
}

TEST(SimpleAdd, DoubleNear)
{
    EXPECT_NEAR((simple::add<double>(0.1, 0.2)), 0.3, 1e-9);
}

// modified
TEST(ModifiedAdd, IntAtLeastSum) 
{
    for (int i = 0; i < 20; ++i)
        EXPECT_GE((modified::add<int>(2, 3)), 5);
}

TEST(ModifiedAdd, IntWithinRange)
{
    for (int i = 0; i < 20; ++i)
        EXPECT_LE((modified::add<int>(2, 3)), 105);
}

TEST(ModifiedAdd, DoubleAtLeastSum)
{
    for (int i = 0; i < 20; ++i)
        EXPECT_GE((modified::add<double>(2.5, 3.5)), 6.0);
}

// wrong
TEST(SimpleAdd, FailExpect)
{
    EXPECT_EQ((simple::add<int>(2, 3)), 999);
    EXPECT_EQ((simple::add<int>(2, 3)), 5);
}

TEST(SimpleAdd, FailAssert)
{
    ASSERT_EQ((simple::add<int>(2, 3)), 999);
    EXPECT_EQ((simple::add<int>(2, 3)), 5);
}