#include "Game.h"

Game::Game()
{
	height = 480;
	width = 640;
}

void Game::DisplayInfo()
{
	printf("******************************************************************************\n");
	printf("******************************************************************************\n");
	printf("******************************************************************************\n");
	printf("\nINSTRUCTION ABOUT GAMES\n");
	printf("\n**********************************************\n");
	printf("\nTHIS CAR GAME CONSIST OF 2 LEVELS WIN THE LEVEL ONE TO GET ACCESS TO THE LEVEL 2 \nWHERE YOU CAN DRIVE CAR WITHOUT ANY BOUNDS\n");
	printf("You can quit the game any time by pressing escape button\n");
	printf("REACH THE GREEN MARK TO WIN THE LEVEL ONE\n");
	printf("******************************************************************************\n");
	printf("******************************************************************************\n");
	printf("Press \"R\" key to restart the level if you get out\n");
	printf("Function of different keys are as follow\n");
	printf("******************************************************************************\n");
	printf("******************************************************************************\n\n");
	printf(" Escape                 =      exiting\n arrow keys             =      movement\n Restart level          =      Restart \n");

}

int Game::getheight()
{
	return height;
}

int Game::getwidth()
{
	return width;
}

