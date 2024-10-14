// Name: Theodore Malaska
// Class (CECS 325-01)
// Project Name (Prog 1 – War)
// Due Date (09/18/2024)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <map>
#include <vector>
#include <ctime>

class Card{
	private:
		char rank;
		char suit;
	public:
		Card(char Rank, char Suit) // constructor to create a card, setting the suit and rank
		{
			rank = Rank;
			suit = Suit;
		}

		void print( ) // display the card example: AC, 10S, KD
		{
			if (rank == 'T') {
				std::cout << "10" << suit << " ";
			}
			else  std::cout<< rank << suit << " ";
			return;	
		}

		int compare(Card card)// return 1 for win, 0 for tie, -1 for lose
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
};

class Deck{
	private:
		std::vector<Card> pile;
		std::vector<Card>::iterator indexIt;
	public:
		Deck( ) // constructor which creates a deck of 52 cards
		{
			
			char suit[4] = {'C', 'S', 'D', 'H'};
			char rank[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'}; 
			for (int i = 0; i < 4; i++) 
			{
				for (int j = 0; j < 13; j++)
				{
					pile.push_back(Card(rank[j], suit[i]));
				}	
			}
			indexIt = pile.begin();	
		}	
				

		Card deal( ) // deal a card if you can – otherwise raise an exception
		{
			if(indexIt == pile.end()) throw 1; // out of bounds error
			Card theCard = *indexIt;	
			indexIt++;
			return theCard;
		}

		void print( ) // show all the cards in the deck
		{
			std::vector<Card>::iterator it = pile.begin();
			for(int i = 0; i < 4; i++)
			{
				for(int j = 0; j < 13; j++)
				{
					(*it).print();
					it++;	
				}
				std::cout<< "\n";
			}		
			std::cout<<"\n";
		}
		void shuffle( ) // shuffle the cards in the deck
		{
			
			srand((int)time(0));
			for(int i = 0; i < 52; i++){
				int swapIndex = rand() % 52;
				Card temp = pile[i];
				pile[i] = pile[swapIndex];
				pile[swapIndex] = temp;

			}	
			indexIt = pile.begin();	
		}
		bool isEmpty() // return true if deck is empty
		{
			return pile.empty();
		}
};	
int main(){
	//game loop
	std::string Player1;
	std::string Player2;
	int scoreP1 = 0;
	int scoreP2 = 0;
	int numGames;
	std::cout << "Enter the name of the first player: ";
	std::cin >> Player1;
	std::cout << "\nEnter the name of the second player: ";
	std::cin >> Player2;
	std::cout << "\nHow may games will they play? ";
	std::cin >> numGames;
	std::cout << "\n	Original Deck\n\n";
	Deck myDeck = Deck();	
	myDeck.print();
	std::cout << "\n	Shuffled Deck\n\n";
	myDeck.shuffle();
	myDeck.print();
	
	//Game start
	try {
		for( int i = 0; i < numGames; i++){
			Card card1 = myDeck.deal();
			Card card2 = myDeck.deal();
			std::cout << "Game " << i + 1 << "\n--------\n";
			std::cout << Player1 << "=>";
			card1.print();	
			std::cout << "\n" << Player2 << "=>";
			card2.print();
			std::cout << "\n";
			int result = card1.compare(card2);
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
	}

	catch (...) {
		numGames = 26;
		std::cout<<"no more games cam be played, ran out of cards.\n\n";	
	}
	std::cout << "-----Final Stats----- \n	" << Player1 << " vs. " << Player2 << "\n";
	std::cout << "Wins	" << scoreP1 << "	" << scoreP2;
	std::cout << "\nLoses   " << scoreP2 << "	" << scoreP1;
	std::cout << "\nTies	" << numGames-scoreP2 -scoreP1 << "	" << numGames-scoreP2 -scoreP1;


	return 0;	
}

