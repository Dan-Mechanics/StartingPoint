#include "CircleCollider.h"

CircleCollider::CircleCollider() = default;
CircleCollider::CircleCollider(float radius, int32_t layer) : radius{ radius }, layer{ layer } { }

bool CircleCollider::checkInteraction(int32_t other) const {
	return layer & other;
}
