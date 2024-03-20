#pragma once
#include <iostream>
#include <string>
#include "Employee.hpp"
using namespace std;
class Admin: public Employee 
{
	public:
		//Cons
		Admin(){}
		Admin(string name, int id, string password, double salary):Employee(name,id,password,salary){}
		//methods
		void addEmployee(Employee& employee){
			allEmployees.push_back(employee);
		}
		Employee* searchEmployee(int id){
			for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++)
			{
				if (eIt->getId() == id)return &(*eIt); 
			}
			return NULL;
		}
		void editEmployee(int id, string name, string password, double salary){
			searchEmployee(id)->setName(name);
			searchEmployee(id)->setPassword(password);
			searchEmployee(id)->setSalary(salary);
		}
		void listEmployee(){
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++)
			{
				eIt->Display();
				cout<<"--------------------------------------->"<<endl; 
			}
		}
		void Display()
		{
			cout<<"-------------------------------------------"<<endl;
			cout << "Admin" <<endl;
			cout << "ID "<<this->id<<endl;
			cout <<"Name "<<this->name<<endl;
			cout <<"Password "<<this->password<<endl;
			cout <<"Salary "<<this->salary<<endl;
		}
		~Admin(){}
};
static vector<Admin> allAdmin;
static vector<Admin>::iterator aIt;