#pragma once
#include "App.h"
#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics.hpp>
class BlackScreen : public App {
public:
	BlackScreen();

	virtual int run() const override;
};

