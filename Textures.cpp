#pragma warning(disable:4996)
#include "Textures.h"
void Textures::loadTextures()
{
	if (!gameover.loadFromFile("Texture/gg.jpg"))
		printf("Error loading gameover image");
	spGameover.setTexture(gameover);
	spGameover.setScale(Vector2f(0.6, 0.65));
	if (!win.loadFromFile("Texture/win.jpg"))
		printf("Error loading win image");
	spwin.setTexture(win);
	if (!background2.loadFromFile("Texture/background2.png"))
		printf("Error loading bacjground image");
	spBackground2.setTexture(background2);
	if (!texture.loadFromFile("Texture/cargame.jpg"))
		printf("Error loading gameover image");
	spritee.setTexture(texture);
}

void Textures::setMainMenu(float width, float height)
{
	if (!font.loadFromFile("Times-New-Romance.ttf"))
	{
		//ERROR DETECTION 
	}
	menu[0].setFont(font);
	menu[0].setColor(Color::Blue);
	menu[0].setString("--PLAY--");
	menu[0].setPosition(Vector2f((width - 15 * strlen("--PLAY--")) / 2, height / (MAX + 1) * 1));

	menu[1].setFont(font);
	menu[1].setColor(Color::White);
	menu[1].setString("--HELP--");
	menu[1].setPosition(Vector2f((width - 15 * strlen("--ABOUT--")) / 2, height / (MAX + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(Color::White);
	menu[2].setString("--EXIT--");
	menu[2].setPosition(Vector2f((width - 15 * strlen("--EXIT--")) / 2, height / (MAX + 1) * 3));

}

void Textures::draw(RenderWindow& window)
{
	for (int i = 0; i < MAX; i++)
	{
		window.draw(menu[i]);
	}

}

void Textures::Moveup()
{
	menu[selectedItemIndex].setColor(Color::White);
	selectedItemIndex--;
	menu[selectedItemIndex].setColor(Color::Blue);

}

void Textures::MoveDown()
{
	if (selectedItemIndex + 1 < MAX)
	{
		menu[selectedItemIndex].setColor(Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(Color::Blue);
	}

}

int Textures::getPressedItem()
{
	return selectedItemIndex;
	return 0;
}
