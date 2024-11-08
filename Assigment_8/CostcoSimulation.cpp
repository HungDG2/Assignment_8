
#include "CostcoSimulation.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
using namespace std;

//precondition: none
//postcondition: class default constructor
CostcoSimulation::CostcoSimulation()
{

	Costcotime = 0;

	Customers = 0;

	registers = 0;

}

//precondition: none
//postcondition: class mutator that will allow us to set the amount of time that the program will run
void CostcoSimulation::setTime(int time1)
{

	Costcotime = time1;

}

//precondition: none
//postcondition: class mutator that will allow the user to find the amount of customers that will pass through the queue
void CostcoSimulation::setCustomers(int customers1)
{

	Customers = customers1;

}

//precondition: none
//postcondition: class mutator will allow the user to set how many registers will be open during the program
void CostcoSimulation::setRegisters(int registers1)
{

	registers = registers1;

}

//precondition: none
//postcondition: Simulation function will be used to run the costco line queue simulation
//////////////// using our class mutators and queue data structures we will find how many customers have passed through line
//////////////// queue after a set time
void CostcoSimulation::Simulation()
{

	int probability = 0;

	//we will set customers to 0 to start the program
	setCustomers(0);

	while (Costcotime-- > 0) //while loop will continue until time equals zero
	{
		probability = rand() % 5;

		system("cls");

		cout << "\n\tCostCo warehouse store: " << Costcotime << "       " << "Number of served customers: " << Customers << endl << endl;

		switch (registers)//switch statement will be used to switch between all scenarios depending on how many registers the user chooses
		{
		case 1://case 1 will run if there is only 1 register
		{
			cout << "\t\tCash register #1: ";

			q1.push(Costcotime);//we will start pushing customers through the first queue

			displayLine(q1, probability); //we will display the line

			probability = rand() % 2;

			if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
			{
				q1.pop(); //pops customer out of the queue
				++Customers;
			}

			cout << endl;

		}
		break;
		case 2://case 2 will run if there are 2 registers open
		{
			//we will compare all open registers/queues and evenly distribute customers throughout all queues 
			if (q1.size() < q2.size())
			{
				q1.push(Costcotime);//we will start pushing customers through the first queue
			}
			else if (q2.size() < q1.size())
			{
				q2.push(Costcotime);//we will start pushing customers through the second queue
			}
			else if (q1.size() == q2.size())
			{
				q1.push(Costcotime);
			}
			cout << "\t\tCash register #1: ";

			displayLine(q1, probability);//we will display line in queue 1

			if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
			{
				q1.pop(); //pops customer out of the queue
				++Customers;
			}

			cout << "\n\n\t\tCash register #2: ";

			displayLine(q2, probability);//we will display line in queue 2

			if (!q2.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q2.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << endl;

		}
		break;
		case 3://case 3 will run if there are 3 registers open
		{
			//we will compare all open registers/queues and evenly distribute customers throughout all queues
			if (highestQueue() == q1.size())
			{
				q1.push(Costcotime);//we will start pushing customers through the first queue
			}
			else if (highestQueue() == q2.size())
			{
				q2.push(Costcotime);//we will start pushing customers through the second queue
			}
			else if (highestQueue() == q3.size())
			{
				q3.push(Costcotime);//we will start pushing customers through the third queue
			}
			else
			{
				q1.push(Costcotime);
			}

			cout << "\t\tCash register #1: ";

			displayLine(q1, probability);//we will display line in queue 1

			if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
			{
				q1.pop(); //pops customer out of the queue
				++Customers;
			}

			cout << "\n\n\t\tCash register #2: ";

			displayLine(q2, probability);//we will display line in queue 2

			if (!q2.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q2.pop(); //pops customer out of the queue
					++Customers;
				}
			}


			cout << "\n\n\t\tCash register #3: ";

			displayLine(q3, probability);//we will display line in queue 3

			if (!q3.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q3.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << endl;

		}
		break;
		case 4://case 4 will run if there are 4 registers open
		{
			//we will compare all open registers/queues and evenly distribute customers throughout all queues
			if (highestQueue() == q1.size())
			{
				q1.push(Costcotime);//we will start pushing customers through the first queue
			}
			else if (highestQueue() == q2.size())
			{
				q2.push(Costcotime);//we will start pushing customers through the second queue
			}
			else if (highestQueue() == q3.size())
			{
				q3.push(Costcotime);//we will start pushing customers through the third queue
			}
			else if (highestQueue() == q4.size())
			{
				q4.push(Costcotime);//we will start pushing customers through the fourth queue
			}
			else
			{
				q1.push(Costcotime);
			}

			cout << "\t\tCash register #1: ";

			displayLine(q1, probability);//we will display line in queue 1

			if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
			{
				q1.pop(); //pops customer out of the queue
				++Customers;
			}

			cout << "\n\n\t\tCash register #2: ";

			displayLine(q2, probability);//we will display line in queue 2

			if (!q2.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q2.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #3: ";

			displayLine(q3, probability);//we will display line in queue 3

			if (!q3.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q3.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #4";

			displayLine(q4, probability);//we will display line in queue 4

			if (!q4.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q4.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << endl;

		}
		break;
		case 5://case 5 will run if there are 5 registers open
		{
			//we will compare all open registers/queues and evenly distribute customers throughout all queues
			if (highestQueue() == q1.size())
			{
				q1.push(Costcotime);//we will start pushing customers through the first queue
			}
			else if (highestQueue() == q2.size())
			{
				q2.push(Costcotime);//we will start pushing customers through the second queue
			}
			else if (highestQueue() == q3.size())
			{
				q3.push(Costcotime);//we will start pushing customers through the third queue
			}
			else if (highestQueue() == q4.size())
			{
				q4.push(Costcotime);//we will start pushing customers through the fourth queue
			}
			else if (highestQueue() == q5.size())
			{
				q5.push(Costcotime);//we will start pushing customers through the fifth queue
			}
			else
			{
				q1.push(Costcotime);
			}

			cout << "\t\tCash register #1: ";

			displayLine(q1, probability);//we will display line in queue 1

			if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
			{
				q1.pop(); //pops customer out of the queue
				++Customers;
			}

			cout << "\n\n\t\tCash register #2: ";

			displayLine(q2, probability);//we will display line in queue 2

			if (!q2.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q2.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #3: ";

			displayLine(q3, probability);//we will display line in queue 3

			if (!q3.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q3.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #4";

			displayLine(q4, probability);//we will display line in queue 4

			if (!q4.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q4.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #5";

			displayLine(q5, probability);//we will display line in queue 5

			if (!q5.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q5.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << endl;
		}
		break;
		case 6://case 6 will run if there are 6 registers open
		{
			//we will compare all open registers/queues and evenly distribute customers throughout all queues
			if (highestQueue() == q1.size())
			{
				q1.push(Costcotime);//we will start pushing customers through the first queue
			}
			else if (highestQueue() == q2.size())
			{
				q2.push(Costcotime);//we will start pushing customers through the second queue
			}
			else if (highestQueue() == q3.size())
			{
				q3.push(Costcotime);//we will start pushing customers through the third queue
			}
			else if (highestQueue() == q4.size())
			{
				q4.push(Costcotime);//we will start pushing customers through the fourth queue
			}
			else if (highestQueue() == q5.size())
			{
				q5.push(Costcotime);//we will start pushing customers through the fifth queue
			}
			else if (highestQueue() == q6.size())
			{
				q6.push(Costcotime);//we will start pushing customers through the sixth queue
			}
			else
			{
				q1.push(Costcotime);
			}

			cout << "\t\tCash register #1: ";

			displayLine(q1, probability);//we will display line in queue 1

			if (probability == 1)//if  will be used to determine if the customer will be finished checking out
			{
				q1.pop(); //pops customer out of the queue
				++Customers;
			}
			//statement
				cout << "\n\n\t\tCash register #2: ";

			displayLine(q2, probability);//we will display line in queue 2

			if (!q2.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q2.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #3: ";

			displayLine(q3, probability);//we will display line in queue 3

			if (!q3.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q3.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #4";

			displayLine(q4, probability);//we will display line in queue 4

			if (!q4.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q4.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #5";

			displayLine(q5, probability);//we will display line in queue 5

			if (!q5.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q5.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #6";

			displayLine(q6, probability);//we will display line in queue 6

			if (!q6.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q6.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << endl;
		}
		break;
		case 7://case 7 will run if there are 7 registers open
		{
			//we will compare all open registers/queues and evenly distribute customers throughout all queues
			if (highestQueue() == q1.size())
			{
				q1.push(Costcotime);//we will start pushing customers through the first queue
			}
			else if (highestQueue() == q2.size())
			{
				q2.push(Costcotime);//we will start pushing customers through the second queue
			}
			else if (highestQueue() == q3.size())
			{
				q3.push(Costcotime);//we will start pushing customers through the third queue
			}
			else if (highestQueue() == q4.size())
			{
				q4.push(Costcotime);//we will start pushing customers through the fourth queue
			}
			else if (highestQueue() == q5.size())
			{
				q5.push(Costcotime);//we will start pushing customers through the fifth queue
			}
			else if (highestQueue() == q6.size())
			{
				q6.push(Costcotime);//we will start pushing customers through the sixth queue
			}
			else if (highestQueue() == q7.size())
			{
				q7.push(Costcotime);//we will start pushing customers through the seventh queue
			}
			else
			{
				q1.push(Costcotime);
			}

			cout << "\t\tCash register #1: ";

			displayLine(q1, probability);//we will display line in queue 1

			if (probability == 1) //20% chance that the customer will be finished checking out
			{
				q1.pop(); //pops customer out of the queue
				++Customers;
			}

			cout << "\n\n\t\tCash register #2: ";

			displayLine(q2, probability);//we will display line in queue 2

			if (!q2.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q2.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #3: ";

			displayLine(q3, probability);//we will display line in queue 3

			if (!q3.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q3.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #4";

			displayLine(q4, probability);//we will display line in queue 4

			if (!q4.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q4.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #5";

			displayLine(q5, probability);//we will display line in queue 5

			if (!q5.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q5.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #6";

			displayLine(q6, probability);//we will display line in queue 6

			if (!q6.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q6.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #7";

			displayLine(q7, probability);//we will display line in queue 7

			if (!q7.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q7.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << endl;

		}
		break;
		case 8://case 8 will run if there are 8 registers open
		{
			//we will compare all open registers/queues and evenly distribute customers throughout all queues
			if (highestQueue() == q1.size())
			{
				q1.push(Costcotime);//we will start pushing customers through the first queue
			}
			else if (highestQueue() == q2.size())
			{
				q2.push(Costcotime);//we will start pushing customers through the second queue
			}
			else if (highestQueue() == q3.size())
			{
				q3.push(Costcotime);//we will start pushing customers through the third queue
			}
			else if (highestQueue() == q4.size())
			{
				q4.push(Costcotime);//we will start pushing customers through the fourth queue
			}
			else if (highestQueue() == q5.size())
			{
				q5.push(Costcotime);//we will start pushing customers through the fifth queue
			}
			else if (highestQueue() == q6.size())
			{
				q6.push(Costcotime);//we will start pushing customers through the sixth queue
			}
			else if (highestQueue() == q7.size())
			{
				q7.push(Costcotime);//we will start pushing customers through the seventh queue
			}
			else if (highestQueue() == q8.size())
			{
				q8.push(Costcotime);//we will start pushing customers through the 8th queue
			}
			else
			{
				q1.push(Costcotime);
			}

			cout << "\t\tCash register #1: ";

			displayLine(q1, probability);//we will display line in queue 1

			if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
			{
				q1.pop(); //pops customer out of the queue
				++Customers;
			}

			cout << "\n\n\t\tCash register #2: ";

			displayLine(q2, probability);//we will display line in queue 2

			if (!q2.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q2.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #3: ";

			displayLine(q3, probability);//we will display line in queue 3

			if (!q3.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q3.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #4";

			displayLine(q4, probability);//we will display line in queue 4

			if (!q4.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q4.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #5";

			displayLine(q5, probability);//we will display line in queue 5

			if (!q5.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q5.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #6";

			displayLine(q6, probability);//we will display line in queue 6

			if (!q6.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q6.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #7";

			displayLine(q7, probability);//we will display line in queue 7

			if (!q7.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q7.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #8";

			displayLine(q8, probability);//we will display line in queue 8

			if (!q8.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q8.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << endl;

		}
		break;
		case 9://case 9 will run if there are 9 registers open
		{
			//we will compare all open registers/queues and evenly distribute customers throughout all queues
			if (highestQueue() == q1.size())
			{
				q1.push(Costcotime);//we will start pushing customers through the first queue
			}
			else if (highestQueue() == q2.size())
			{
				q2.push(Costcotime);//we will start pushing customers through the second queue
			}
			else if (highestQueue() == q3.size())
			{
				q3.push(Costcotime);//we will start pushing customers through the third queue
			}
			else if (highestQueue() == q4.size())
			{
				q4.push(Costcotime);//we will start pushing customers through the fourth queue
			}
			else if (highestQueue() == q5.size())
			{
				q5.push(Costcotime);//we will start pushing customers through the fifth queue
			}
			else if (highestQueue() == q6.size())
			{
				q6.push(Costcotime);//we will start pushing customers through the sixth queue
			}
			else if (highestQueue() == q7.size())
			{
				q7.push(Costcotime);//we will start pushing customers through the seventh queue
			}
			else if (highestQueue() == q8.size())
			{
				q8.push(Costcotime);//we will start pushing customers through the 8th queue
			}
			else if (highestQueue() == q9.size())
			{
				q9.push(Costcotime);//we will start pushing customers through the ninth queue
			}
			else
			{
				q1.push(Costcotime);
			}

			cout << "\t\tCash register #1: ";

			displayLine(q1, probability);//we will display line in queue 1

			if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
			{
				q1.pop(); //pops customer out of the queue
				++Customers;
			}

			cout << "\n\n\t\tCash register #2: ";

			displayLine(q2, probability);//we will display line in queue 2

			if (!q2.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q2.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #3: ";

			displayLine(q3, probability);//we will display line in queue 3

			if (!q3.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q3.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #4";

			displayLine(q4, probability);//we will display line in queue 4

			if (!q4.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q4.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #5";

			displayLine(q5, probability);//we will display line in queue 5

			if (!q5.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q5.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #6";

			displayLine(q6, probability);//we will display line in queue 6

			if (!q6.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q6.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #7";

			displayLine(q7, probability);//we will display line in queue 7

			if (!q7.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q7.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #8";

			displayLine(q8, probability);//we will display line in queue 8

			if (!q8.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q8.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #9";

			displayLine(q9, probability);//we will display line in queue 9

			if (!q9.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q9.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << endl;

		}
		break;
		case 10://case 10 will run if there are 10 registers open
		{
			//we will compare all open registers/queues and evenly distribute customers throughout all queues
			if (highestQueue() == q1.size())
			{
				q1.push(Costcotime);//we will start pushing customers through the first queue
			}
			else if (highestQueue() == q2.size())
			{
				q2.push(Costcotime);//we will start pushing customers through the second queue
			}
			else if (highestQueue() == q3.size())
			{
				q3.push(Costcotime);//we will start pushing customers through the third queue
			}
			else if (highestQueue() == q4.size())
			{
				q4.push(Costcotime);//we will start pushing customers through the fourth queue
			}
			else if (highestQueue() == q5.size())
			{
				q5.push(Costcotime);//we will start pushing customers through the fifth queue
			}
			else if (highestQueue() == q6.size())
			{
				q6.push(Costcotime);//we will start pushing customers through the sixth queue
			}
			else if (highestQueue() == q7.size())
			{
				q7.push(Costcotime);//we will start pushing customers through the seventh queue
			}
			else if (highestQueue() == q8.size())
			{
				q8.push(Costcotime);//we will start pushing customers through the 8th queue
			}
			else if (highestQueue() == q9.size())
			{
				q9.push(Costcotime);//we will start pushing customers through the ninth queue
			}
			else if (highestQueue() == q10.size())
			{
				q10.push(Costcotime);//we will start pushing customers through the 10th queue
			}
			else
			{
				q1.push(Costcotime);
			}

			cout << "\t\tCash register #1: ";

			displayLine(q1, probability);//we will display line in queue 1

			if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
			{
				q1.pop(); //pops customer out of the queue
				++Customers;
			}

			cout << "\n\n\t\tCash register #2: ";

			displayLine(q2, probability);//we will display line in queue 2

			if (!q2.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q2.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #3: ";

			displayLine(q3, probability);//we will display line in queue 3

			if (!q3.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q3.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #4";

			displayLine(q4, probability);//we will display line in queue 4

			if (!q4.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q4.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #5";

			displayLine(q5, probability);//we will display line in queue 5

			if (!q5.empty())
			{
				if (probability == 1) //20% chance that the customer will be finished checking out
				{
					q5.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #6";

			displayLine(q6, probability);//we will display line in queue 6

			if (!q6.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q6.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #7";

			displayLine(q7, probability);//we will display line in queue 7

			if (!q7.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q7.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #8";

			displayLine(q8, probability);//we will display line in queue 8

			if (!q8.empty())
			{
				if (probability == 1) //20% chance that the customer will be finished checking out
				{
					q8.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #9";

			displayLine(q9, probability);//we will display line in queue 9

			if (!q9.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q9.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << "\n\n\t\tCash register #10";

			displayLine(q10, probability);//we will display line in queue 10

			if (!q10.empty())
			{
				if (probability == 1)//if statement will be used to determine if the customer will be finished checking out
				{
					q10.pop(); //pops customer out of the queue
					++Customers;
				}
			}

			cout << endl;

		}
		}
		this_thread::sleep_for(chrono::seconds(1)); //delays for 1 second before starting the next loop
	}

}

//precondition: none
//postcondition: highestqueue will allow our program to find which line/register contains more customers
//////////////// this will then allow the program to distibute the customers evenly across all open registers/queues
int CostcoSimulation::highestQueue()
{

	int longestLine;

	//initialzing vector that will hold the queue sizes of each queue/register
	vector<int> line;

	//if statements will be used to push queue size data to our vector
	if (registers == 1)
	{
		line.push_back(q1.size());
	}
	else if (registers == 2)
	{
		line.push_back(q1.size());
		line.push_back(q2.size());
	}
	else if (registers == 3)
	{
		line.push_back(q1.size());
		line.push_back(q2.size());
		line.push_back(q3.size());
	}
	else if (registers == 4)
	{
		line.push_back(q1.size());
		line.push_back(q2.size());
		line.push_back(q3.size());
		line.push_back(q4.size());
	}
	else if (registers == 5)
	{
		line.push_back(q1.size());
		line.push_back(q2.size());
		line.push_back(q3.size());
		line.push_back(q4.size());
		line.push_back(q5.size());
	}
	else if (registers == 6)
	{
		line.push_back(q1.size());
		line.push_back(q2.size());
		line.push_back(q3.size());
		line.push_back(q4.size());
		line.push_back(q5.size());
		line.push_back(q6.size());
	}
	else if (registers == 7)
	{
		line.push_back(q1.size());
		line.push_back(q2.size());
		line.push_back(q3.size());
		line.push_back(q4.size());
		line.push_back(q5.size());
		line.push_back(q6.size());
		line.push_back(q7.size());
	}
	else if (registers == 8)
	{
		line.push_back(q1.size());
		line.push_back(q2.size());
		line.push_back(q3.size());
		line.push_back(q4.size());
		line.push_back(q5.size());
		line.push_back(q6.size());
		line.push_back(q7.size());
		line.push_back(q8.size());
	}
	else if (registers == 9)
	{
		line.push_back(q1.size());
		line.push_back(q2.size());
		line.push_back(q3.size());
		line.push_back(q4.size());
		line.push_back(q5.size());
		line.push_back(q6.size());
		line.push_back(q7.size());
		line.push_back(q8.size());
		line.push_back(q9.size());
	}
	else if (registers == 10)
	{
		line.push_back(q1.size());
		line.push_back(q2.size());
		line.push_back(q3.size());
		line.push_back(q4.size());
		line.push_back(q5.size());
		line.push_back(q6.size());
		line.push_back(q7.size());
		line.push_back(q8.size());
		line.push_back(q9.size());
		line.push_back(q10.size());
	}

	sort(line.begin(), line.end());

	longestLine = line.front();

	//we will return which line has the highest amount of customers in queue
	return longestLine;

}

//precondition: none
//postcondition: displayLine function will be used to display all queue lines during our simulation
void CostcoSimulation::displayLine(queue<int> line, int probability)
{

	cout << "\n\t\t\t\t" << string(1, char(254)) << line.size() << string(1, char(254));

	if (line.size() != 0)
	{
		for (int i = 0; i < line.size() - 1; i++)
		{
			cout << "  " << string(4, char(254));
		}
	}
	probability = rand() % 5;

}
