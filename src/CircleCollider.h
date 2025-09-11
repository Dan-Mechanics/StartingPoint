#pragma once
#include <cstdint>

enum Layer {
	GROUND = 0,
	WATER = 1,
	TRIGGER = 2
};

class CircleCollider {
public:
	CircleCollider();
	CircleCollider(float radius, int32_t layer);
	
	float radius{};
	int32_t layer{};
	
	/// <summary>
	/// Check if there are any commonalities whatsoever.
	/// </summary>
	bool checkInteraction(int32_t other) const;
	static void test();
};