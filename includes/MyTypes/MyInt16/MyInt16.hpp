/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** MyInt16.hpp
*/

#ifndef MYINT16_HPP_
#define MYINT16_HPP_

#include <string>
#include "IOperand.hpp"

class MyInt16 : public IOperand {
public:
    MyInt16(const std::string &value);
    ~MyInt16() override {};

    std::string toString() const override;

    eOperandType getType() const override;

    IOperand *operator+(const IOperand &rhs) const override;
    IOperand *operator-(const IOperand &rhs) const override;
    IOperand *operator*(const IOperand &rhs) const override;
    IOperand *operator/(const IOperand &rhs) const override;
    IOperand *operator%(const IOperand &rhs) const override;

private:
    __int16_t _value;
};

#endif /*MYINT16_HPP_*/
