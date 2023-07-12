/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** MyInt16.cpp
*/

#include <iostream>
#include <cmath>
#include <Factory.hpp>
#include "MyInt16.hpp"

MyInt16::MyInt16(const std::string &value) {
    long int tmp;

    tmp = std::stold(value);
    if (tmp > 32767 || tmp < -32768)
        throw std::runtime_error("Error: Invalid value for Int16 (overflow) should be between -32768 and 32767");
    _value = static_cast<short>(tmp);
}

std::string MyInt16::toString() const  {
    return std::to_string(_value);
}

eOperandType MyInt16::getType() const  {
    return eOperandType::INT16;
}

IOperand *MyInt16::operator+(const IOperand &rhs) const  {
    if (static_cast<size_t>(rhs.getType()) < static_cast<size_t>(eOperandType::INT16))
        return Factory::createOperand(eOperandType::INT16, std::to_string(_value + std::stold(rhs.toString())));
    return Factory::createOperand(rhs.getType(), std::to_string(_value + std::stold(rhs.toString())));
}

IOperand *MyInt16::operator-(const IOperand &rhs) const  {
    if (static_cast<size_t>(rhs.getType()) < static_cast<size_t>(eOperandType::INT16))
        return Factory::createOperand(eOperandType::INT16, std::to_string(_value - std::stold(rhs.toString())));
    return Factory::createOperand(rhs.getType(), std::to_string(_value - std::stold(rhs.toString())));
}

IOperand *MyInt16::operator*(const IOperand &rhs) const  {
    if (static_cast<size_t>(rhs.getType()) < static_cast<size_t>(eOperandType::INT16))
        return Factory::createOperand(eOperandType::INT16, std::to_string(_value * std::stold(rhs.toString())));
    return Factory::createOperand(rhs.getType(), std::to_string(_value * std::stold(rhs.toString())));
}

IOperand *MyInt16::operator/(const IOperand &rhs) const  {
    if (std::stold(rhs.toString()) == 0)
        throw std::runtime_error("Error: division by 0");
    if (static_cast<size_t>(rhs.getType()) < static_cast<size_t>(eOperandType::INT16))
        return Factory::createOperand(eOperandType::INT16, std::to_string(_value / std::stold(rhs.toString())));
    return Factory::createOperand(rhs.getType(), std::to_string(_value / std::stold(rhs.toString())));
}

IOperand *MyInt16::operator%(const IOperand &rhs) const  {
    if (std::stold(rhs.toString()) == 0)
        throw std::runtime_error("Error: modulo by 0");
    if ((static_cast<size_t>(rhs.getType()) < static_cast<size_t>(eOperandType::INT16)))
        return Factory::createOperand(eOperandType::INT16, std::to_string(fmod(_value, std::stold(rhs.toString()))));
    return Factory::createOperand(rhs.getType(), std::to_string(fmod(_value, std::stold(rhs.toString()))));
}
