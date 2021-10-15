#include <string>
#include "gtest/gtest.h"
#include "LongArithmetic.h"

TEST(LongArithmetic, add) {
    LongArithmetic number1 = LongArithmetic("559876543");
    LongArithmetic number2 = LongArithmetic("4609876543");
    LongArithmetic number3 = LongArithmetic(3456788);
    LongArithmetic number4 = LongArithmetic(5690790);
    LongArithmetic sum = number1 + number2;
    LongArithmetic sum2 = number3 + number4;
    EXPECT_EQ(sum.getValue(), "5169753086");
    EXPECT_EQ(sum2.getValue(), "9147578");
}
TEST(LongArithmetic, subtract) {
    LongArithmetic number1 = LongArithmetic("75");
    LongArithmetic number2 = LongArithmetic("84");
    LongArithmetic number3 = LongArithmetic("32");
    LongArithmetic number4 = LongArithmetic(-50);
    LongArithmetic number5 = LongArithmetic(-100);
    LongArithmetic number6 = LongArithmetic(172);
    LongArithmetic number7 = LongArithmetic(73);
    LongArithmetic diff7 = LongArithmetic(55422424) - LongArithmetic(55422424);
    EXPECT_EQ((number1 - number2).getValue(), "-9");
    EXPECT_EQ( (number1 - number3).getValue(), "43");
    EXPECT_EQ( (number4 - number5).getValue(), "50");
    EXPECT_EQ( (number5 - number4).getValue(), "-50");
    EXPECT_EQ((number6 - number7).getValue(), "99");
    EXPECT_EQ(diff7.getValue(), "0");
}

TEST(LongArithmetic, multiply) {
    LongArithmetic number1 = LongArithmetic("7545678");
    LongArithmetic number2 = LongArithmetic("84345");
    LongArithmetic number3 = LongArithmetic("3");
    LongArithmetic number4 = LongArithmetic("-3");
    EXPECT_EQ((number1 * number2).getValue(), "636440210910");
    EXPECT_EQ( (number1 * number3).getValue(), "22637034");
    EXPECT_EQ( (number3 * number1).getValue(), "22637034");
    EXPECT_EQ( (number4 * number1).getValue(), "-22637034");
    EXPECT_EQ( (number4 * number4).getValue(), (number3 * number3).getValue());
}

TEST(LongArithmetic, equals) {
    LongArithmetic number1 = LongArithmetic("550987658");
    LongArithmetic number2 = LongArithmetic("5509876543");
    LongArithmetic number3 = LongArithmetic("550987658");
    EXPECT_EQ(number1 == number2, false);
    EXPECT_EQ(number1 == number3, true);
}
TEST(LongArithmetic, greater) {
    LongArithmetic number1 = LongArithmetic("550987658");
    LongArithmetic number2 = LongArithmetic("5509876543");
    LongArithmetic number3 = LongArithmetic("550987658");
    LongArithmetic number4 = LongArithmetic("550987658");
    LongArithmetic number5 = LongArithmetic(-45678990);
    EXPECT_EQ(number1 > number2, false);
    EXPECT_EQ(number1 > number3, false);
    EXPECT_EQ(number4 > number1, false);
    EXPECT_EQ(number5 > number4, false);
}
TEST(LongArithmetic, less) {
    LongArithmetic number1 = LongArithmetic("550987658");
    LongArithmetic number2 = LongArithmetic("5509876543");
    LongArithmetic number3 = LongArithmetic("550987658");
    LongArithmetic number4 = LongArithmetic("-87658");
    LongArithmetic number5 = LongArithmetic(-45678990);
    EXPECT_EQ(number1 < number2, true);
    EXPECT_EQ(number1 < number3, false);
    EXPECT_EQ(number4 < number1, true);
    EXPECT_EQ(number5 < number4, true);
}





