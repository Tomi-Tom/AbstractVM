/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** Factory.hpp
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <functional>
#include <vector>
#include <iostream>

#include "eOperandType.hpp"
#include "IOperand.hpp"

class Factory {
public:
    Factory() {}
    ~Factory() {}

    static IOperand *createOperand(eOperandType type, const std::string &value) {
        Factory factory;

        switch (type) {
            case eOperandType::INT8:
                return factory.createInt8(value);
            case eOperandType::INT16:
                return factory.createInt16(value);
            case eOperandType::INT32:
                return factory.createInt32(value);
            case eOperandType::FLOAT:
                return factory.createFloat(value);
            case eOperandType::DOUBLE:
                return factory.createDouble(value);
            default:
                return nullptr;
        }
    }

private:
    IOperand *createInt8(const std::string &value);
    IOperand *createInt16(const std::string &value);
    IOperand *createInt32(const std::string &value);
    IOperand *createFloat(const std::string &value);
    IOperand *createDouble(const std::string &value);
};

#endif /* FACTORY_HPP_ */
