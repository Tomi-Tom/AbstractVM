/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** MyInt32.hpp
*/

#ifndef MYINT32_HPP_
#define MYINT32_HPP_

#include <string>
#include "IOperand.hpp"

class MyInt32 : public IOperand {
public:
    MyInt32(const std::string &value);
    ~MyInt32() override {};

    std::string toString() const override;

    eOperandType getType() const override;

    IOperand *operator+(const IOperand &rhs) const override;
    IOperand *operator-(const IOperand &rhs) const override;
    IOperand *operator*(const IOperand &rhs) const override;
    IOperand *operator/(const IOperand &rhs) const override;
    IOperand *operator%(const IOperand &rhs) const override;

private:
    __int32_t _value;
};

#endif /*MYINT32_HPP_*/
