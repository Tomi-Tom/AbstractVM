/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** Memory.hpp
*/

#ifndef MEMORY_HPP_
	#define MEMORY_HPP_

#include <iostream>
#include <stack>
#include <vector>
#include <memory>

#include "IOperand.hpp"

class Memory {
	public:
		Memory() {
            _register.resize(16);
            for (auto &i : _register) {
                i = nullptr;
            }
        }
		~Memory() {
            while (!_stack.empty()) {
                _stack.pop();
            }
        }

        IOperand *getTop();

        void push(IOperand *value);
        void pop();

        void add();
        void sub();
        void mul();
        void div();
        void mod();

        void clear();
        void dup();
        void swap();
        void assert(IOperand *value);

        void dump();

        void load(IOperand *value);
        void store(IOperand *value);

        void print();

	private:
        std::stack<IOperand *> _stack;
        std::vector<IOperand *> _register;
};

#endif /*MEMORY_HPP_*/
