// Name: Theodore Malaska
// Class (CECS 325-01)
// Project Name (Prog 1 – War)
// Due Date (09/18/2024)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.
#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{
public:
	Deck( ); // constructor which creates a deck of 52 cards
	Card deal( ); // deal a card
	void print( ); // show all the cards in the deck
	void shuffle( ); // shuffle the cards in the deck
	Card pile[52];
	

};  

#endif

