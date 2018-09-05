//the include guard
#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#define ROWS 5
#define COLS 5

class GameWorld
{
	private:
		char playingfield[7][7];

		int wumpusX;
		int wumpusY;

		int treasureX;
		int treasureY;
		
		int playerX;
		int playerY;

		bool dead = false;

	public:
	//constructor
	GameWorld()
	{
			//seed the random number
			srand(time(NULL));
			
			char player = 'N';
			char wumpus = 'W';
			char gold = 'G';
			char space = ' ';
			char pit = 'P';


	//initialize array to blankspace
	for(int x = 0; x < 7; ++x) 
	{	
		for(int y = 0; y < 7; ++y)
		{
			playingfield[x][y] = space;
		}	
	}

		//iterate through rows of the 2d-array
		for(int x = rand() % 5; x < ROWS; x++) 
		{
		//iterate through columns of 2d-array
		for(int y = rand() % 5; y < COLS; y++) 
		{
			//place a wumpus, randomly, on map
			playingfield[x][y] = wumpus;
		
				//hold wumpus coordinates
				wumpusX = x;
				wumpusY = y;
		break;
		}
		break;
		}

		//iterate through rows of the 2d-array
		for(int x = rand() % 5; x < ROWS; x++)
		{
		//iterate through columns of 2d-array
		for(int y = rand() % 5; y < COLS; y++)
		{
			//place the gold, randomly, on map
			playingfield[x][y] = gold;

				//if gold is on a wumpus, move gold
				if(playingfield[x][y] == wumpus)
				{
					(x + 1) % 5;
					(y + 1) % 5;
				}
				//hold treasure coordinates
				treasureX = x;
				treasureY = y;
		break;
		}
		break;
		}
		
				//iterate through rows of the 2d-array
				for(int x = rand() % 5; x < ROWS; x++)
				{
				//iterate through columns of 2d-array
				for(int y = rand() % 5; y < COLS; y++)
				{
				//place the player, randomly, on map
				playingfield[x][y] = player;
		
					//if player is on wumpus, move player
					if(playingfield[x][y] == wumpus)
					{
						(x + 1) % 5;
					}
					//if player is on gold, move player
					else if(playingfield[x][y] == gold)
					{
						(x + 1) % 5;
						(y + 1) % 5;
					}
					//hold player coordinates
					playerX = x;
					playerY = y;
				break;
				}
				break;
				}

	//store pits
	int pitfalls;
	//randomize the instances of pits on map
	pitfalls = (rand() % 6) + 5;

	//hold count
	int z = 0;

	//loop through pits
	while (z < pitfalls)
	{

		//(x) is randomized
		int x = rand() % 5;

		//(y) is randomized
		int y = rand() % 5;

		if ((playingfield[x][y] != pit) &&
			(playingfield[x][y] != playingfield[playerX][playerY]) &&
			(playingfield[x][y] != playingfield[wumpusX][wumpusY]) &&
			(playingfield[x][y] != playingfield[treasureX][treasureY]))
		{
			//a 'P' is dropped on (x,y)
			playingfield[x][y] = pit;

			//que next
			z++;
		}
	}
}


//display the state of game to screen
void displayEntireWorld();
				
//display squares contiguous to player
void displayVisibleWorld();
			
//move forward in the facing direction 
void moveForward();

//move backward in the facing direction 
void moveBackward();
			
//turn player 90 degrees to the left
void turnLeft();

//turn player 90 degrees to the right
void turnRight();
			
//return true or false if player won
void haveIWon();
			
//return true or false if player dead
bool amIAlive();

};

#endif