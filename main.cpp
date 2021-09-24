#include <iostream>
#include "LongArithmetic.h"

void add() {
    LongArithmetic number1 = LongArithmetic(87654768);
    LongArithmetic number2 = LongArithmetic(5690790);
    LongArithmetic sum = number1 + number2;

    std::cout << number1.getValue() << " minus "<< number2.getValue() << " is " << sum.getValue() << std::endl;
}

void subtract() {
    LongArithmetic number1 = LongArithmetic(87654768);
    LongArithmetic number2 = LongArithmetic(5690790);
    LongArithmetic sum = number1 - number2;
    std::cout << number1.getValue() << " plus " << number2.getValue() << " is " << sum.getValue() << std::endl;
}

void equals() {
    LongArithmetic number1 = LongArithmetic(87654768);
    LongArithmetic number2 = LongArithmetic(5690790);
    std::string answer = (number1 == number2)?" is equal to ": " is not equal to ";
    std::cout << number1.getValue()  << answer << number2.getValue() << std::endl;
}

void greater() {
    LongArithmetic number1 = LongArithmetic(87654768);
    LongArithmetic number2 = LongArithmetic(5690790);
    std::string answer = (number1 > number2) ? " is greater than " : " is not greater than ";
    std::cout << number1.getValue() << answer << number2.getValue() << std::endl;
}

void less() {
    LongArithmetic number1 = LongArithmetic(87654768);
    LongArithmetic number2 = LongArithmetic(5690790);
    std::string answer = (number1 < number2) ? " is less than " : " is not less than ";
    std::cout << number1.getValue() << answer << number2.getValue() << std::endl;
}
void greater_or_equal(){
    LongArithmetic number1 = LongArithmetic(5690790);
    LongArithmetic number2 = LongArithmetic(5690790);
    std::string answer = (number1 <= number2) ? " is less than/equal to " : " is not less or equal to ";
    std::cout << number1.getValue() << answer << number2.getValue() << std::endl;
}
void less_or_equal(){
    LongArithmetic number1 = LongArithmetic(5690790);
    LongArithmetic number2 = LongArithmetic(5690791);
    std::string answer = (number1 >= number2) ? " is greater than/equal to " : " is not greater or equal to ";
    std::cout << number1.getValue() << answer << number2.getValue() << std::endl;
}
int main() {

    add();
    subtract();
    equals();
    greater();
    less();
    greater_or_equal();
    less_or_equal();
    return 0;
}
