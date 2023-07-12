/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** IoInterface.hpp
*/

#ifndef IOINTERFACE_HPP_
	#define IOINTERFACE_HPP_

#include <iostream>
#include <vector>
#include "Instruction.hpp"

class IOInterface {
	public:
        IOInterface() : _isFile(false) {};
        IOInterface(std::string file);
		~IOInterface() {};

        std::vector<instruction_t> getInstructions();
        std::vector<instruction_t> getActualInstructions();
        std::vector<instruction_t> getLiveInstructions();
        void display(std::string output);

	private:
        std::vector<instruction_t> _instructions;
        bool _isFile;

        void getLiveInstruction();
        instruction_t InstructionsParsingFromLine(std::string line, int lineNb);
};

#endif /*IOINTERFACE_HPP_*/