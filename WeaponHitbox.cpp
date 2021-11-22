#include "WeaponHitbox.h"

WeaponHitbox::WeaponHitbox()
{
	Hitbox.setFillColor(sf::Color::Transparent);
	Hitbox.setOutlineThickness(1.f);
	Hitbox.setOutlineColor(sf::Color::Blue);
}

void WeaponHitbox::setHitbox(float posX, float posY, int type, int state, bool isMoving)
{
	if (type == 0)
	{
		range = 0.f;
		width = 0.f;
	}
	else if (type == 1)
	{
		range = 120.f;
		width = 190.f;
	}
	else if (type == 2)
	{
		range = 120.f;
		width = 190.f;
	}

	if (state == 0)
	{
		Hitbox.setSize({ range,width });
		Hitbox.setOrigin({ Hitbox.getLocalBounds().width / 2 , Hitbox.getLocalBounds().height / 2 });
		Hitbox.setPosition(posX - Hitbox.getSize().x/2, posY);
	}
	else if (state == 1)
	{
		Hitbox.setSize({ range,width });
		Hitbox.setOrigin({ Hitbox.getLocalBounds().width / 2 , Hitbox.getLocalBounds().height / 2 });
		Hitbox.setPosition(posX + Hitbox.getSize().x/2, posY);
	}
	else if (state == 2)
	{
		Hitbox.setSize({ width, range });
		Hitbox.setOrigin({ Hitbox.getLocalBounds().width / 2 , Hitbox.getLocalBounds().height / 2 });
		Hitbox.setPosition(posX, posY - Hitbox.getSize().y/2);
	}
	else if (state == 3)
	{
		Hitbox.setSize({ width, range });
		Hitbox.setOrigin({ Hitbox.getLocalBounds().width / 2 , Hitbox.getLocalBounds().height / 2 });
		Hitbox.setPosition(posX, posY + Hitbox.getSize().y/2);
	}
}

void WeaponHitbox::render(sf::RenderTarget& other)
{
	//other.draw(Hitbox);
}
