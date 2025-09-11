#pragma once
#include "App.h"
#include <cstdint>

class Directions : public App {
public:
	Directions();

	virtual int run() const override;

private:
	void printDirection(int8_t direction) const;
};