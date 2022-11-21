#include <iostream>
#include "loading.h"
#include <string>
#include <Windows.h>
#include "adminFunction.h"

using namespace std;

void passwordVerification();
void mainMenu();

//Auth before opening the main program

void passwordVerification()
{
	system("cls");

	string password;

	cout << "\n\n\n\n\n\t\t\t\t\t";
	cout << "\n\n\n\t\t\t\t\tEnter Password: ";

	do
	{
		cin >> password;

		if (password != "password")
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"
				<< "Wrong password!, try again or type 'quit' to quit the program.";
			cout << "Enter Password: ";
		}
		if (password == "Quit" || password == "quit")
		{
			system("cls");
			cout << "\t\t\n\n\n\n\n\n\n\t\t\tQuitting the program";

			for (int i = 0; i < 4; i++)
			{
				Sleep(1000); // 1 second pause
				cout << ".;";
			}
			exit(0);
		}
	} while (password != "password");
	mainMenu();
}// SRM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	//fast io
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	system("color 9f");

	passwordVerification();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
