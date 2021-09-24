#include <iostream>
#include <string>
#include <algorithm>
#include "LongArithmetic.h"

LongArithmetic::LongArithmetic() {
    this->value = "0";
    this->sign = false;
}

LongArithmetic::LongArithmetic(int big_integer) {
    if (big_integer == 0) {
        this->value = "0";
    } else {
        this->value = std::to_string(big_integer);
    }
}

LongArithmetic::LongArithmetic(std::string &big_integer) {
    this->sign = (big_integer[0] == '-');
    this->value = big_integer;
}

void LongArithmetic::setSign(bool sign_number) {
    this->sign = sign_number;
}

LongArithmetic LongArithmetic::operator+(LongArithmetic &big_int) {
    std::string result_string = plusInteger(big_int.value, this->value);
    LongArithmetic result = LongArithmetic(result_string);
    return result;
}

LongArithmetic LongArithmetic::operator-(LongArithmetic &big_int) {
    std::string result_string;
    if ((!this->sign && !big_int.sign) && (*this >= big_int)) {
        result_string = minusInteger(this->getValue(), big_int.getValue());
    }
    if ((!this->sign && !big_int.sign) && (*this < big_int)) {
        result_string = minusInteger(big_int.getValue(), this->getValue());
        result_string.insert(0, "-");
    }
    if (!this->sign && big_int.sign) {
        result_string = plusInteger(big_int.value.substr(1, big_int.value.length()), this->getValue());
    }
    if (this->sign && !big_int.sign) {
        result_string = plusInteger(big_int.getValue(), (this->value).substr(1, this->value.length()));
        result_string.insert(0, "-");
    }
    LongArithmetic result = LongArithmetic(result_string);
    return result;
}

bool LongArithmetic::operator==(LongArithmetic &big_int) {
    return (this->getValue() == big_int.getValue() && this->sign == big_int.sign);
}

bool LongArithmetic::operator>(LongArithmetic &big_int) {
    if (!this->sign && !big_int.sign) {
        if (this->getValue().length() > big_int.getValue().length()) {
            return true;
        }
        if (this->getValue().length() < big_int.getValue().length()) {
            return false;
        }
        return this->getValue() > big_int.getValue();
    }
    if (this->sign && big_int.sign) {
        if (this->getValue().length() < big_int.getValue().length()) {
            return true;
        }
        if (this->getValue().length() > big_int.getValue().length()) {
            return false;
        }
        return this->getValue() < big_int.getValue();
    }
    if (this->sign && !big_int.sign) {
        return false;
    }
    if (!this->sign && big_int.sign) {
        return true;
    }
}

bool LongArithmetic::operator<(LongArithmetic &big_int) {
    return !(*this > big_int);
}

bool LongArithmetic::operator>=(LongArithmetic &big_int) {
    if (this->getValue() == big_int.getValue()) {
        return true;
    }
    return (*this > big_int);
}

bool LongArithmetic::operator<=(LongArithmetic &big_int) {
    if (this->getValue() == big_int.getValue()) {
        return true;
    }
    return (*this < big_int);
}

std::string LongArithmetic::plusInteger(std::string int1, std::string int2) {
    std::string result = (int1.length() > int2.length()) ? int1 : int2;
    char high_bit = '0';
    int diff_length = std::abs(static_cast<int>(int1.length()) - static_cast<int>(int2.length()));
    if (int1.length() > int2.length()) {
        int2.insert(0, diff_length, '0');
    } else {
        int1.insert(0, diff_length, '0');
    }
    for (size_t i = static_cast<int>(int1.length()) - 1; i > 0; --i) {
        result[i] = ((high_bit - '0') + (int1[i] - '0') + (int2[i] - '0')) + '0';
        if (result[i] > '9') {
            result[i] -= 10;
            high_bit = '1';
        } else {
            high_bit = '0';
        }
    }
    result[0] = ((high_bit - '0') + (int1[0] - '0') + (int2[0] - '0')) + '0';
    if (result[0] > '9') {
        result[0] -= 10;
        result.insert(0, 1, '1');
    }
    return result;
}

std::string LongArithmetic::minusInteger(std::string int1, std::string int2) {
    std::string result = (int1.length() > int2.length()) ? int1 : int2;
    int diff_length = std::abs(static_cast<int>(int1.length()) - static_cast<int>(int2.length()));
    if (int1.length() > int2.length()) {
        int2.insert(0, diff_length, '0');
    } else if (int1.length() < int2.length()) {
        int1.insert(0, diff_length, '0');
    }
    size_t size = static_cast<int>(int1.length());
    for (int i = size - 1; i >= 0; --i) {
        if (int1[i] < int2[i]) {
            int1[i] = int1[i] + 10;
            int1[i - 1] -= 1;
        }
        result[i] = ((int1[i] - '0') - (int2[i] - '0')) + '0';
    }
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

std::string LongArithmetic::getValue() {
    return this->value;
}
