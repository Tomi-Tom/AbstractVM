/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** eOperandType.cpp
*/

#include <iostream>
#include <string>
#include "eOperandType.hpp"

eOperandType getTypeFromString(std::string type) {
    if (type == "int8")
        return eOperandType::INT8;
    if (type == "int16")
        return eOperandType::INT16;
    if (type == "int32")
        return eOperandType::INT32;
    if (type == "float")
        return eOperandType::FLOAT;
    if (type == "double")
        return eOperandType::DOUBLE;
    return eOperandType::NULLTYPE;
}

std::string getStringFromType(eOperandType type) {
    if (type == eOperandType::INT8)
        return "int8";
    if (type == eOperandType::INT16)
        return "int16";
    if (type == eOperandType::INT32)
        return "int32";
    if (type == eOperandType::FLOAT)
        return "float";
    if (type == eOperandType::DOUBLE)
        return "double";
    return "null";
}