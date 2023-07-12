/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** IoInterface.cpp
*/

#include <fstream>
#include <regex>
#include "IOInterface.hpp"

IOInterface::IOInterface(std::string file) : _isFile(true) {
    std::string line;
    std::ifstream fileStream(file);

    if (file == "") {
        fileStream.close();
        _isFile = false;
        return;
    }
    if (!fileStream.is_open())
        throw std::runtime_error("Error: Can't open file");

    for (int i = 1; getline(fileStream, line); i++) {
        if (line.empty() || line.find(";") != std::string::npos)
            continue;
        _instructions.push_back(InstructionsParsingFromLine(line, i));
    }

    fileStream.close();
}

void IOInterface::getLiveInstruction() {
    std::string line;
    std::cout << "\033[1;31m{Abstract-VM} > \033[0m";

    if (!getline(std::cin, line)) {
        if (std::cin.eof())
            exit(EXIT_SUCCESS);
        if (std::cin.fail())
            throw std::runtime_error("Error: Can't read on stdin");
    }

    if (line.empty() || line.find(";") != std::string::npos)
        _instructions.push_back(instruction_t{"skip", eOperandType::NULLTYPE, ""});
    _instructions.push_back(InstructionsParsingFromLine(line, -1));
}

std::vector<instruction_t> IOInterface::getLiveInstructions() {
    _instructions.clear();
    getLiveInstruction();
    return _instructions;
}

void handleExit(std::vector<instruction_t> instructions) {
    for (instruction_t instruction : instructions) {
        if (instruction.instruction == "exit")
            return;
    }
    throw std::runtime_error("Error: No exit instruction");
}

std::vector<instruction_t> IOInterface::getInstructions() {
    if (_isFile) {
        handleExit(_instructions);
        return _instructions;
    } else {
        _instructions.clear();
        return getActualInstructions();
    }
}

std::vector<instruction_t> IOInterface::getActualInstructions() {
    _instructions.clear();
    std::string line;

    while (getline(std::cin, line)) {
        if (line == ";;")
            break;
        if (line.empty() || line.find(";") != std::string::npos)
            continue;
        _instructions.push_back(InstructionsParsingFromLine(line, -1));
    }
    return _instructions;
}

instruction_t IOInterface::InstructionsParsingFromLine(std::string line, int lineNb) {
    instruction_t instruction;
    std::string Type;
    std::regex instructionsRegex("^(push|pop|dump|clear|dup|swap|assert|add|sub|mul|div|mod|load|store|print|exit|;;).*$");
    std::regex instructionWithoutValueRegex("^(pop|dump|clear|dup|swap|add|sub|mul|div|mod|print|exit)$");
    std::regex instructionWithValueRegex("^(push|assert|load|store)$");
    std::regex valueRegex("^([-]?[0-9]+(.[0-9]+)?)$");

    // Get instruction
    instruction.instruction = line.substr(0, line.find(" "));

    // Get types and value depend on if the instruction has a value or not
    if (std::regex_match(instruction.instruction, instructionWithValueRegex)) {
        instruction.type = getTypeFromString(line.substr(line.find(" ") + 1, line.find("(") - line.find(" ") - 1));
        instruction.value = line.substr(line.find("(") + 1, line.find(")") - line.find("(") - 1);
    } else {
        instruction.type = eOperandType::NULLTYPE;
        instruction.value = "";
    }


    if (!std::regex_match(instruction.instruction, instructionsRegex))
        throw std::runtime_error("Error : Bad Instruction" + (lineNb != -1 ? " at line " + std::to_string(lineNb) : ""));
    if (std::regex_match(instruction.instruction, instructionWithValueRegex)) {
        if (!std::regex_match(instruction.value, valueRegex))
            throw std::runtime_error("Error : Bad Value" + (lineNb != -1 ? " at line " + std::to_string(lineNb) : ""));
        if (instruction.type == eOperandType::NULLTYPE)
            throw std::runtime_error("Error : Bad types" + (lineNb != -1 ? " at line " + std::to_string(lineNb) : ""));
    }

    return instruction;
}

void IOInterface::display(std::string output) {
    std::cout << output;
}
