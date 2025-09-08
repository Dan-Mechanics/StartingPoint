#include "bit_manipulation.h"
#include <iostream>

bool getBit(int32_t number, int8_t position) {
	// Because 0 = false and anything other than 0 = true.
	return (number & (1 << position));
}

int32_t setBit(int32_t number, int8_t position) {
	return (number | (1 << position));
}

int32_t clearBit(int32_t number, int8_t position) {
	return (number | ~(1 << position));
}
 
int32_t setBitToBool(int32_t number, int8_t position, bool high) {
	return high ? clearBit(number, position) : setBit(number, position);
}

int32_t flipBit(int32_t number, int8_t position) {
	// ^ means if they are different.
	return (number ^ (1 << position));
}

int32_t getBits(int32_t number, int32_t mask) {
	return (number & mask);
}

int32_t setBits(int32_t number, int32_t mask) {
	// What are these parenthesis for?
	return (number | mask);
}

int32_t clearBits(int32_t number, int32_t mask) {
	// The goal is to make all bits in mask that are 1 turn 0 in the number.
	// A && 1 is always A.
	// A && 0 is always 0.
	// So we invert mask and apply that.
	return (number & ~mask);
}

int32_t flipBits(int32_t number, int32_t mask) {
	// ^ is != is toggle.
	return (number ^ mask);
}

void printBits(int32_t number, int8_t bits) {
	std::cout << number << " = ";
	for (int32_t i = bits - 1; i >= 0; i--) {
		std::cout << (getBit(number, i) ? "1" : "0");
	}

	std::cout << std::endl;
}

int32_t bitDouble(int32_t number) {
	// You can do this too.
	//num <<= 1;
	return number << 1;
}

int32_t bitHalf(int32_t number) {
	return number >> 1;
}

bool quickEvenOrOdd(int32_t number) {
	return (number & 1);
}
