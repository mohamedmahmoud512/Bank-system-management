#pragma once
#include <iostream>
#include <string>
#include "ClientManger.hpp"
#include "EmployeeManager.hpp"
#include "Employee.hpp"
#include "FilesHelper.hpp"

class AdminManager {
public:
	static void printAdminMenu()
	{
		system("cls");
		cout <<"1-Dispaly My Info" << endl;
		cout <<"2-Update Password " <<endl;
		cout <<"3-Add new Client "<<endl;
		cout <<"4-Search for Clients"<<endl;
		cout <<"5-List all Clinets "<<endl;
		cout <<"6-Edit Client Info "<<endl;
		cout <<"7-Add new Employee"<<endl;
		cout <<"8-Seach for Employee"<<endl;
		cout <<"9-List all Employee Info"<<endl;
		cout <<"10-Edit Employee Info "<<endl;
		cout << "11-Logout\n"<<endl;
	}
	static void back(Admin* admin)
	{
		cout << endl;
		system("pause");
		adminOptions(admin);
	}
	static Admin* login(int id, string password)
	{
		for (aIt = allAdmin.begin(); aIt != allAdmin.end(); aIt++)
		{
			if (aIt->getId() == id && aIt->getPassword() == password) return &(*aIt);
		}
		return NULL;
	}
	static void newEmployee(Admin* admin)
	{
		Employee e;
		string name , password;
		double salary;
			cout << "Name: ";
			cin>>name;
			cout << "Password: ";
			cin>>password;
			cout << "Salary: ";
			cin>>salary;
			e.setName(name);
			e.setPassword(password);
			e.setSalary(salary);
			e.setId(FilesHelper::getLast("EmployeeLastId.txt")+1);
			admin->addEmployee(e);
			FileManager::updateEmployees();
			cout <<"\nEmployee added successfully.\n ";
	}
	static bool adminOptions(Admin* admin)
	{
		printAdminMenu();
		string name, password;
		double salary;
		int id;
		cout << "Your Choice is : ";
		Employee e;
		int choise;
		cin>>choise;
		switch(choise)
		{
		case 1:
			system("cls");
			admin->Display();
			break;
		case 2:
			ClientManger::updatePassword(admin);
			FileManager::updateAdmins();
			break;
		case 3:
			EmployeeManager::newClient(admin);
			break;
		case 4:
			EmployeeManager::searchForClient(admin);
			break;
		case 5:
			EmployeeManager::listAllClients(admin);
			break;
		case 6:
			EmployeeManager::editClientInfo(admin);
			break;
		case 7:
			newEmployee(admin);
			break;
		case 8:
			system("cls");
			cout << "Enter Employee id: ";
			cin>>id;
			if (admin->searchEmployee(id) == NULL) cout <<"\n employee not found.\n";
			else admin->searchEmployee(id)->Display();
			break;

		case 9:
			system("cls");
			cout << "All emplyes: \n";
			admin->listEmployee();
			break;
		case 10:
			system("cls");
			cout << "Enter employte Id: ";
			cin>> id;
			if (admin->searchEmployee(id) == NULL)cout << "\nEmployee not Found.\n";
			else {
				string name , password;
				double salary;
				cout << "Name: ";
				cin>>name;
				cout <<"Password: ";
				cin>>password;
				cout << "Salary: ";
				cin>>salary;
				admin->editEmployee(id , name , password, salary);
				FileManager::updateEmployees();
				cout << "\nEmployee Info updated.\n";
			}
			break;
		case 11:
			return false;
			break;
		default:
			system("cls");
			adminOptions(admin);
			break;
		}
		back(admin);
		return true;
	}
	
};