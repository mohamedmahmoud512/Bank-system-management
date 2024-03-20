
#pragma once
#include <iostream>
#include <string>
using namespace std;
class Validation
{
public:
	static bool validName(string name)
	{
		for (int i = 0; i < name.length(); i++)
		{
			if (!isalpha(name[i]) || isspace(name[i]) || name.length() < 5 || name.length() > 20)
			{
				cout<<"Error your name. Characters only no numbers and no space and min size 5 to max 20!\n";
				return false;
			}
		}
		return true;
	}
	static bool validPassword(string password){
		for (int i = 0; i < password.length(); i++)
		{
			if(!isdigit(password[i]) || password.length() < 8 || password.length() > 20){
				cout << "Error your password, numbers only no Characters or space or symbol"<<endl;
				return false;
			}
		}
		return true;
	}
	static bool minBalance(double balance){
		if(balance < 1500)
		{
			cout << "min balance is 1500"<<endl;
			return false;
		}
		return true;
	}
	static bool minSalary(double salary){
		if(salary < 5000)
		{
			cout<<"min salary is 5000"<<endl;
			return false;
		}
		return true;
	}
};
