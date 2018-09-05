#include <iostream>
#include "GameWorld.h"
using namespace std;

int main()
{
	//hold choice
	char choice;

NEWGAME:

	//display the menu for navigation of game
	cout << "WELCOME TO THE WUMPUS GAME\n";
	cout << "__________________________\n\n";

	cout << "Press 'A' to turn left\n";
	cout << "Press 'D' to turn right\n";
	cout << "Press 'W' to move forward\n";
	cout << "Press 'C' to be a cheater\n";
	cout << "Press 'Q' to end the game\n";
	cout << "Press 'R' to restart\n";
	cout << "__________________________\n\n";

	//instance of GameWorld
	GameWorld objbegin;

	//display compass directions one
	//space from the player location
	objbegin.displayVisibleWorld();

CHOOSE:
	cin >> choice;

	switch(choice)
	{
		//turn left
		case 'a':
		case 'A': objbegin.turnLeft();
			      objbegin.displayVisibleWorld();
				  objbegin.haveIWon();
				  objbegin.amIAlive();
			goto CHOOSE;
		//turn right
		case 'd':
		case 'D': objbegin.turnRight();
				  objbegin.displayVisibleWorld();
				  objbegin.haveIWon();
				  objbegin.amIAlive();
			goto CHOOSE;
		//forward
		case 'w':
		case 'W':
				  objbegin.moveForward();
				  objbegin.displayVisibleWorld();
				  objbegin.haveIWon();
				  objbegin.amIAlive();
			goto CHOOSE;
		//backward
		case 'z':
		case 'Z': objbegin.moveBackward();
			      objbegin.displayVisibleWorld();
				  objbegin.haveIWon();
				  objbegin.amIAlive();
			goto CHOOSE;
		//cheater
		case 'c': 
		case 'C': objbegin.displayEntireWorld();
			goto CHOOSE;
		//restart
		case 'r':
		case 'R':
			goto NEWGAME;
		//end game
		case 'q':
		case 'Q': cout << "Bye!"; 
			exit(0);
			break;
		//invalid
		default: cout << "Invalid entry, use letters ";
				 cout << "listed in the menu only" << endl;
			goto CHOOSE;
	}



system("pause");
return 0;
}