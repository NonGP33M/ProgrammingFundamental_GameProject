#include "WeaponHitbox.h"

WeaponHitbox::WeaponHitbox()
{
	Hitbox.setFillColor(sf::Color::Transparent);
	Hitbox.setOutlineThickness(1.f);
	Hitbox.setOutlineColor(sf::Color::Green);
}

void WeaponHitbox::setHitbox(float posX, float posY, int type, int state)
{
	if (type == 0)
	{
		range = 0.f;
		width = 0.f;
	}
	else if (type == 1)
	{
		range = 75.f;
		width = 100.f;
	}
	else if (type == 2)
	{
		range = 150.f;
		width = 175.f;
	}

	if (state == 1)
	{
		Hitbox.setSize({ range,width });
		Hitbox.setOrigin({ Hitbox.getLocalBounds().width / 2 , Hitbox.getLocalBounds().height /2 });
		Hitbox.setPosition(posX - 8 - 75, posY - 8);
	}
	if (state == 2)
	{
		Hitbox.setSize({ range,width });
		Hitbox.setOrigin({ Hitbox.getLocalBounds().width / 2 , Hitbox.getLocalBounds().height / 2 });
		Hitbox.setPosition(posX - 8 + 75, posY - 8);
	}
	if (state == 3)
	{
		Hitbox.setSize({ width, range });
		Hitbox.setOrigin({ Hitbox.getLocalBounds().width / 2 , Hitbox.getLocalBounds().height / 2 });
		Hitbox.setPosition(posX - 8, posY - 8 - 75);
	}
	if (state == 4)
	{
		Hitbox.setSize({ width, range });
		Hitbox.setOrigin({ Hitbox.getLocalBounds().width / 2 , Hitbox.getLocalBounds().height / 2 });
		Hitbox.setPosition(posX - 8, posY - 8 + 75);
	}
}

void WeaponHitbox::render(sf::RenderTarget& other)
{
	other.draw(Hitbox);
}
