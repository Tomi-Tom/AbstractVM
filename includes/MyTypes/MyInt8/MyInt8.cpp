/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** MyInt8.cpp
*/

#include <cmath>
#include <iostream>
#include <Factory.hpp>
#include "MyInt8.hpp"

MyInt8::MyInt8(const std::string &value) {
    long int tmp;

    tmp = std::stold(value);
    if (tmp > 127 || tmp < -128)
        throw std::runtime_error("Error: Invalid value for Int8 (overflow) should be between -128 and 127");
    _value = static_cast<char>(tmp);
}

std::string MyInt8::toString() const  {
    return std::to_string(_value);
}

eOperandType MyInt8::getType() const  {
    return eOperandType::INT8;
}

IOperand *MyInt8::operator+(const IOperand &rhs) const  {
    return Factory::createOperand(rhs.getType(), std::to_string(_value + std::stold(rhs.toString())));
}

IOperand *MyInt8::operator-(const IOperand &rhs) const  {
    return Factory::createOperand(rhs.getType(), std::to_string(_value - std::stold(rhs.toString())));
}

IOperand *MyInt8::operator*(const IOperand &rhs) const  {
    return Factory::createOperand(rhs.getType(), std::to_string(_value * std::stold(rhs.toString())));
}

IOperand *MyInt8::operator/(const IOperand &rhs) const  {
    if (std::stold(rhs.toString()) == 0)
        throw std::runtime_error("Error: division by 0");
    return Factory::createOperand(rhs.getType(), std::to_string(_value / std::stold(rhs.toString())));
}

IOperand *MyInt8::operator%(const IOperand &rhs) const  {
    if (std::stold(rhs.toString()) == 0)
        throw std::runtime_error("Error: modulo by 0");
    return Factory::createOperand(rhs.getType(), std::to_string(fmod(_value, std::stold(rhs.toString()))));
}
