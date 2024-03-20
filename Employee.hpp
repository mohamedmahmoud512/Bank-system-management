#pragma once
#include <iostream>
#include "Person.hpp"
#include "Validation.hpp"
using namespace std;
class Employee : public Person
{
protected:
	//data members
	double salary;
public:
	//Dist
	Employee()
	{
		this->salary = 0;
	}
	Employee(string name, int id, string password, double salary):Person(name,id,password)
	{
		while(true)
		{
			if (Validation::minSalary(salary))
			{
			this->salary = salary;
			break;
			} else {
			cout << "the salary is min 5000, pelase enter above 5000"<<endl;
			cin>>salary;
			}
		}
	}
	//Setter
	void setSalary(double salary)
	{
		if (Validation::minSalary(salary))
		{
			this->salary = salary;
		}
	}
	//Getter
	double getSalary()
	{
		return this->salary;
	} 
	//Methods

	void addClient(Client& client){
		allClient.push_back(client);
	}
	Client* searchClient(int id){
		for (clIt = allClient.begin(); clIt != allClient.end(); clIt++)
		{
			if (clIt->getId() == id)return &(*clIt);
		}
		return NULL;
	}
	void listClient(){
		for (clIt = allClient.begin(); clIt != allClient.end(); clIt++)
		{
			clIt->Display();
			cout << "----------------------------->"<<endl;
		}
	}
	void editClient(int id, string name, string password, double balance) {
		searchClient(id)->setName(name);
		searchClient(id)->setPassword(password);
		searchClient(id)->setBalance(balance);
	}
	void Display()
	{
		cout<<"------------------------------------------->"<<endl;
		cout << "Employee" <<endl;
		cout << "ID "<<this->id<<endl;
		cout <<"Name "<<this->name<<endl;
		cout <<"Password "<<this->password<<endl;
		cout <<"Salary "<<this->salary<<endl;
	}
	~Employee(){}
};
static vector<Employee> allEmployees;
static vector<Employee>::iterator eIt;