/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** eOperandType.hpp
*/

#ifndef EOPERANDTYPE_HPP_
	#define EOPERANDTYPE_HPP_

enum class eOperandType {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE,
    NULLTYPE
};

eOperandType getTypeFromString(std::string type);
std::string getStringFromType(eOperandType type);

#endif /*EOPERANDTYPE_HPP_*/
