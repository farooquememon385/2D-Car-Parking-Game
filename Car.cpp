#include "Car.h"

void Car::loadTex()
{
	Textures tx;
	car1.loadFromFile("Texture/car1.PNG");
	spcar1.setTexture(car1);
	spcar1.setScale(0.8, 0.8);
	spcar1.setOrigin(Vector2f(spcar1.getTexture()->getSize().x * 0.5, spcar1.getTexture()->getSize().y * 0.5));
}	