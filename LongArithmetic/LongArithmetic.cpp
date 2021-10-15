#include <iostream>
#include <string>
#include <algorithm>
#include "LongArithmetic.h"

// анонимное пространство для реализации вспомогательных методов для операторов
namespace {
    std::string add(const std::string &number1, const std::string &number2) {
        std::string result;
        int num1_len = static_cast<int>(number1.length()) - 1;
        int num2_len = static_cast<int>(number2.length()) - 1;
        int high_bit = 0;
        while (num1_len >= 0 && num2_len >= 0) {
            int digit = (number1[num1_len] - '0') + (number2[num2_len] - '0') + high_bit;
            high_bit = digit / 10;
            result.push_back(digit % 10 + '0');
            --num1_len;
            --num2_len;
        }
        while (num1_len >= 0) {
            int digit = (number1[num1_len] - '0') + high_bit;
            high_bit = digit / 10;
            result.push_back(digit % 10 + '0');
            --num1_len;
        }
        while (num2_len >= 0) {
            int digit = (number2[num2_len] - '0') + high_bit;
            high_bit = digit / 10;
            result.push_back(digit % 10 + '0');
            --num2_len;
        }
        std::reverse(result.begin(), result.end());
        if (high_bit == 1) {
            result.insert(0, "1");
        }
        return result;
    }

    std::string subtract(const std::string &number1, const std::string &number2) { // number1 - number2
        std::string result;
        int carry = 0;
        int n1 = number1.length();
        int n2 = number2.length();
        int diff = n1 - n2;
        for (int i = n2 - 1; i >= 0; --i) {
            int digit = (number1[i + diff] - '0') - (number2[i] - '0') - carry;
            if (digit < 0) {
                digit += 10;
                carry = 1;
            } else {
                carry = 0;
            }
            result.append(std::to_string(digit));
        }
        for (int i = diff - 1; i >= 0; --i) {
            if (number1[i] == '0' && carry == 1) {
                result.append("9");
                continue;
            }
            int digit = (number1[i] - '0') - carry;
            result.append(std::to_string(digit));
            carry = 0;
        }
        std::reverse(result.begin(), result.end());
        int pos = 0;
        for (int i = 0; i < result.size(); ++i) {
            if (result[i] >= '1' && result[i] <= '9') {
                pos = i;
                break;
            }
        }
        result.erase(0, pos);
        return result;
    }

    std::string multiply_one_digit(const std::string &num1, const char &num2_digit, int num_zeros) {
        std::string result;
        //result.insert(0, "0", num_zeros);
        int start = static_cast<int>(num1.size()) - 1;
        int carry = 0;
        for (int i = start; i >= 0; --i) {
            int multiplication = (num1[i] - '0') * (num2_digit - '0') + carry;
            carry = multiplication / 10;
            result.append(std::to_string(multiplication % 10));
        }
        if (carry) {
            result.append(std::to_string(carry));
        }
        std::reverse(result.begin(), result.end());
        for (int i = 0; i < num_zeros; ++i) {
            result.push_back('0');
        }
        return result;
    }

    std::string multiply(const std::string &num1, const std::string &num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        std::string result;
        std::string prev_digit = "0";
        int start = static_cast<int>(num2.size()) - 1;
        for (int i = start; i >= 0; --i) {
            std::string current_digit = multiply_one_digit(num1, num2[i], start - i);
            result = add(current_digit, prev_digit);
            prev_digit = result;
        }

        return result;
    }

    bool abs_cmp(const LongArithmetic &number1, const LongArithmetic &number2) {
        if (number1.getAbsoluteValue().length() > number2.getAbsoluteValue().length()) {
            return true;
        }
        if (number1.getAbsoluteValue().length() < number2.getAbsoluteValue().length()) {
            return false;
        } else return number1.getAbsoluteValue() >= number2.getAbsoluteValue();
    }
}

LongArithmetic::LongArithmetic(int big_integer) : value(std::to_string(big_integer)), sign(value[0] == '-') {
}

LongArithmetic::LongArithmetic(const std::string &big_integer) : value(big_integer), sign(big_integer[0] == '-') {
}

LongArithmetic &LongArithmetic::operator+=(const LongArithmetic &big_int) {
    LongArithmetic num(*this);
    this->value = add(this->getValue(), big_int.getValue());
    return (*this);
}

LongArithmetic LongArithmetic::operator+(const LongArithmetic &big_int) {
    LongArithmetic num(*this);
    num += big_int;
    return num;
}

LongArithmetic &LongArithmetic::operator-=(const LongArithmetic &big_int) {
    LongArithmetic num(*this);
    if (*this == big_int) {
        this->value = "0";
        this->sign = true;
    } else if (this->sign == big_int.sign) {
        // |number1| > |number2|  => |number1| = |number1 - number2|
        if (abs_cmp(*this, big_int)) {
            this->value = subtract(this->getAbsoluteValue(), big_int.getAbsoluteValue());
            if (this->sign) {
                this->value.insert(0, "-");
                this->sign = true;
            }
        } else { // number1 < number2 => number1 = -(number2 - number1)
            this->value = subtract(big_int.getAbsoluteValue(), this->getAbsoluteValue());
            if (!this->sign) {
                this->value.insert(0, "-");
                this->sign = true;
            }
        }
    }
        // 1) -number1 - number2 = -(number1 + number2);
        // 2) number1 - (-number2) = number1 + number2
    else if (this->sign != big_int.sign) {
        this->value = add(this->getAbsoluteValue(), big_int.getAbsoluteValue());
        if (this->sign) {
            this->value.insert(0, "-");
            this->sign = true;
        }
    }
    return (*this);
}

LongArithmetic LongArithmetic::operator-(const LongArithmetic &big_int) {
    LongArithmetic num(*this);
    num -= big_int;
    return num;
}

LongArithmetic &LongArithmetic::operator*=(const LongArithmetic &big_int) {
    LongArithmetic num(*this);
    this->value = multiply(this->getAbsoluteValue(), big_int.getAbsoluteValue());
    if (this->sign != big_int.sign) {
        this->sign = true;
        this->value.insert(0, "-");
    }
    return (*this);
}

LongArithmetic LongArithmetic::operator*(const LongArithmetic &big_int) {
    LongArithmetic num(*this);
    num *= big_int;
    return num;
}

bool LongArithmetic::operator==(const LongArithmetic &big_int) const {
    return (this->getAbsoluteValue() == big_int.getAbsoluteValue() && this->sign == big_int.sign);
}

bool LongArithmetic::operator>(const LongArithmetic &big_int) const {
    if (this->sign == big_int.sign) { // case: (negative and negative) or (positive and positive)
        if (this->getAbsoluteValue().length() > big_int.getAbsoluteValue().length()) {
            return !(this->sign); // case positive and positive: 100 > 10 - true (sign = false);
            // negative and negative: -100 < -10 (sign = true)
        } else if (this->getAbsoluteValue().length() < big_int.getAbsoluteValue().length()) {
            return this->sign;
        } else { // length_1 = length_2
            return (this->getAbsoluteValue() > big_int.getAbsoluteValue() &&
                    !(this->sign)); // false if |x1| > |x2| and they are negative, otherwise true
        }
    } else if (this->sign) {
        return false;
    }
    return true; // case: this.value is positive, big_int.value is negative
}

bool LongArithmetic::operator<(const LongArithmetic &big_int) const {
    return !(*this >= big_int);
}

bool LongArithmetic::operator>=(const LongArithmetic &big_int) const {
    bool answer = this->getValue() == big_int.getValue() || (*this > big_int);
    return answer;
}

bool LongArithmetic::operator<=(const LongArithmetic &big_int) const {
    bool answer = this->getValue() == big_int.getValue() || (*this < big_int);
    return answer;
}



