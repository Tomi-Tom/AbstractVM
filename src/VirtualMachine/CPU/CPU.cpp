/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** Cpu.cpp
*/

#include "CPU.hpp"
#include "Factory.hpp"

void CPU::handleInstruction(instruction_t instruction) {
    if (instruction.instruction == "push")
        push(instruction.value, instruction.type);
    if (instruction.instruction == "pop")
        pop();
    if (instruction.instruction == "dump")
        dump();
    if (instruction.instruction == "clear")
        clear();
    if (instruction.instruction == "dup")
        dup();
    if (instruction.instruction == "swap")
        swap();
    if (instruction.instruction == "assert")
        assert(instruction.value, instruction.type);
    if (instruction.instruction == "add")
        add();
    if (instruction.instruction == "sub")
        sub();
    if (instruction.instruction == "mul")
        mul();
    if (instruction.instruction == "div")
        div();
    if (instruction.instruction == "mod")
        mod();
    if (instruction.instruction == "load")
        load(instruction.value, instruction.type);
    if (instruction.instruction == "store")
        store(instruction.value, instruction.type);
    if (instruction.instruction == "print")
        print();
    if (instruction.instruction == "exit")
        _exit();
}

void CPU::push(std::string value, eOperandType type) {
    switch (type) {
        case eOperandType::INT8:
            _memory.push(Factory::createOperand(eOperandType::INT8, value));
            break;
        case eOperandType::INT16:
            _memory.push(Factory::createOperand(eOperandType::INT16, value));
            break;
        case eOperandType::INT32:
            _memory.push(Factory::createOperand(eOperandType::INT32, value));
            break;
        case eOperandType::FLOAT:
            _memory.push(Factory::createOperand(eOperandType::FLOAT, value));
            break;
        case eOperandType::DOUBLE:
            _memory.push(Factory::createOperand(eOperandType::DOUBLE, value));
            break;
        default:
            break;
    }
}

void CPU::pop() {
    _memory.pop();
}

void CPU::dump() {
    _memory.dump();
}

void CPU::clear() {
    _memory.clear();
}

void CPU::dup() {
    _memory.dup();
}

void CPU::swap() {
    _memory.swap();
}

void CPU::assert(std::string value, eOperandType type) {
    _memory.assert(Factory::createOperand(type, value));
}

void CPU::add() {
    _memory.add();
}

void CPU::sub() {
    _memory.sub();
}

void CPU::mul() {
    _memory.mul();
}

void CPU::div() {
    _memory.div();
}

void CPU::mod() {
    _memory.mod();
}

void CPU::load(std::string value, eOperandType type) {
   _memory.load(Factory::createOperand(type, value));
}

void CPU::store(std::string value, eOperandType type) {
    _memory.store(Factory::createOperand(type, value));
}

void CPU::print() {
    _memory.print();
}

void CPU::_exit() {
    exit(EXIT_SUCCESS);
}
