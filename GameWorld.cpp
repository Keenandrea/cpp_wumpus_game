//implementation file
#include "GameWorld.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ROWS 5
#define COLS 5

//===========================================//
//===========================================//
void GameWorld::displayEntireWorld()
{
for(int x = 0; x < ROWS; ++x) 
{
	for(int y = 0; y < COLS; ++y) 
	{
		cout << playingfield[x][y];
		cout << "|";
	}
	cout << "\n";
	}
}
//===========================================//
//===========================================//


//===========================================//
//===========================================//
void GameWorld::displayVisibleWorld()
{
//iterate through the rows
for(int x = 0; x < ROWS; x++) 
{
	//iterate through the cols
	for(int y = 0; y < COLS; y++) 
	{

		//if an iteration is equal to the player's coordinates
		if((x == playerX && y == playerY) 
		//if an iteration is equal to the player's compass values
		|| (x == playerX - 1 && y == playerY)
		|| (x == playerX && y == playerY - 1)
		|| (x == playerX && y == playerY + 1)
		|| (x == playerX + 1 && y == playerY))
			{ 
			cout << playingfield[x][y];
			}
			else
				{
				cout << " ";
				}
		cout << "|";
	}
	cout << "\n";	
}

}
//===========================================//
//===========================================//


//===========================================//
//===========================================//
void GameWorld::moveForward()
{
	char erase = ' ';
	char newPos = 'N';

	//bounds checking
	if(playerX <= 0)
	{
		cout << "I'm afraid you've reached ";
		cout << "ends of the wumpus world, ";
		cout << "move south to stay in bounds";
		cout << endl;
	}

	//if the player moves forward and lands on a space or the gold, they live
	if((playingfield[playerX - 1][playerY] == ' ') 
	|| (playingfield[playerX - 1][playerY] == playingfield[treasureX][treasureY]))
	{
		dead = false;
	}
	//if the player moves forward and does not land on space or gold, they die
	else if((playingfield[playerX - 1][playerY] != ' ')
	|| (playingfield[playerX - 1][playerY] != playingfield[treasureX][treasureY]))
	{
		dead = true;
		cout << "Whoopsie daisy! You've died\n\n";
		cout << "Press 'R' to re-try\n";
		system("pause");
	}

	//move player char up one space and output
	playingfield[playerX - 1][playerY] = newPos;
	//erase player char from the former space
	playingfield[playerX][playerY] = erase;
	//int move
	playerX--;
	
	//give space
	cout << endl;
}
//===========================================//
//===========================================//


//===========================================//
//===========================================//
void GameWorld::moveBackward()
{
	char erase = ' ';
	char newPos = 'S';

	
	//bounds checking
	if(playerX >= 4)
	{
		cout << "I'm afraid you've reached ";
		cout << "ends of the wumpus world, ";
		cout << "move north to stay in bounds";
		cout << endl;
	}
	
	//if the player moves backward and lands on a space or the gold, they live
	if((playingfield[playerX + 1][playerY] == ' ') 
	|| (playingfield[playerX + 1][playerY] == playingfield[treasureX][treasureY]))
	{
		dead = false;
	}
	//if the player moves backward and does not land on space of gold, they die
	else if((playingfield[playerX + 1][playerY] != ' ')
	|| (playingfield[playerX + 1][playerY] != playingfield[treasureX][treasureY]))
	{
	dead = true;
	cout << "Whoopsie daisy! You've died\n\n";
	cout << "Press 'R' to re-try\n";
	system("pause");
	}

	//move player char up one space and output
	playingfield[playerX + 1][playerY] = newPos;
	//erase player char from the former space
	playingfield[playerX][playerY] = erase;
	//int move
	playerX++;

	//give space
	cout << endl;
}
//===========================================//
//===========================================//


//===========================================//
//===========================================//
void GameWorld::turnLeft()
{

	char erase = ' ';
	char newPos = '<';

	//bounds checking
	if(playerY <= 0)
	{
		cout << "I'm afraid you've reached ";
		cout << "ends of the wumpus world, ";
		cout << "move right to stay in bounds";
		cout << endl;
	}

	//if the player moves left and lands on a space or the gold, they live
	if((playingfield[playerX][playerY - 1] == ' ') 
	|| (playingfield[playerX][playerY - 1] == playingfield[treasureX][treasureY]))
	{
		dead = false;
	}
	//if the player moves left and does not land on space of gold, they die
	else if((playingfield[playerX][playerY - 1] != ' ')
	|| (playingfield[playerX][playerY - 1] != playingfield[treasureX][treasureY]))
	{
	dead = true;
	cout << "Whoopsie daisy! You've died\n\n";
	cout << "Press 'R' to re-try\n";
	system("pause");
	}

	//move player char up one space and output
	playingfield[playerX][playerY - 1] = newPos;
	//erase player char from the former space
	playingfield[playerX][playerY] = erase;
	//int move
	playerY--;

	//give space
	cout << endl;	
}
//===========================================//
//===========================================//


//===========================================//
//===========================================//
void GameWorld::turnRight()
{

	char erase = ' ';
	char newPos = '>';

	//bounds checking
	if(playerY >= 4)
	{
		cout << "I'm afraid you've reached ";
		cout << "ends of the wumpus world, ";
		cout << "move left to stay in bounds";
		cout << endl;
	}

	//if the player moves right and lands on a space or the gold, they live
	if((playingfield[playerX][playerY + 1] == ' ') 
	|| (playingfield[playerX][playerY + 1] == playingfield[treasureX][treasureY]))
	{
		dead = false;
	}
	//if the player moves right and does not land on space of gold, they die
	else if((playingfield[playerX][playerY + 1] != ' ')
	|| (playingfield[playerX][playerY + 1] != playingfield[treasureX][treasureY]))
	{
	dead = true;
	cout << "Whoopsie daisy! You've died\n\n";
	cout << "Press 'R' to re-try\n";
	system("pause");
	}

	//move player char up one space and output
	playingfield[playerX][playerY + 1] = newPos;
	//erase player char from the former space
	playingfield[playerX][playerY] = erase;
	//int move
	playerY++;

	//give space
	cout << endl;
}
//===========================================//
//===========================================//


//===========================================//
//===========================================//
void GameWorld::haveIWon()
{
	//if player lands on gold coordinates
	if(playingfield[playerX][playerY] == 
	playingfield[treasureX][treasureY])
	{ 
	//terminate program with the quit key
	cout << "Yipee! You can retire early!";
	cout << "\n\nPress 'Q' to quit the game";
	cout << "\nPress 'R' to reboot the map";
	cout << endl << endl << endl << endl;
	}
}
//===========================================//
//===========================================//


//===========================================//
//===========================================//
bool GameWorld::amIAlive()
{return dead;}
//===========================================//
//===========================================//