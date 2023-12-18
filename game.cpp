// Game program
// Kaila Anderson
// 11/06/2022

#include <iostream>
#include "maze.hpp"

using std::endl; using std::cin; using std::cout; 

int main() {

	Maze MyMaze; 
	Room CheeseRoom;
	CheeseRoom.makeCheeseRoom(); 

	MyMaze.build(); 
	cout << "Before starting the maze game, would you like to see " 
		 <<  "the locations of the internal walls ? : (y if yes, n if no) : " << endl; 
	char choice;
	cin >> choice; 

	if (choice == 'y' || choice == 'Y') {
		MyMaze.print();
		cout << endl << "Let's Start!" << endl;
	}
	else
		cout << endl << "Let's Start!" << endl; 

	MyMaze.start(); 
	Room Current; 
	Current = MyMaze.getCurrentRoom(); 


	do {
		Current = MyMaze.getCurrentRoom(); 
		cout << "This is your location: "; 
		Current.print(); 
		cout << endl; 

		Room NewLoc = Current.nextMove(); 
		if (matchRoom(NewLoc, Current) == false) {
			RoomPair Move = { NewLoc, Current };
			if (MyMaze.move(NewLoc) == true) {
				cout << "Your move was successful" << endl;
			}
			else { cout << "There is a wall. Try again" << endl; }
		}
	} while (matchRoom(Current, CheeseRoom) == false);
		
	cout << "The Game Has Ended, thank you for playing!" << endl; 


}