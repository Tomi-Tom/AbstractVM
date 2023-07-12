/*
** EPITECH PROJECT, 2023
** AbstractVM
** File description:
** MyInt8.hpp
*/

#ifndef MYINT8_HPP_
	#define MYINT8_HPP_

#include <string>
#include "IOperand.hpp"

class MyInt8 : public IOperand {
	public:
		MyInt8(const std::string &value);
		~MyInt8() override {};

    std::string toString() const override;

    eOperandType getType() const override;

    IOperand *operator+(const IOperand &rhs) const override;
    IOperand *operator-(const IOperand &rhs) const override;
    IOperand *operator*(const IOperand &rhs) const override;
    IOperand *operator/(const IOperand &rhs) const override;
    IOperand *operator%(const IOperand &rhs) const override;

private:
    __int8_t _value;
};

#endif /*MYINT8_HPP_*/
