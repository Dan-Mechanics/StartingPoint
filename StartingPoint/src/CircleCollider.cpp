#include "CircleCollider.h"
#include <iostream>

CircleCollider::CircleCollider() = default;
CircleCollider::CircleCollider(float radius, int32_t layer) : radius{ radius }, layer{ layer } { }

bool CircleCollider::checkInteraction(int32_t other) const {
	return layer & other;
}

void CircleCollider::test() {
    const CircleCollider groundCircle{ 0.5f, Layer::GROUND };
    const CircleCollider triggerCircle{ 0.5f, Layer::TRIGGER };

    // Something can be both.
    const CircleCollider mixedCircle{ 0.5f, Layer::GROUND | Layer::WATER };

    std::cout << (groundCircle.checkInteraction(triggerCircle.layer) ? "True" : "False") << std::endl;
    std::cout << (groundCircle.checkInteraction(mixedCircle.layer) ? "True" : "False") << std::endl;
}