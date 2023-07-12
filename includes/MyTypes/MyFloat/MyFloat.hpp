/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** MyFloat.hpp
*/

#ifndef MyFloat_HPP_
#define MyFloat_HPP_

#include <string>
#include "IOperand.hpp"

class MyFloat : public IOperand {
public:
    MyFloat(const std::string &value);
    ~MyFloat() override {};

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

#endif /*MyFloat_HPP_*/
