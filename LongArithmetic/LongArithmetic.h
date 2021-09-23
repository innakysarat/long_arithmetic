
class LongArithmetic {
private:
    std::string big_integer;
    bool sign;

    std::string plusInteger(std::string int1, std::string int2);

    std::string minusInteger(std::string int1, std::string int2);

public:
    LongArithmetic();

    explicit LongArithmetic(std::string &big_integer);
    explicit LongArithmetic(int big_integer);
    LongArithmetic operator+(LongArithmetic &big_integer);

    LongArithmetic operator-(LongArithmetic &big_integer);

    bool operator==(LongArithmetic &big_integer);
    bool operator>(LongArithmetic &big_integer);
    bool operator<(LongArithmetic &big_integer);
    bool operator>=(LongArithmetic &big_integer);
    bool operator<=(LongArithmetic &big_integer);

    std::string getValue();
    void setSign(bool sign);
};
