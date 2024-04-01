#pragma once
#include"Game.h"
const int MAX = 3;
class Textures
{
public:
	Texture  background1, background2, gameover, win, texture;
	Sprite spGameover, spwin, spBackground2, spritee;
	void loadTextures();

	int selectedItemIndex = 0;
	Font font;
	Text menu[MAX];
	void setMainMenu(float width, float height);
	void draw(RenderWindow& window);
	void Moveup();
	void MoveDown();
	int getPressedItem();
};
