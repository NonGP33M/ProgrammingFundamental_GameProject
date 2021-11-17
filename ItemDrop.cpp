#include "ItemDrop.h"

ItemDrop::ItemDrop(int wave, sf::Vector2f enemyPos)
{
	drop.setSize({ 64.f ,64.f });
	currentFrame = { 0,0,16,16 };
	drop.setTextureRect(currentFrame);
	
	drop.setPosition(enemyPos);
	weaponType = rand() % 2 + 1;
	if (weaponType == 1)
	{
		damage = 2 * wave + (rand() % 5);
		texture.loadFromFile("Texture/Sprite/Sword.png");
		
	}
	else if (weaponType == 2)
	{
		damage = 4 * wave + (rand() % 5);
		drop.setFillColor(sf::Color::White);
		texture.loadFromFile("Texture/Sprite/Hammer.png");
	}
	drop.setTexture(&texture);
}

void ItemDrop::warning()
{
	if (timer.getElapsedTime().asSeconds() > 10 &&
		static_cast<int>(timer.getElapsedTime().asMilliseconds()) % 500 < 250 )
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

void ItemDrop::render(sf::RenderTarget& other)
{
	warning();
	animation();
	if(showing)
		other.draw(drop);
}
