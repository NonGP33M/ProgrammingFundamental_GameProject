#include "ItemDrop.h"

ItemDrop::ItemDrop(int type, int wave, sf::Vector2f enemyPos)
{	
	drop.setRadius(15);
	if(type == 1)
		drop.setFillColor(sf::Color::Black);
	if(type == 2)
		drop.setFillColor(sf::Color::White);
	drop.setPosition(enemyPos);
	weaponType = type;
}

void ItemDrop::render(sf::RenderTarget& other)
{
	other.draw(drop);
}
