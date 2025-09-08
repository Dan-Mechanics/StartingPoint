// https://youtu.be/vqpfrSIyojo?si=JfCw0D9cfXTpvuHo

#pragma once
#include <cstdint>

/// <summary>
/// Returns the state of a single bit.
/// </summary>
bool getBit(int32_t number, int8_t position);

/// <summary>
/// Sets a single bit in the number ( make true ).
/// </summary>
int32_t setBit(int32_t number, int8_t position);

/// <summary>
/// Clears a single bit in the number ( make false ).
/// </summary>
int32_t clearBit(int32_t number, int8_t position);

/// <summary>
/// For ease.
/// </summary>
int32_t setBitToBool(int32_t number, int8_t position, bool b);

/// <summary>
/// Toggle that bit.
/// XOR.
/// </summary>
int32_t flipBit(int32_t number, int8_t position);

/// <summary>
/// Extract out using mask. Apply the mask.
/// </summary>
int32_t getBits(int32_t number, int32_t mask);

/// <summary>
/// Add two masks together.
/// </summary>
int32_t setBits(int32_t number, int32_t mask);

/// <summary>
/// Remove a mask from a mask.
/// </summary>
int32_t clearBits(int32_t number, int32_t mask);

/// <summary>
/// Flip with mask.
/// </summary>
int32_t flipBits(int32_t number, int32_t mask);

/// <summary>
/// For debug.
/// </summary>
void printBits(int32_t number, int8_t bits);

int32_t bitDouble(int32_t number);

int32_t bitHalf(int32_t number);

bool quickEvenOrOdd(int32_t number);