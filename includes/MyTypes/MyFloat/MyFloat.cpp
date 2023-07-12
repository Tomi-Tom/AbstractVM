/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** MyFloat.cpp
*/

#include <iostream>
#include <cmath>
#include <Factory.hpp>
#include "MyFloat.hpp"

MyFloat::MyFloat(const std::string &value) {
    double tmp;

    tmp = std::stold(value);
    if (tmp > 3.40282e+38 || tmp < -3.40282e+38)
        throw std::runtime_error("Error: Invalid value for Float (overflow) should be between -3.40282e+38 and 3.40282e+38");
    _value = static_cast<double>(tmp);
}

std::string MyFloat::toString() const {
    std::string str = std::to_string(_value);
    size_t pos = str.find_last_not_of('0');

    if (pos != std::string::npos)
        str.erase(pos + 1);
    pos = str.find_last_not_of('.');
    if (pos != std::string::npos)
        str.erase(pos + 1);
    return str;
}

eOperandType MyFloat::getType() const {
    return eOperandType::FLOAT;
}

IOperand *MyFloat::operator+(const IOperand &rhs) const {
    if (static_cast<size_t>(rhs.getType()) < static_cast<size_t>(eOperandType::FLOAT))
        return Factory::createOperand(eOperandType::FLOAT, std::to_string(_value + std::stof(rhs.toString())));
    return Factory::createOperand(rhs.getType(), std::to_string(_value + std::stof(rhs.toString())));
}

IOperand *MyFloat::operator-(const IOperand &rhs) const {
    if (static_cast<size_t>(rhs.getType()) < static_cast<size_t>(eOperandType::FLOAT))
        return Factory::createOperand(eOperandType::FLOAT, std::to_string(_value - std::stof(rhs.toString())));
    return Factory::createOperand(rhs.getType(), std::to_string(_value - std::stof(rhs.toString())));
}

IOperand *MyFloat::operator*(const IOperand &rhs) const {
    if (static_cast<size_t>(rhs.getType()) < static_cast<size_t>(eOperandType::FLOAT))
        return Factory::createOperand(eOperandType::FLOAT, std::to_string(_value * std::stof(rhs.toString())));
    return Factory::createOperand(rhs.getType(), std::to_string(_value * std::stof(rhs.toString())));
}

IOperand *MyFloat::operator/(const IOperand &rhs) const {
    if (std::stold(rhs.toString()) == 0)
        throw std::runtime_error("Error: division by 0");
    if (static_cast<size_t>(rhs.getType()) < static_cast<size_t>(eOperandType::FLOAT))
        return Factory::createOperand(eOperandType::FLOAT, std::to_string(_value / std::stof(rhs.toString())));
    return Factory::createOperand(rhs.getType(), std::to_string(_value / std::stof(rhs.toString())));
}

IOperand *MyFloat::operator%(const IOperand &rhs) const {
    if (std::stold(rhs.toString()) == 0)
        throw std::runtime_error("Error: modulo by 0");
    if (static_cast<size_t>(rhs.getType()) < static_cast<size_t>(eOperandType::FLOAT))
        return Factory::createOperand(eOperandType::FLOAT, std::to_string(fmod(_value, std::stof(rhs.toString()))));
    return Factory::createOperand(rhs.getType(), std::to_string(fmod(_value, std::stof(rhs.toString()))));
}
