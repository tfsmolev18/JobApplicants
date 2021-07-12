#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

struct Applicant
{
	int Id;
	string username;
	string firstName;
	string lastName;
	string address;
	string education;
	int yearOfExperience;
};

bool isLoggedIn()
{
	string username, password, username1, password1;
	cout << "Enter your username" << endl;
	cin >> username;
	cout << "Enter your password" << endl;
	cin >> password;
	ifstream read(username + ".txt");

	getline(read, username1);
	getline(read, password1);

	if (username1 == username && password1 == password)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void addApplicant()
{
	string ID;
	cout << "Enter applicant's ID" << endl;
	getline(cin, ID);
	string username;
	cout << "Enter applicant's username" << endl;
	getline(cin, username);
	string firstName;
	cout << "Enter applicant's first name" << endl;
	getline(cin, firstName);
	string lastName;
	cout << "Enter applicant's last name" << endl;
	getline(cin, lastName);
	string address;
	cout << "Enter applicant's address" << endl;
	getline(cin, address);
	string education;
	cout << "Enter applicant's level of education" << endl;
	getline(cin, education);
	string yearOfExperience;
	cout << "Enter applicant's years of experience" << endl;
	getline(cin, yearOfExperience);

	ofstream file;
	file.open(ID + " " + username + " "  + firstName + " " + lastName + " " + address + " " + education + " " + yearOfExperience + ".txt");
	file << ID << endl << username << endl << firstName << endl << lastName << endl << address << endl << education << endl << yearOfExperience;
	file.close();
}

int adminChoice()
{
	int choice;
	cout << "Enter 1 if you want to add an applicant, 2 if you want to edit applicant's information or 3 if you want to delete one" << endl;
	cin >> choice;
	if (choice == 1)
	{
		addApplicant();
	}
	else if (choice == 2)
	{
		return 3;
	}
	else if (choice == 3)
	{
		return 3;
	}
}

int main()
{
	/*int choice;
	cout << "Enter 1 if you want to register or 2 if you want to login" << endl;
	cin >> choice;
	if (choice == 1)
	{
		string username, password;

		cout << "Enter an username: ";
		cin >> username;
		cout << "Enter a password: ";
		cin >> password;

		ofstream file;

		file.open(username + ".txt");
		file << username << endl << password;
		file.close();
	}
	else if (choice == 2)
	{
		bool status = isLoggedIn();

		if (!status)
		{
			cout << "Incorrect credentials!" << endl;
			system("PAUSE");
			return 0;
		}
		else
		{
			cout << "You're logged in!" << endl;
			system("PAUSE");
			return 1;
		}
	}*/
	/*int adminMenuChoice;
	cout << "Enter 1 if you want to add an applicant, 2 if you want to edit applicant's information or 3 if you want to delete one" << endl;
	cin >> adminMenuChoice;
	system("PAUSE");
	if (adminMenuChoice == 1)
	{
		
	}*/
	cout << adminChoice() << endl;
}
