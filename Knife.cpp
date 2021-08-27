#include "Knife.h"

Knife::Knife()
{
	KnifeBox.setOrigin(sf::Vector2f(10.f, 10.f));
	KnifeBox.setSize(sf::Vector2f(100.f, 100.f));
	KnifeBox.setFillColor(sf::Color::Transparent);
	KnifeBox.setOutlineThickness(1.f);
	KnifeBox.setOutlineColor(sf::Color::Green);
}

void Knife::setPosition(float posX, float posY)
{
	KnifeBox.setPosition(posX, posY);
}

void Knife::render(sf::RenderTarget& other)
{
	other.draw(KnifeBox);
}
