/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** Cpu.hpp
*/

#ifndef CPU_HPP_
	#define CPU_HPP_

#include <iostream>
#include <functional>
#include <unordered_map>
#include "Memory.hpp"
#include "Instruction.hpp"

class CPU {
	public:
        CPU() : _status(true) {};
        ~CPU() {};

        bool getStatus() const { return _status; };
        void handleInstruction(instruction_t instruction);

	private:
        Memory _memory;
        bool _status;

        void push(std::string value, eOperandType type);
        void pop();
        void dump();
        void clear();
        void dup();
        void swap();
        void assert(std::string value, eOperandType type);
        void add();
        void sub();
        void mul();
        void div();
        void mod();
        void load(std::string value, eOperandType type);
        void store(std::string value, eOperandType type);
        void print();
        void _exit();
};

#endif /*CPU_HPP_*/
