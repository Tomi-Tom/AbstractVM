/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** MyInt32.cpp
*/

#include <iostream>
#include <cmath>
#include <Factory.hpp>
#include "MyInt32.hpp"

MyInt32::MyInt32(const std::string &value) {
    long int tmp;

    tmp = std::stold(value);
    if (tmp > 2147483647 || tmp < -2147483648)
        throw std::runtime_error("Error: Invalid value for Int32 (overflow) should be between -2147483648 and 2147483647");
    _value = static_cast<int>(tmp);
}

std::string MyInt32::toString() const  {
    return std::to_string(_value);
}

eOperandType MyInt32::getType() const  {
    return eOperandType::INT32;
}

IOperand *MyInt32::operator+(const IOperand &rhs) const  {
    if (static_cast<size_t>(rhs.getType()) < static_cast<size_t>(eOperandType::INT32))
        return Factory::createOperand(eOperandType::INT32, std::to_string(_value + std::stold(rhs.toString())));
    return Factory::createOperand(rhs.getType(), std::to_string(_value + std::stold(rhs.toString())));
}

IOperand *MyInt32::operator-(const IOperand &rhs) const  {
    if (static_cast<size_t>(rhs.getType()) < static_cast<size_t>(eOperandType::INT32))
        return Factory::createOperand(eOperandType::INT32, std::to_string(_value - std::stold(rhs.toString())));
    return Factory::createOperand(rhs.getType(), std::to_string(_value - std::stold(rhs.toString())));
}

IOperand *MyInt32::operator*(const IOperand &rhs) const  {
    if (static_cast<size_t>(rhs.getType()) < static_cast<size_t>(eOperandType::INT32))
        return Factory::createOperand(eOperandType::INT32, std::to_string(_value * std::stold(rhs.toString())));
    return Factory::createOperand(rhs.getType(), std::to_string(_value * std::stold(rhs.toString())));
}

IOperand *MyInt32::operator/(const IOperand &rhs) const  {
    if (std::stold(rhs.toString()) == 0)
        throw std::runtime_error("Error: division by 0");
    if (static_cast<size_t>(rhs.getType()) < static_cast<size_t>(eOperandType::INT32))
        return Factory::createOperand(eOperandType::INT32, std::to_string(_value / std::stold(rhs.toString())));
    return Factory::createOperand(rhs.getType(), std::to_string(_value / std::stold(rhs.toString())));
}

IOperand *MyInt32::operator%(const IOperand &rhs) const  {
    if (std::stold(rhs.toString()) == 0)
        throw std::runtime_error("Error: modulo by 0");
    if (static_cast<size_t>(rhs.getType()) < static_cast<size_t>(eOperandType::INT32))
        return Factory::createOperand(eOperandType::INT32, std::to_string(fmod(_value, std::stold(rhs.toString()))));
    return Factory::createOperand(rhs.getType(), std::to_string(fmod(_value, std::stold(rhs.toString()))));
}
