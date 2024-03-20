#pragma once
#include "Validation.hpp"
#include <iostream>
#include <string>
using namespace std;
class Person
{ 
protected:
	//data member
	string name;
	string password;
	int id;
public:
//Cons
Person ()
{
	this->name = "";
	this->id = 0;
	this->password = "";
}
Person (string name,int id, string password)
{
		this->setName(name);
		this->setPassword(password);
		this->id = id;
}
//Setter
	void setName(string name)
	{
		while(true)
		{
			if(Validation::validName(name))
			{
				this->name = name;
				break;
			} 
			else
			{
				cout<<"Invalid name"<<endl;
	            cout<<"Enter Valid Name(No space in Name:)"<<endl;
	            cin>>name;
			}
		}
	}
	void setId(int id)
	{
		this->id = id;
	}
	void setPassword(string password)
	{
		while(true)
		{
			if (Validation::validPassword(password))
			{
				this->password = password;
				break;
			} else {
	            cout<<"Invalid password"<<endl;
	            cout<<"Enter Valid Password(No space in password:)"<<endl;
	            cin>>password;
			}
		}
	}
//Getter
	string getName()
	{
		return this->name;
	}
	int getId()
	{
		return this->id;
	}
	string getPassword()
	{
		return this->password;
	}
};
