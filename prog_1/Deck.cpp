// Name: Theodore Malaska
// Class (CECS 325-01)
// Project Name (Prog 1 – War)
// Due Date (09/18/2024)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include "Card.h"
#include "Deck.h"
//#include <cstdlib>
#include <iostream>
#include <ctime>
Deck::Deck()
{
	char suit[4] = {'C', 'S', 'D', 'H'};
	char rank[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'}; 
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 13; j++)
		{
			pile[i * 13 + j] = Card(rank[j],suit[i]);
		}	
	}		
}

void Deck::print()
{
	for( int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 13; j++)
		{
			pile[i * 13 + j].print();
		}
		std::cout<< "\n";
	}		
	std::cout << "\n";
}

void Deck::shuffle()
{
	srand((int)time(0));
	for(int i = 0; i < 52; i++){
		int swapIndex = rand() % 52;
		Card temp = pile[i];
		pile[i] = pile[swapIndex];
		pile[swapIndex] = temp;

	}
}

