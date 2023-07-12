/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** VitrualMachine.cpp
*/

#include <iostream>
#include "VirtualMachine.hpp"
#include "Instruction.hpp"

void VirtualMachine::handleInstructions(std::vector<instruction_t> instructions) {
    std::string output;

    for (instruction_t &instruction : instructions) {
        _cpu.handleInstruction(instruction);
        if (_cpu.getStatus() == false || instruction.instruction == "exit")
            _PowerOn = false;
    }

}

void VirtualMachine::run(std::string file) {
    std::vector<instruction_t> instructions;
    _ioInterface = IOInterface(file);

    while (_PowerOn) {
        instructions = _ioInterface.getInstructions();
        handleInstructions(instructions);
        instructions.clear();
    }
}

void VirtualMachine::run() {
    std::vector<instruction_t> instructions;
    _ioInterface = IOInterface("");

    std::cout << "--[ Welcome to AbstractVM Live Execution ]--" << std::endl;
    while (_PowerOn) {
        instructions = _ioInterface.getLiveInstructions();
        handleInstructions(instructions);
    }
}