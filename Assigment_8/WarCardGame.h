#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include "input.h"
#include "CardDeck.h"

using namespace std;

/*
- War Card Game
- Cards -> class
	- number value
	- suit (spades, hearts, diamonds, clubs)

- Deck - class 
    - hold the cards 52 cards

- Shuffle cards

- 2 players ( deal cards)
	- 2 holders -> array/list
	- take the top card 
	- compare the cards -> if statement
		- if the player 1 card is greater than player 2 card -> player 1 wins -> player 1 takes both cards
		- else player 2 wins -> player 2 takes both cards
		- if the player 1 card is equal to player 2 card -> war
		- logic for war
			- both players take 3 cards and store in a new array/list
			- compare the cards -> if statement
			- winner takes all the cards from the array.
	- if player 1 runs out of cards -> player 2 wins and opposite -> check isempty deque of each player

*/

//char inputChar(string prompt, string lookup);
//char inputChar(string prompt, char yes, char no);
//int inputInteger(string prompt, bool posNeg);
//int inputInteger(string prompt, int startRange, int endRange);
//double inputDouble(string prompt);


class WarGame {
private:
	deque <CardDeck> p1Cards;
	deque <CardDeck> p2Cards;
	deque <CardDeck> warCards;
	int numCardsPerSuit;
	vector <CardDeck> deck;
public:
	//defualt constructor 
	WarGame();
	WarGame(int newNumCardsPerSuite);

	//member functions
	void fillDeck();
	void randomizeDeck();
	void distributeCards();
	void playGame();

	//memnber function to get the whole menu
	void menuInformation();
};
