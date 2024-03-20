#pragma once
#include <iostream>
#include <vector>
#include "Person.hpp"
#include "Validation.hpp"

using namespace std;
class Client : public Person
{
private:
	//data member:
	double balance;
public:
	//Cons
	Client()
	{
		this->balance = 0.0;
	};
	Client(string name, int id, string password, double balance):Person(name,id,password)
	{
		while(true){
		  if(Validation::minBalance(balance))
		  {
				this->balance = balance;
				break;
		  }
		  else{
		  	cout<< "the balance is min 1500"<<endl;
		  	cin>>balance;
		  } 

		}
	};
	//Setter
	void setBalance(double balance)
	{
		while(true){
		  if(Validation::minBalance(balance))
		  {
				this->balance = balance;
				break;
		  }
		  else{
		  	cout<< "the balance is min 1500"<<endl;
		  	cin>>balance;
		  } 

		}
	}
	//Getter
	double getBalance()
	{
		return this->balance;
	}
	void deposit (double amount)
	{
		if (Validation::minBalance(amount))
		{
			this->balance += amount;
		}

	}
	void withdraw(double amount)
	{
		if (amount <= this->balance)
		{
			this->balance -= amount;
		}
	}
	void transferTo (double amount, Client& recipient)
	{
		this->withdraw(amount);
		recipient.deposit(amount);
	}
	void checkBalance()
	{
		cout << "Check Balance "<< this->balance<<endl;
	}
	void Display()
	{
		cout<<"-------------------------------------------"<<endl;
		cout << "Client" <<endl;
		cout << "ID "<<this->id<<endl;
		cout <<"Name "<<this->name<<endl;
		cout <<"Password "<<this->password<<endl;
		cout <<"Balance "<<this->balance<<endl;
	}
	~Client(){};
	
};
static vector<Client> allClient;
static vector<Client>::iterator clIt;