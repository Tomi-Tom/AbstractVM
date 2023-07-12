/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** IOperand.hpp
*/

#ifndef IOPERAND_HPP_
	#define IOPERAND_HPP_

#include <string>
#include "eOperandType.hpp"

class IOperand {
    public :
        virtual std::string toString() const = 0; // string that represents the instance

        virtual eOperandType getType() const = 0; // returns the types of instance

        virtual IOperand *operator+(const IOperand &rhs) const = 0; // sum
        virtual IOperand *operator-(const IOperand &rhs) const = 0; // difference
        virtual IOperand *operator*(const IOperand &rhs) const = 0; // product
        virtual IOperand *operator/(const IOperand &rhs) const = 0; // quotient
        virtual IOperand *operator%(const IOperand &rhs) const = 0; // modulo

        virtual ~IOperand() {};
};

#endif /*IOPERAND_HPP_*/
