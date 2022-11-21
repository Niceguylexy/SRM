#include <iostream>
#include <string.h>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <Bits.h>
#include <fstream>
#include <vector>
#include <sstream>



using namespace std;
void addData(void);
void viewData(void);
void mainMenu(void);
void deleteData(void);
void adminVerification(void);
void studentFunction(void);

void adminFunction()
{
	cout << "\n\n\t\t\t\t\t | Logged in as admin |\n";
	cout << "\n\n\t\t\t\t\t 1. Add Students Detail";
	cout << "\n\n\t\t\t\t\t 2. Delete Students";
	cout << "\n\n\t\t\t\t\t 3. View Table";
	cout << "\n\n\t\t\t\t\t 4. Main Menu";
	cout << "\n\n\t\t\t\t\t 5. Exit";

	int option;
	cout << "\n\n\t\t\t\t\tEnter Choice: ";
	do
	{
		cin >> option;
		{
			switch (option)
			{
			case 1:
				addData();
				break;

			case 2:
				deleteData();
				break;

			case 3:
				viewData();
				break;

			case 4:
				mainMenu();
				break;

			case 5:
				system("cls");
				cout << "\t\t\n\n\n\n\n\n\t\t\t\t\tQuitting the program";

				for (int i = 0; i < 4; i++)
				{
					Sleep(1000);
					cout << ".";
				}
				exit(0);
				break;

			default:
				system("cls");
				cout << "\n\n\t\t\t\t\t Logged in as Admin";
				cout << "\n\n\t\t\t\t\t 1. Add Students Record";
				cout << "\n\n\t\t\t\t\t 2. Delete Record";
				cout << "\n\n\t\t\t\t\t 3. View table";
				cout << "\n\n\t\t\t\t\t 4. Main Menu";
				cout << "\n\n\t\t\t\t\t 5. Exit";

				cout << "\n\n\t\t\t\t\t InvalidC Input";
				cout << "\n\n\t\t\t\t\t Enter Choice: ";
			}

		}
	} while (option != '5');
}

void mainMenu()
{
	system("cls");

	cout << "\n\n\n\n\t\t\t Login As: ";
	cout << "\n\n\n\n\t\t\t 1. Admin";
	cout << "\n\n\n\n\t\t\t 2. Student";
	cout << "\n\n\n\n\t\t\t 3. Exit";
	cout << "\n\n\n\n\t\t\t Enter your Choice: ";

	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		adminVerification();
		break;

	case 2:
		system("cls");

		cout << "Welcome as Student";
		studentFunction();
		break;

	case 3:
		system("cls");
		cout << "\t\t\n\n\n\n\n\n\t\t\t\t\tQuitting The program";

		for (int i = 0; i < 4; i++)
		{
			Sleep(1000);
			cout << ".";
		}

		exit(0);
		break;

	default:
		cout << "Invalid input";
	}

	system("pause");
}

// all functions for admin below
void deleteData()
{
	system("cls");

	//Open file pointers
	fstream fin, fout;

	//open the existing file
	fin.open("data.csv", ios::in);

	//create a new file to store the non-deleted data
	fout.open("datanew.csv", ios::out);

	int rollnum, roll1, marks, count = 0, i;
	/*char sub;
	int index, new_marks;*/
	string line, word;
	vector<string> row;

	//get the roll number
	// to decide data to be deleted
	cout << "Enter the roll number" << "of the record to be deleted: ";
	cin >> rollnum;

	//check if this record exists
	//if eexist, leave it and add data to the new file
	while (!fin.eof())
	{
		row.clear();

		getline(fin, line);
		stringstream s(line);

		while (getline(s, word, ','))
		{
			row.push_back(word);
		}
		int row_size = row.size();
		roll1 = stoi(row[0]);


		// writing all records,
		// except the record to be deleted
		//into the new file 'reportcardnew.csv'
		// using fout pointer
		if (roll1 != rollnum)
		{
			if (!fin.eof())
			{
				for (i = 0; i < row_size - 1; i++)
				{
					fout << row[1] << ",";
				}
				fout << row[row_size - 1] << "\n";
			}
		}
		else
		{
			count = 1;
		}
		if (fin.eof())
			break;
	}
	if (count == 1)
		cout << "Record deleted\n";
	else
		cout << "Record not found\n";

	//close the pointers
	fin.close();
	fout.close();

	//removing the existing file
	remove("data.csv");

	//renaming the new file with the existing filename
	rename("datanew.csv", "data.csv");

	Sleep(2000);

	adminFunction();


}
void addData()
{
	system("cls");
	fstream file("data.csv", ios::out | ios::app);
	if (!file)
	{
		cout << "\nFailed to open data.csv / data.csv file not found";
	}
	else
		cout << "\t|Enter Data|" << endl;

	string rollNumber, name, college, branch, attendance, physics, chemistry, maths;
	string moreData;

	cout << "\nEnter Student's roll Number: ";
	cin >> rollNumber;
	file << "\n" << rollNumber << ",";

	cout << "\nEnter Student's Name: ";
	cin >> name;
	file << name << ",";

	cout << "\nEnter College: ";
	cin >> college;
	file << college << ",";

	cout << "\nEnter Branch: ";
	cin >> branch;
	file << branch << ",";

	cout << "\nEnter Attendance: ";
	cin >> attendance;
	file << attendance << ",";

	cout << "\nEnter Pyhsic's mark: ";
	cin >> physics;
	file << physics << ",";

	cout << "\nEnter Chemisty's Mark: ";
	cin >> chemistry;
	file << chemistry << ",";

	cout << "\nEnter Maths Mark: ";
	cin >> maths;
	file << maths << ",";

	file.close();

	cout << "\nAdd more record? (Y / N)";
	cin >> moreData;
	if (moreData == "y" || moreData == "Y" || moreData == "yes" || moreData == "Yes")
	{
		addData();
	}
	else if (moreData == "n" || moreData == "N" || moreData == "no" || moreData == "No")
		adminFunction();

	else
		cout << "\nEnter a valid option";

	adminFunction();
}

void viewData()
{
	system("cls");

	fstream file("data.csv");


	if (!file)
	{
		cout << "fail in opening the file";
	}
	cout << "\n\t\t\t\t\t\t|Students Record| \n\n";

	cout << "\n---------------------------------------------------------------------------------------\n"
		<< endl
		<< endl;
	cout << "Roll \t Name \t\t\t College \t Branch \t Attendance \t Physics \t Chemistry \t Maths" << endl
		<< endl;
	string rollNumber, name, college, branch, attendance, physics, chemistry, maths;



	/*fstream file("data.csv");*/

	while (!file.eof())
	{
		getline(file, rollNumber, ',');
		getline(file, name, ',');
		getline(file, college, ',');
		getline(file, branch, ',');
		getline(file, attendance, ',');
		getline(file, physics, ',');
		getline(file, chemistry, ',');
		getline(file, maths, ',');

		cout << rollNumber << "\t" << name << "\t\t\t" << college << "\t\t" << branch << "\t\t"
			<< attendance << "\t\t" << physics << "\t\t" << chemistry << "\t\t" << maths << endl;
	}

	cout << "\n------------------------------------------------------------------------------------" << endl;
	file.close();

	cout << "\n\n 1. Add Record\n";
	cout << "2. Delete Record\n";
	cout << "3. Update Record\n";
	cout << "4. Main Menu\n";
	cout << "5. Exit\n";
	cout << "\n Enter Choice: ";
}

void adminVerification()
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
				<< "wrong password!, try again or type 'menu' to navigate to main menu";
			cout << "\n\n\n\t\t\t\tEnter password: ";
		}

		if (password == "Menu" || password == "menu" || password == "MENU")
		{
			mainMenu();
		}
	} while (password != "password");
	adminFunction();
}

void studentFunction()
{
	system("cls");

	fstream file("data.csv");

	if (!file)
	{
		cout << "fail in opening the file";

	}
	cout << "\n\t\t\t\t\t\t|Students Record| \n\n";

	cout << "\n---------------------------------------------------------------------------------------\n"
		<< endl
		<< endl;
	cout << "Roll \t Name \t\t\t College \t Branch \t Attendance \t Physics \t Chemistry \t Maths" << endl
		<< endl;
	string rollNumber, name, college, branch, attendance, physics, chemistry, maths;



	/*fstream file("data.csv");*/

	while (!file.eof())
	{
		getline(file, rollNumber, ',');
		getline(file, name, ',');
		getline(file, college, ',');
		getline(file, branch, ',');
		getline(file, attendance, ',');
		getline(file, physics, ',');
		getline(file, chemistry, ',');
		getline(file, maths, ',');

		cout << rollNumber << "\t" << name << "\t\t\t" << college << "\t\t" << branch << "\t\t"
			<< attendance << "\t\t" << physics << "\t\t" << chemistry << "\t\t" << maths << endl;
	}

	cout << "\n------------------------------------------------------------------------------------" << endl;
	file.close();
	system("pause");
	mainMenu();
}



