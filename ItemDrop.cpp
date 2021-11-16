#include "ItemDrop.h"

ItemDrop::ItemDrop(int type, int wave, sf::Vector2f enemyPos)
{
	drop.setRadius(15);
	if (type == 0)
		drop.setFillColor(sf::Color::Black);
	if (type == 1)
		drop.setFillColor(sf::Color::White);
	drop.setPosition(enemyPos);
	weaponType = type + 1;
	if (weaponType == 1)
		damage = 2 * wave + (rand() % 5);
	else if (weaponType == 2)
		damage = 4 * wave + (rand() % 5);
}

void ItemDrop::render(sf::RenderTarget& other)
{
	other.draw(drop);
}
