/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** Memory.cpp
*/

#include "Memory.hpp"

IOperand *Memory::getTop() {
    return _stack.top();
}

void Memory::push(IOperand *value) {
    _stack.push(value);
}

void Memory::pop() {
    if (_stack.empty())
        throw std::runtime_error("Error: not enough values on the stack");
    _stack.pop();
}

void Memory::add() {
    IOperand *first;
    IOperand *second;

    if (_stack.size() < 2)
        throw std::runtime_error("Error: not enough values on the stack");
    first = _stack.top();
    _stack.pop();
    second = _stack.top();
    _stack.pop();

    _stack.push(*second + *first);
}

void Memory::sub() {
    IOperand *first;
    IOperand *second;

    if (_stack.size() < 2)
        throw std::runtime_error("Error: not enough values on the stack");
    first = _stack.top();
    _stack.pop();
    second = _stack.top();
    _stack.pop();

    _stack.push(*second - *first);
}

void Memory::mul() {
    IOperand *first;
    IOperand *second;

    if (_stack.size() < 2)
        throw std::runtime_error("Error: not enough values on the stack");
    first = _stack.top();
    _stack.pop();
    second = _stack.top();
    _stack.pop();

    _stack.push(*second * *first);
}

void Memory::div() {
    IOperand *first;
    IOperand *second;

    if (_stack.size() < 2)
        throw std::runtime_error("Error: not enough values on the stack");
    first = _stack.top();
    _stack.pop();
    second = _stack.top();
    _stack.pop();

    _stack.push(*second / *first);
}

void Memory::mod() {
    IOperand *first;
    IOperand *second;

    if (_stack.size() < 2)
        throw std::runtime_error("Error: not enough values on the stack");
    first = _stack.top();
    _stack.pop();
    second = _stack.top();
    _stack.pop();

    _stack.push(*second % *first);
}

void Memory::clear() {
    if (_stack.empty())
        throw std::runtime_error("Error: stack is empty");
    while (!_stack.empty()) {
        _stack.pop();
    }
}

void Memory::dup() {
    IOperand *top;

    if (_stack.empty())
        throw std::runtime_error("Error: stack is empty");
    top = _stack.top();
    _stack.push(top);
}

void Memory::swap() {
    IOperand *first;
    IOperand *second;

    if (_stack.size() < 2)
        throw std::runtime_error("Error: not enough values on the stack");
    first = _stack.top();
    _stack.pop();
    second = _stack.top();
    _stack.pop();

    _stack.push(first);
    _stack.push(second);
}

void Memory::dump() {
    std::string returnString;
    std::stack <IOperand *> tmp = _stack;

    for (size_t i = 0; i < _stack.size(); i++) {
        std::cout << std::fixed << tmp.top()->toString() << std::endl;
        tmp.pop();
    }
}

void Memory::assert(IOperand *value) {
    if (_stack.empty())
        throw std::runtime_error("Error: stack is empty");
    if (value->getType() != _stack.top()->getType())
        throw std::runtime_error("Error: assert value is not the same types as the top of the stack");
    if (value->toString() != _stack.top()->toString())
        throw std::runtime_error("Error: assert value is not the same value as the top of the stack");
}

void Memory::load(IOperand *value) {
    if (value->getType() != eOperandType::INT8)
        throw std::runtime_error("Error: load value is not an INT8");
    if (_register[std::stoi(value->toString())] == nullptr)
        throw std::runtime_error("Error: register is empty");
    if (std::stoi(value->toString()) > 15 || std::stoi(value->toString()) < 0)
        throw std::runtime_error("Error: register index is not between 0 and 15");
    _stack.push(_register[std::stoi(value->toString())]);
}

void Memory::store(IOperand *value) {
    if (value->getType() != eOperandType::INT8)
        throw std::runtime_error("Error: store value is not an INT8");
    if (_stack.empty())
        throw std::runtime_error("Error: stack is empty");
    if (std::stoi(value->toString()) > 15 || std::stoi(value->toString()) < 0)
        throw std::runtime_error("Error: register index is not between 0 and 15");
    _register[std::stoi(value->toString())] = _stack.top();
    _stack.pop();
}

void Memory::print() {
    IOperand *top;

    if (_stack.empty())
        throw std::runtime_error("Error: stack is empty");
    top = _stack.top();
    if (top->getType() != eOperandType::INT8)
        throw std::runtime_error("Error: print value is not an INT8");
    std::cout << static_cast<char>(std::stoi(top->toString())) << std::endl;
}
