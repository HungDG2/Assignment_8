#pragma once
#include <iostream>
#include <queue>
using namespace std;



class CostcoSimulation
{

private:

	//private class members
	int Costcotime;

	int Customers;

	int registers;

	//all queues representing 10 different registers
	queue<int> q1;

	queue<int> q2;

	queue<int> q3;

	queue<int> q4;

	queue<int> q5;

	queue<int> q6;

	queue<int> q7;

	queue<int> q8;

	queue<int> q9;

	queue<int> q10;


public:

	//default constructor
	CostcoSimulation();

	//class mutators
	void setTime(int newTime);
	void setRegisters(int newRegisters);
	void setCustomers(int newServed);

	//function will run our costco simulation
	void Simulation();

	//function will be used to find line with highest queue
	int highestQueue();

	//function will display all lines/registers
	void displayLine(queue<int> line, int probability);

};

