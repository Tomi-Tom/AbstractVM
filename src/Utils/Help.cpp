/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** Help.cpp
*/

#include <iostream>

int help()
{
    std::cout << "USAGE: ./abstractVM [FILE]" << std::endl << std::endl;
    std::cout << "\tFILE\t- file that contains the instructions" << std::endl;
    std::cout << "\t\t- If no file is passed, the program will read from the standard input." << std::endl << std::endl;
    std::cout << "\t\t- If the argument '--live' is passed, the program will read and live exec from the standard input" << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl << std::endl;
    std::cout << "INSTRUCTIONS:" << std::endl << std::endl;
    std::cout << "\tpush\t-\tPushes the value at the top of the stack." << std::endl;
    std::cout << "\tpop\t-\tUnstacks the value from the top of the stack." << std::endl;
    std::cout << "\tdump\t-\tDisplays each value of the stack." << std::endl;
    std::cout << "\tclear\t-\tClears the stack." << std::endl;
    std::cout << "\tdup\t-\tDuplicates the value at the top of the stack." << std::endl;
    std::cout << "\tswap\t-\tSwaps the two values at the top of the stack." << std::endl;
    std::cout << "\tassert\t-\tAsserts that the value at the top of the stack is equal to the one passed as" << std::endl;
    std::cout << "\t\t\tparameter for this instruction." << std::endl;
    std::cout << "\tadd\t-\tUnstacks the first two values on the stack, adds them together and stacks the result." << std::endl;
    std::cout << "\tsub\t-\tUnstacks the first two values on the stack, subtracts them, then stacks the result." << std::endl;
    std::cout << "\tmul\t-\tUnstacks the first two values on the stack, multiplies them, then stacks the result." << std::endl;
    std::cout << "\tdiv\t-\tUnstacks the first two values on the stack, divides them, then stacks the result." << std::endl;
    std::cout << "\tmod\t-\tUnstacks the first two values on the stack, calculates the modulus, then stacks the result." << std::endl;
    std::cout << "\tprint\t-\tAsserts that the value at the top of the stack is an 8-bit integer, then interprets" << std::endl;
    std::cout << "\t\t\tit as an ASCII value and displays the corresponding character on the standard output." << std::endl;
    std::cout << "\texit\t-\tTerminates the execution of the current program." << std::endl << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    return 0;
}