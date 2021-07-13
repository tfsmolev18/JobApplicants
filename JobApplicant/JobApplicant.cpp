#include <iostream>
#include <string>
#include <cstring>
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

bool isLoggedInAdmin()
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
    system("cls");
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

    string fileName = ID + ".txt";
    ifstream fin(fileName);
    ofstream file;
    if (fin.good()) 
    {
        cout << "Could not create applicant because ID " << fileName << " is already taken";
    }
    else 
    {
        cout << "Applicant was added successfully";
        file.open(fileName);
    }
    file << "ID - " << ID << endl << "username - " << username << endl << "first name - " << firstName << endl << "last name - " << lastName << endl << "address - " << address << endl << "education level -" << education << endl << "years of experience - " << yearOfExperience;
    file.close();
}

void editApplicant()
{
    string fileName;
    cout << "Enter the ID of the applicant you are looking for" << endl;
    getline(cin, fileName);
    getline(cin, fileName);
    string textFile = fileName + ".txt";
    ifstream file(textFile);

    if (file.good()) 
    {
        cout << "Youre now editing " << textFile << endl;
        file.open(textFile);
    }
    else 
    {
        cout << "Looks like there is no applicant with such ID " << endl;
    }
}

void deleteApplicant()
{

}

void adminChoice()
{
    string choice;
    cout << "Enter 1 if you want to add an applicant, 2 if you want to edit applicant's information or 3 if you want to delete one" << endl;
    cin >> choice;
    if (choice == "1")
    {
        addApplicant();
    }
    else if (choice == "2")
    {
        editApplicant();
    }
    else if (choice == "3")
    {
        deleteApplicant();
    }
}


int main()
{
    int choice;
    int adminStatus;
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
        cout << "Registered successfully!";
        return 0;
    }
    else if (choice == 2)
    {
        cout << "Enter 1 if you want to login as an user or 2 if you want to login as an admin" << endl;
        cin >> adminStatus;
        if (adminStatus == 1)
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
                system("cls");
            }
        }
        else
        {
            bool adminStatus = isLoggedInAdmin();
            if (!adminStatus)
            {
                cout << "Incorrect credentials!" << endl;
                system("PAUSE");
                return 0;
            }
            else
            {
                cout << "You're logged in!" << endl;
                system("PAUSE");
                system("cls");
                adminChoice();
            }
        }
    }
}