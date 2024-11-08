// Name: Chris Johnson & Joseph Jimenez & Oscar Gallardo & Anthony Le & Hung
// Date: 11-7-24
// Module 8 - Queue and Deque


#include<iostream>
#include "input.h"
#include <queue>
#include "WarCardGame.h"
#include "Patient.h"
#include "CostcoSimulation.h"


using namespace std;

// Function Prototypes
void warGame();
void PriorityOption();
char menuOption();
void Costco();

// Main Function
int main()
{
    system("cls");
    do
    {
        switch (toupper(menuOption()))
        {
        case '0': exit(0);
            break;
        case '1': system("cls"); warGame();
            break;
        case '2': system("cls"); PriorityOption();
            break;
        case '3': system("cls"); Costco();
            break;
        default: cout << "\t\tERROR - Invalid option. Please enter valid option."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);


    return EXIT_SUCCESS;
}

char menuOption()
{
    system("cls");
    cout << "\t\tCMPR131 Chapter 8: Applications using Queues and Deque\n";
    cout << "\t\tby Chris Johnson & Joseph Jimenez & Oscar Gallardo & Anthony Le & Hung Duong (11-7-2024)\n";
    cout << "\n\t" << string(85, char(205)) << "\n";
    cout << "\t\t1> Simulation of War (card game) using deque STL\n";
    cout << "\t\t2> Simulation of an emergency room (ER) using priority queue STL\n";
    cout << "\t\t3> Simulation of checkout lines at CostCo using multiple queues STL\n";
    cout << "\n\t" << string(85, char(196)) << "\n";
    cout << "\t\t0. Exit\n";
    cout << "\n\t" << string(85, char(205));
   

    return input::inputChar("\n\t\tOption: ", static_cast <string>("0123"));
}



void PriorityOption()
{
    system("cls");
    cout << "\n\t2> Simulation of an emergency room (ER) using priority queue STL\n";
    priority_queue<Patient> pq2;
    vector<Patient> submit;
    do
    {
        cout << "\n\t\t A> Register a patient";
        cout << "\n\t\t B> Transfer patient(s) to the designation";
        cout << "\n\t\t C> Display transferred patients";
        cout << "\n\t\t 0> return\n";
        switch (toupper(input::inputChar("\t\t Option: ", static_cast <string>("ABC0"))))
        {
        case '0': return;
        case 'A':
        {
            Patient patient;
            string name;
            cout << "\n\t\tEnter the patient's name: ";
            getline(cin, name);
            patient.setName(name);
            patient.setAge(input::inputInteger("\t\tEnter the patient's age: ", true));
            patient.setCheckedInTime(time(0));
            patient.setGender(toupper(input::inputChar("\t\tChoose the patient's gender (F-female or M - male) : ", 'F', 'M')));
            patient.setPriority(input::inputInteger("\t\tChoose the ER level 1)Non-urgent, 2)Less Urgent, 3)Urgent, 4)Emergent, or 5)Resuscitation: ", 1, 5));
            pq2.push(patient); // enqueue
            cout << "\n\t\tPatient information has been registered.\n";
        }
        break;
        case 'B':
        {
            if (!pq2.empty())
            {
                if (pq2.top().getPriority() == 5)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - transfers to ICU...\n";
                    pq2.pop(); // dequeue
                    break;
                }
                else if (pq2.top().getPriority() == 4)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - transfers to surgery room...\n";
                    pq2.pop();
                    break;
                }
                else if (pq2.top().getPriority() == 3)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - transfers to emergency room...\n";
                    pq2.pop();
                    break;
                }
                else if (pq2.top().getPriority() == 2)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - transfers to x-ray lab...\n";
                    pq2.pop();
                    break;
                }
                else if (pq2.top().getPriority() == 1)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - examines and gives prescription...\n";
                    pq2.pop();
                    break;
                }
            }
        }
        break;
        case 'C':
        {
            if (!submit.empty())
            {
                sort(submit.begin(), submit.end());
                reverse(submit.begin(), submit.end());
                cout << '\n';
                for (int i = 0; i < submit.size(); i++)
                    cout << "\t\t" << i + 1 << " - " << submit[i] << '\n';
            }
            else
                cout << "\n\t\tNo patient has been transferred.\n";
        }
        break;
        }
    } while (true);
}

void warGame()
{
    WarGame menu;
    menu.menuInformation();
}

//precondtion: Create class CostcoSimulation
//postcondition: We will use the created CostcoSimulation class to create a program that will allow the user to 
////////////// simulate a line queue at a costco cashier checkout
void Costco()
{

    system("cls");

    cout << endl;

    //we will initialize a CostcoSimulation class object
    CostcoSimulation costco;

    cout << "\n\t3> Simulation of checkout lines at a CostCo warehouse store\n\n";

    cout << endl;

    //we will allow the user to input the amount of time the program will run
    costco.setTime(input::inputInteger("\tEnter the time(1..37800 in seconds) of the store will be operated : ", 1, 37800));

    cout << endl;

    //we will allow the user to input how many registers are going to be working
    costco.setRegisters(input::inputInteger("\tEnter the number of cash registers (1..10): ", 1, 10));

    //we will call Simulation function in order to run the line queue simulation
    costco.Simulation();

}
