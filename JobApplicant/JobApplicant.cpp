#include <iostream>
#include <string>
#include <fstream>
using namespace std;

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

int main()
{
	int choice;
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
			cout << "Incorrect creditals!" << endl;
			system("PAUSE");
			return 0;
		}
		else
		{
			cout << "You're logged in!" << endl;
			system("PAUSE");
			return 1;
		}
	}
}
