#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace sf;
using namespace std;

class Game
{
	int height, width;
public:
	Game();
	void DisplayInfo();
	int getheight();
	int getwidth();
};

