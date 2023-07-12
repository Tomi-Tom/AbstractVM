/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** ErrorHandling.cpp
*/

#include <fstream>
#include <iostream>

int checkFile(std::string file) {
    std::ifstream f(file);

    if (file == "--live")
        return 0;
    if (file.substr(file.find_last_of(".") + 1) != "avm") {
        std::cerr << "Error: File must be a .avm" << std::endl;
        return 84;
    }
    if (!f.good()) {
        std::cerr << "Error: File not found" << std::endl;
        return 84;
    }
    return 0;
}

int errorHandling(int ac, char **av) {
    if (ac == 1)
        return 0;
    if (ac > 2)
        return 84;
    return checkFile(av[1]);
}