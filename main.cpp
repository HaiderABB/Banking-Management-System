#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<regex>
#include<cstdlib>
#include<ctime>
#include<random>
#include<Classes.h>
#include<Functions.h>
using namespace std;
bool fraud;
int totalID;
int totalA;
int loanC = 0;
int totalTC;
int DayT;
int totalT;
int PIN;
int amount;
int loginC = 0;
int totalR;
ifstream read;
ofstream write;
string type;
int input;
string id;
string pass;
string name;
string CNIC;
string address;
string date;
long long int phoneNum;
int withDrawL;
int deposit;
bool check = false;
int hold;
int hold1;
int totalC;
int tax;
int _id;
int* idPtr;
int* amountPtr;

 
int main()
{     
	     readRecords();
		 Transaction* Tr;
		 Tr = new Transaction[totalT];
		 Transaction* TrC;
		 TrC = new Transaction[totalTC];
		 check = true;
	while (check)
	{
		cout << "---------------------------------------------------------" << endl;
		cout << "\n";
		cout << "                      Welcome to MEEZAN BANK                ";
		cout << "\n";
		cout << " Functions                                            Input" << endl;
		cout << "Sign-In as User Client                                  1" << endl;
		cout << "Sign-In as Company Client                               2" << endl;
		cout << "Sign-In as Bank Employee                                3" << endl;
		cout << "Open a new Account as User Client                       4" << endl;
		cout << "Open a new account as Company Client                    5" << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << "\n";
		cout << "Enter your option : " << endl;
		cin >> input;
		while (input < 1 || input>5)  
		{
			cout << "Enter Correct Option : " << endl;
			cin >> input;
		}
		if (input == 1)
		{
			SignInAsUserClient(Tr);
		}
		else if (input == 2)
		{
			SignInAsCompanyClient(TrC);
		}
		else if(input==3)
		{
			readManagerDetail();
			loginAsManager();
			SignInAsManager();
		}
		else if (input == 4)
		{
			SignUpAsUserClient();
		}
		else if (input == 5)
		{
			SignUpAsCompany();
		}
		cout << "Enter 1 to Exit, or any other digit to continue " << endl;
		cin >> input;
		if (input == 1)
			check = false;
		else check = true;
		system("cls");
	}
	delete[] Tr;
	Tr = nullptr;
	delete[] TrC;
	TrC = nullptr;
	delete[]idPtr;
	idPtr = nullptr;
	delete[]amountPtr;
	amountPtr = nullptr;
	cout << "---------------------------------------------------------" << endl;
	cout << "\n\n";
	cout << " BYE - BYE " << endl;
	cout << "\n\n";
	cout << "---------------------------------------------------------" << endl;
}