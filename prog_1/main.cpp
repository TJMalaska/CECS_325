// Name: Theodore Malaska
// Class (CECS 325-01)
// Project Name (Prog 1 – War)
// Due Date (09/18/2024)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <string>
int main()
{	
	std::string Player1;
	std::string Player2;
	int scoreP1 = 0;
	int scoreP2 = 0;

	std::cout << "Enter the name of the first player: ";
	std::cin >> Player1;
	std::cout << "\nEnter the name of the second player: ";
	std::cin >> Player2;
	std::cout << "\n	Original Deck\n\n";

	Deck myDeck = Deck();	
	myDeck.print();

	std::cout << "\n	Shuffled Deck\n\n";
	myDeck.shuffle();
	myDeck.print();

	//Game start
	for(int i = 0; i < 26; i++){

		std::cout << "Game " << i + 1 << "\n--------\n";
		std::cout << Player1 << "=>";
		myDeck.pile[2*i].print();
		std::cout << "\n" << Player2 << "=>";
		myDeck.pile[2*i + 1].print();
		std::cout << "\n";
		int result = myDeck.pile[i * 2].compare(myDeck.pile[2*i+1]);
		switch (result) {
			case 1:
				scoreP1++;
				std::cout << Player1 << "=> Winner\n\n";
				break;
			case -1:
				scoreP2++;
				std::cout << Player2 << "=> Winner\n\n";
				break;
			case 0:
				std::cout << "tie game \n\n";
				break;	
		}
	}
	std::cout << "-----Final Stats----- \n	" << Player1 << " vs. " << Player2 << "\n";
	std::cout << "Wins	" << scoreP1 << "	" << scoreP2;
	std::cout << "\nLoses   " << scoreP2 << "	" << scoreP1;
	std::cout << "\nTies	" << 26-scoreP2 -scoreP1 << "	" << 26-scoreP2 -scoreP1;

	return 0;
}
