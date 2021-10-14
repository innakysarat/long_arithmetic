#pragma once

class LongArithmetic {

private:

    std::string value = "0";
    bool sign = false;

public:

    LongArithmetic(const std::string &big_integer);

    LongArithmetic(int big_integer);

    LongArithmetic &operator+=(const LongArithmetic &value);

    LongArithmetic &operator-=(const LongArithmetic &value);

    LongArithmetic operator+(const LongArithmetic &big_integer);

    LongArithmetic operator-(const LongArithmetic &big_integer);

    bool operator==(const LongArithmetic &big_integer) const;

    bool operator>(const LongArithmetic &big_integer) const;

    bool operator<(const LongArithmetic &big_integer) const;

    bool operator>=(const LongArithmetic &big_integer) const;

    bool operator<=(const LongArithmetic &big_integer) const;

    [[nodiscard]] std::string getAbsoluteValue() const {
        if (value[0] == '-') {
            return (value).substr(1, value.length());
        }
        return value;
    };

    [[nodiscard]] std::string getValue() const {
        return value;
    };
};
