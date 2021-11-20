#include "ItemDrop.h"

ItemDrop::ItemDrop(int type, int dmg, bool playerDrop, sf::Vector2f pos)
{
	drop.setSize({ 64.f ,64.f });
	currentFrame = { 0,0,16,16 };
	drop.setTextureRect(currentFrame);

	drop.setPosition(pos);

	//ENEMIES DROP
	if (!playerDrop)
	{
		weaponType = rand() % 2 + 1;
		if (weaponType == 1)
		{
			damage = dmg + (rand() % 7 + 1);
			texture.loadFromFile("Texture/Sword.png");

		}
		else if (weaponType == 2)
		{
			damage = dmg + (rand() % 7 + 1 );
			texture.loadFromFile("Texture/Hammer.png");
		}
	}
	//PLAYER DROP
	else
	{
		if (type == 1)
		{
			damage = dmg;
			texture.loadFromFile("Texture/Sword.png");
			weaponType = 1;
		}
		else if (type == 2)
		{
			damage = dmg;
			texture.loadFromFile("Texture/Hammer.png");
			weaponType = 2;
		}
		else
		{
			drop.setSize({ 0, 0 });
			weaponType = 0;
			damage = 0;
		}
	}
	drop.setTexture(&texture);
}

void ItemDrop::warning()
{
	if (timer.getElapsedTime().asSeconds() > 10 &&
		static_cast<int>(timer.getElapsedTime().asMilliseconds()) % 500 < 250)
	{
		showing = false;
	}
	else if (timer.getElapsedTime().asSeconds() > 10 &&
		static_cast<int>(timer.getElapsedTime().asMilliseconds()) % 500 >= 250)
	{
		showing = true;
	}
}

void ItemDrop::animation()
{
	if (weaponType == 1)
	{
		if (animClock.getElapsedTime().asSeconds() >= 0.2f)
		{
			currentFrame.left += 16;
			if (currentFrame.left >= 128)
			{
				if (currentFrame.top < 48)
					currentFrame.top += 16;
				else
					currentFrame.top = 0;
				currentFrame.left = 0;
			}

			drop.setTextureRect(currentFrame);
			animClock.restart();
		}
	}
	else if (weaponType == 2)
	{
		if (animClock.getElapsedTime().asSeconds() >= 0.2f)
		{
			currentFrame.left += 16;
			if (currentFrame.left >= 128)
			{
				if (currentFrame.top < 48)
					currentFrame.top += 16;
				else
					currentFrame.top = 0;
				currentFrame.left = 0;
			}

			drop.setTextureRect(currentFrame);
			animClock.restart();
		}
	}
}

void ItemDrop::update()
{
	warning();
	animation();
}

void ItemDrop::render(sf::RenderTarget& other)
{
	if (showing)
		other.draw(drop);
}
