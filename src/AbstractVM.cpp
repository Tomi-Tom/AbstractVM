/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** AbstractVM.cpp
*/

#include <optional>
#include <string>
#include "VirtualMachine.hpp"

int abstractVM(std::optional<std::string> file) {
    try {
        VirtualMachine vm;

        if (file == "--live") {
            vm.run();
        } else if (file == std::nullopt) {
            vm.run("");
        } else {
            vm.run(file.value());
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return EXIT_SUCCESS;
}