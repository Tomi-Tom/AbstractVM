/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** MyDouble.hpp
*/

#ifndef MyDouble_HPP_
#define MyDouble_HPP_

#include <string>
#include "IOperand.hpp"

class MyDouble : public IOperand {
public:
    MyDouble(const std::string &value);
    ~MyDouble() override {}

    std::string toString() const override;

    eOperandType getType() const override;

    IOperand *operator+(const IOperand &rhs) const override;
    IOperand *operator-(const IOperand &rhs) const override;
    IOperand *operator*(const IOperand &rhs) const override;
    IOperand *operator/(const IOperand &rhs) const override;
    IOperand *operator%(const IOperand &rhs) const override;

private:
    double _value;
};

#endif /*MyDouble_HPP_*/
