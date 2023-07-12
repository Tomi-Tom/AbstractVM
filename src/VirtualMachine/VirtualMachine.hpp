/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** VitrualMachine.hpp
*/
#ifndef VIRTUALMACHINE_HPP_
	#define VIRTUALMACHINE_HPP_

#include <iostream>

#include "IOInterface.hpp"
#include "CPU.hpp"

class VirtualMachine {
	public:
		VirtualMachine() : _PowerOn(true) {}
		~VirtualMachine() {};

        void run(std::string file);
        void run();

	private:
        CPU _cpu;
        IOInterface _ioInterface;

        bool _PowerOn;

        void handleLiveInstructions(std::vector<instruction_t>);
        void handleInstructions(std::vector<instruction_t>);
};

#endif /*VIRTUALMACHINE_HPP_*/
