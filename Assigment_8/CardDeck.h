#pragma once
#include <string>
using namespace std;

//Precon: going to create a class called CardDeck and gets the suit and value
//Postcon: going to have privates, in public are creating defualt constructor, and getters and setters
class CardDeck {
private:
	//Card Suit (Spade, Clover, Heart, Diamond)
	string suit;
	// Card Value (1	to 13)
	int value;
public:
	//defualt constructor
	CardDeck();

	//getters(accesors)
	string getCardSuit() const;
	int getCardValue() const;

	//setters(mutators)
	void setCardSuit(string newSuit);
	void setCardValue(int newCardValue);

	~CardDeck() {}//Destructor
};
