/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** Factory.cpp
*/

#include "Factory.hpp"
#include "IOperand.hpp"
#include "MyInt8.hpp"
#include "MyInt16.hpp"
#include "MyInt32.hpp"
#include "MyFloat.hpp"
#include "MyDouble.hpp"

IOperand *Factory::createInt8(const std::string &value) {
    return new MyInt8(value);
}

IOperand *Factory::createInt16(const std::string &value) {
    return new MyInt16(value);
}

IOperand *Factory::createInt32(const std::string &value) {
    return new MyInt32(value);
}

IOperand *Factory::createFloat(const std::string &value) {
    return new MyFloat(value);
}

IOperand *Factory::createDouble(const std::string &value) {
    return new MyDouble(value);
}