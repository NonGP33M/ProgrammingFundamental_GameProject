#include "WeaponHitbox.h"

WeaponHitbox::WeaponHitbox()
{
	Hitbox.setFillColor(sf::Color::Transparent);
	Hitbox.setOutlineThickness(1.f);
	Hitbox.setOutlineColor(sf::Color::Green);
}

void WeaponHitbox::setHitbox(float posX, float posY, int type)
{
	if (type == 0)
		size = 1000.f;
	else if (type == 1)
		size = 100.f;
	else if (type == 2)
		size = 200.f;

	Hitbox.setSize({ size,size });
	Hitbox.setOrigin({ size / 2,size / 2 });
	Hitbox.setPosition(posX - 8, posY - 8);
}

void WeaponHitbox::render(sf::RenderTarget& other)
{
	other.draw(Hitbox);
}
