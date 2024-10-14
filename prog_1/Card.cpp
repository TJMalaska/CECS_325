// Name: Theodore Malaska
// Class (CECS 325-01)
// Project Name (Prog 1 – War)
// Due Date (09/18/2024)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <map>
#include "Card.h"
//using namespace std;


Card::Card(){
	rank = 'X';
	suit = 'X';
}
Card::Card(char Rank, char Suit)
{
	rank = Rank;
	suit = Suit;
}

void Card::print()
{
	if (rank == 'T') {
		std::cout << "10" << suit << " ";
	}
	else  std::cout<< rank << suit << " ";
	return;	
}

int Card::compare(Card card)
{
	std::map<char, int> map;
	map['A'] = 1;
	map['2'] = 2;
	map['3'] = 3;
	map['4'] = 4;
	map['5'] = 5;
	map['6'] = 6;
	map['7'] = 7;
	map['8'] = 8;
	map['9'] = 9;
	map['T'] = 10;
	map['J'] = 11;
	map['Q'] = 12;
	map['K'] = 13;
	
	int myval = map[rank];
	int otherVal = map[card.rank];

	if (myval > otherVal) {
		return 1;
	}
	else if(myval < otherVal){
		return -1;
	}
	else return 0;
	
}

