/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** Instruction.hpp
*/

#ifndef INSTRUCTION_HPP_
	#define INSTRUCTION_HPP_

#include <string>
#include "eOperandType.hpp"

typedef struct instruction_s {
    std::string instruction;
    eOperandType type;
    std::string value;
} instruction_t;

#endif /*INSTRUCTION_HPP_*/