#include <string>
#include "gtest/gtest.h"
#include "LongArithmetic.h"

TEST(LongArithmetic, plusplus) {
    std::string str = "559876543";
    std::string str2 = "4609876543";
    LongArithmetic number1 = LongArithmetic(str);
    LongArithmetic number2 = LongArithmetic(str2);
    LongArithmetic sum = number1 + number2;
    EXPECT_EQ(sum.getValue(), "5169753086");
}
TEST(LongArithmetic, minusminus) {
    std::string str = "556768475096";
    std::string str2 = "4689850467";
    std::string str3 = "989765432";
    LongArithmetic number1 = LongArithmetic(str);
    LongArithmetic number2 = LongArithmetic(str2);
    LongArithmetic number3 = LongArithmetic(str3);
    LongArithmetic diff = number1 - number2;
    LongArithmetic diff2 = number1 - number3;
    EXPECT_EQ(diff.getValue(), "552078624629");
    EXPECT_EQ( diff2.getValue(), "555778709664");
}
TEST(LongArithmetic, equals) {
    std::string str = "550987658";
    std::string str2 = "5509876543";
    std::string str3 = "550987658";
    LongArithmetic number1 = LongArithmetic(str);
    LongArithmetic number2 = LongArithmetic(str2);
    LongArithmetic number3 = LongArithmetic(str3);
    EXPECT_EQ(number1 == number2, false);
    EXPECT_EQ(number1 == number3, true);
}
TEST(LongArithmetic, greater) {
    std::string str = "550987658";
    std::string str2 = "5509876543";
    std::string str3 = "550987658";
    std::string str4 = "-87658";
    std::string str5 = std::to_string(-45678990);
    LongArithmetic number1 = LongArithmetic(str);
    LongArithmetic number2 = LongArithmetic(str2);
    LongArithmetic number3 = LongArithmetic(str3);
    LongArithmetic number4 = LongArithmetic(str4);
    LongArithmetic number5 = LongArithmetic(str5);
    EXPECT_EQ(number1 > number2, false);
    EXPECT_EQ(number1 > number3, false);
    EXPECT_EQ(number4 > number1, false);
    EXPECT_EQ(number5 > number4, false);
}
TEST(LongArithmetic, less) {
    std::string str = "550987658";
    std::string str2 = "5509876543";
    std::string str3 = "550987658";
    std::string str4 = "-87658";
    std::string str5 = std::to_string(-45678990);
    LongArithmetic number1 = LongArithmetic(str);
    LongArithmetic number2 = LongArithmetic(str2);
    LongArithmetic number3 = LongArithmetic(str3);
    LongArithmetic number4 = LongArithmetic(str4);
    LongArithmetic number5 = LongArithmetic(str5);
    EXPECT_EQ(number1 < number2, true);
    EXPECT_EQ(number1 < number3, true);
    EXPECT_EQ(number4 < number1, true);
    EXPECT_EQ(number5 < number4, true);
}




