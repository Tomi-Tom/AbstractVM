/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** Main.cpp
*/

#include <optional>
#include <string>
#include "Utils.hpp"

int main(int ac, char **av)
{
    if (ac == 2 && std::string(av[1]) == "-h")
        return help();

    if (errorHandling(ac, av) == 84)
        return 84;

    return abstractVM(ac == 2 ? std::optional<std::string>(av[1]) : std::nullopt);
}