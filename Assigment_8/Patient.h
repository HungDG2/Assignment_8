#pragma once

#include <iostream>
#include <string>
#include<queue>
#include "input.h"
using namespace std;

//input (1) header files inputs validation
//char inputChar(string prompt, string lookup);
//char inputChar(string prompt, char yes, char no);
//int inputInteger(string prompt, bool posNeg);
//int inputInteger(string prompt, int startRange, int endRange);
//double inputDouble(string prompt);

//precondition: going to create a class called Patient and gets the information
//postcondition: going to have privates, in public are creating defualt constructor, getters and setters, member functions, and overloading operators
class Patient {
private:
	int priority;
	unsigned int checkedInTime;
	string name;
	int age;
	char gender;
	unsigned int admittedTime;
	string careUnit;
	static string ER_description[5];
	//STL queue of the class
	priority_queue<Patient> pq2;
	//STL to hold the data
	priority_queue<Patient> submit;
	//STL to hold the copy of the submit
	priority_queue<Patient>copy;
public:
	//defualt constructor
	Patient();

	//getters(accesors)
	unsigned int getCheckedInTime() const;
	int getPriority() const;
	string getName() const;
	int getAge() const;
	char getGender() const;

	//setters(mutators)
	void setCheckedInTime(unsigned int newT);
	void setPriority(int newPriority);
	void setName(string newName);
	void setAge(int newAge);
	void setGender(char newGender);

	void displayCheckedInTime() const;

	//overloading operators
	//key in priority queue
	friend bool operator <(const Patient& P1, const Patient& P2);
	friend ostream& operator<<(ostream& outs, const Patient& obj);

	//member function to get the whole menu
	void menuInformation();
};

