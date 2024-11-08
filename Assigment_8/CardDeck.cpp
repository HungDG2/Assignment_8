#include "CardDeck.h"

//Precon: going to call the default constructor class
//Postcon: going to then intialize the privates 
CardDeck::CardDeck() : suit(" "), value(0) {}

//Precon: going to get the suit 
//Postcon: going to return the private suit
string CardDeck::getCardSuit() const {
	return suit;
}
//Precon: going to get the new suit
//Postcon: going to set the private suit with the new suit member
void CardDeck::setCardSuit(string newSuit) {
	suit = newSuit;
}

//Precon: going to get the value 
//Postcon: going to return the private value
int CardDeck::getCardValue() const {
	return value;
}
//Precon: going to get the new value
//Postcon: going to set the private value with the new value member
void CardDeck::setCardValue(int newCardValue) {
	value = newCardValue;
}
