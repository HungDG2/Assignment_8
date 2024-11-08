#include "WarCardGame.h"

//Precon: going to call the default constructor class
//Postcon: going to then intialize the private and member function fillDeck()
WarGame::WarGame() {
	numCardsPerSuit = 1;
	fillDeck();
}
//Precon: going to get the new numCardsPerSuit
//Postcon: going to set the private numCardsPerSuit with the new numCardsPerSuit member
WarGame::WarGame(int newNumCardsPerSuit) {
	numCardsPerSuit = newNumCardsPerSuit;
	fillDeck();
}

//Precon: going to make function that checks deck
//Postcon: going to then call my setters to set teh information, passing in an object of the clas CardDeck
void WarGame::fillDeck() {
	for (int index = 0; index < numCardsPerSuit; index++) {
		CardDeck newCard;

		newCard.setCardValue(index + 1);
		newCard.setCardSuit("Spades (" + string(1, char(6)) + ")");
		deck.push_back(newCard);
		newCard.setCardSuit("Clubs (" + string(1, char(5)) + ")");
		deck.push_back(newCard);
		newCard.setCardSuit("Diamonds (" + string(1, char(4)) + ")");
		deck.push_back(newCard);
		newCard.setCardSuit("Hearts (" + string(1, char(3)) + ")");
		deck.push_back(newCard);
	}
	randomizeDeck();
}
//Precon: going to make a random deck function
//Postcon: going to make sure its random, calling the shuffle built in function to get the deck from being, to end and make it random
void WarGame::randomizeDeck() {
	shuffle(deck.begin(), deck.end(), random_device());
	distributeCards();
}
//Precon: goning to create a distribute card function
//Postcon: going to do a while loop that checks if deck is not empty and then push the information to the queue
void WarGame::distributeCards() {
	while (!deck.empty()) {
		p1Cards.push_back(deck.back());
		deck.pop_back();
		p2Cards.push_back(deck.back());
		deck.pop_back();
	}
}
//Precon: going to create a playGame function
//Postcon: going to then make sure it plays the game by using push,pop, front, and using the getters
void WarGame::playGame() {
	do {
		CardDeck p1CompareCard = p1Cards.front();
		CardDeck p2CompareCard = p2Cards.front();
		p1Cards.pop_front();
		p2Cards.pop_front();
		cout << "\n\tPlayer1: " << p1CompareCard.getCardValue() << " of " << p1CompareCard.getCardSuit() << "   Player2: " << p2CompareCard.getCardValue() << " of " << p2CompareCard.getCardSuit();
		if (p1CompareCard.getCardValue() > p2CompareCard.getCardValue()) {
			p1Cards.push_back(p1CompareCard);
			p1Cards.push_back(p2CompareCard);
			cout << " -> Player1 wins!" << endl << endl;
			system("pause");

		}
		else if (p1CompareCard.getCardValue() < p2CompareCard.getCardValue()) {
			p2Cards.push_back(p2CompareCard);
			p2Cards.push_back(p1CompareCard);
			cout << " -> Player2 wins!" << endl << endl;
			system("pause");

		}
		else {
			cout << " -> Tie-Breaker Begins!" << endl << endl;
			system("pause");
			cout << endl;
			warCards.push_back(p1CompareCard);
			warCards.push_back(p2CompareCard);
			while (p1CompareCard.getCardValue() == p2CompareCard.getCardValue()) {
				for (int index = 0; index < 4; index++) {
					if (!p1Cards.empty() && !p2Cards.empty()) {

						p1CompareCard = p1Cards.front();
						p2CompareCard = p2Cards.front();
						warCards.push_back(p1CompareCard);
						warCards.push_back(p2CompareCard);
						p1Cards.pop_front();
						p2Cards.pop_front();
					}
					else if (p1Cards.empty()) {
						cout << "\tPlayer 1 Has Insufficient Cards For War. *****Player 2 Wins*****" << endl;
						return;
					}
					else if (p2Cards.empty()) {
						cout << "\tPlayer 2 Has Insufficient Cards For War. *****Player 1 Wins*****" << endl;
						return;
					}
				}

				cout << "\tPlayer1: " << p1CompareCard.getCardValue() << " of " << p1CompareCard.getCardSuit() << "   Player2: " << p2CompareCard.getCardValue() << " of " << p2CompareCard.getCardSuit();
				if (p1CompareCard.getCardValue() > p2CompareCard.getCardValue()) {
					while (!warCards.empty()) {
						p1Cards.push_back(warCards.front());
						warCards.pop_front();
					}
					cout << " -> Player1 wins!" << endl << endl;
					system("pause");
					cout << endl;
				}
				else if (p1CompareCard.getCardValue() < p2CompareCard.getCardValue()) {
					while (!warCards.empty()) {
						p2Cards.push_back(warCards.front());
						warCards.pop_front();
					}
					cout << " -> Player2 wins!" << endl << endl;
					system("pause");
					cout << endl;
				}
				else {
					cout << " -> Tie breaker again!" << endl << endl;
					system("pause");
					cout << endl;
				}
			}

		}

	} while (!p1Cards.empty() && !p2Cards.empty());

	if (p1Cards.empty()) {
		cout << "Player 2 wins the war with most number of cards(" << (numCardsPerSuit * 4) << ")." << endl;
	}
	else {
		cout << "Player 1 wins the war with most number of cards(" << (numCardsPerSuit * 4) << ")." << endl;
	}
}

//Precon: going to print the information
//Postcon: going to create a menu that makse sure it calls the playGame function
void WarGame::menuInformation()
{
	system("cls");
	cout << "\n\t1> Simulation of War (card game) using deque STL\n\n";
	int suit = (input::inputInteger("\tEnter a number of cards per suit(1...13): ", 1, 13));

	if (suit == 1)
	{
		cout << "\n\tGame will always be a tie. No one will win, because 1 is the heighest number in both decks\n";
	}
	else
	{
		WarGame game1(suit);
		game1.playGame();
	}

}
