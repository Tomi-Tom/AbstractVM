/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** MyDouble.cpp
*/

#include <cmath>
#include <iostream>
#include "MyDouble.hpp"

MyDouble::MyDouble(const std::string &value) {
    long double tmp;

    tmp = std::stold(value);
    if (tmp > 1.79769e+308 || tmp < -1.79769e+308)
        throw std::runtime_error("Error: Invalid value for Double (overflow) should be between -1.79769e+308 and 1.79769e+308");
    _value = static_cast<double>(tmp);
}

std::string MyDouble::toString() const {
    std::string str = std::to_string(_value);
    size_t pos = str.find_last_not_of('0');

    if (pos != std::string::npos)
        str.erase(pos + 1);
    pos = str.find_last_not_of('.');
    if (pos != std::string::npos)
        str.erase(pos + 1);
    return str;
}

eOperandType MyDouble::getType() const {
    return eOperandType::DOUBLE;
}

IOperand *MyDouble::operator+(const IOperand &rhs) const {
    return new MyDouble(std::to_string(_value + std::stold(rhs.toString())));
}

IOperand *MyDouble::operator-(const IOperand &rhs) const {
    return new MyDouble(std::to_string(_value - std::stold(rhs.toString())));
}

IOperand *MyDouble::operator*(const IOperand &rhs) const {
    return new MyDouble(std::to_string(_value * std::stold(rhs.toString())));
}

IOperand *MyDouble::operator/(const IOperand &rhs) const {
    if (std::stoi(rhs.toString()) == 0)
        throw std::runtime_error("Error: division by 0");
    return new MyDouble(std::to_string(_value / std::stold(rhs.toString())));
}

IOperand *MyDouble::operator%(const IOperand &rhs) const {
    if (std::stoi(rhs.toString()) == 0)
        throw std::runtime_error("Error: modulo by 0");
    return new MyDouble(std::to_string(std::fmod(_value, std::stold(rhs.toString()))));
}
