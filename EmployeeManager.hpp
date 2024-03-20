#pragma once
#include <iostream>
#include <string>
#include <chrono>

#include "FileManager.hpp"
#include "Employee.hpp"
#include "validation.hpp"
#include "FilesHelper.hpp"
class EmployeeManager {
public:
	static void PrintEmployeeMenu()
	{
		system("cls");
		cout << "1-Dispaly My Info: " <<endl;
		cout << "2-Update Password: " <<endl;
		cout << "3-Add new Client: " <<endl;
		cout << "4-Search for Clients: " <<endl;
		cout << "5-List all Clinets: " <<endl;
		cout << "6-Edit Client Info: " <<endl;
		cout << "7-Logout\n" <<endl;
	}
	static void back(Employee* employee)
	{
		cout <<endl;
		system("pause");
		employeeOptions(employee);
	}
	static void newClient(Employee* employee)
	{
		 string name , password;
            double balance ;
            cout<< "Enter Name : ";
            cin>> name;
            cout<< "Enter Password : " ;
            cin>>password;
            cout<< "Enter Balance : ";
            cin>>balance;
            int id;
		Client client;
		client.setId(FilesHelper::getLast("ClientLastId.txt") + 1 );
		client.setName(name);
		client.setPassword(password);
		client.setBalance(balance);
		employee->addClient(client);
		FileManager::updateClients();
		cout << "\nClient added successfully.\n";
	}
	static void searchForClient(Employee* employee)
	{
		int id;
		system("cls");
		cout << "Enter Client id: ";
		cin >> id;
		if (employee->searchClient(id) == NULL)cout << "\nClient not found.\n";
		else employee->searchClient(id)->Display();
	}
	static void listAllClients(Employee* employee)
	{
		system("cls");
		cout <<"All clients: \n";
		employee->listClient();
	}
	static void editClientInfo(Employee* employee)
	{
		int id;
		system("cls");
		cout <<"Enter clint id:";
		cin >>id;
		if (employee->searchClient(id) == NULL) cout <<"\nClient not found.. \n";
		else {
			string name, password;
			double balance;
			cout <<"Name :";cin>>name;
			cout <<"Password: "; cin>>password;
			cout <<"Balance: ";cin>>balance;
			employee->editClient(id,name,password,balance);
			FileManager::updateClients();
			cout << "\nClint info updated..\n";
		}
	}
	static Employee* login(int id, string password)
	{
		for (eIt = allEmployees.begin();eIt != allEmployees.end(); eIt++)
		{
			if (eIt->getId() == id && eIt->getPassword() == password)return &(*eIt);
			
		}
		return NULL;
	}
	static bool employeeOptions(Employee* employee)
	{
		PrintEmployeeMenu();
		cout <<"Your Choice is: ";
		int choise;
		cin>>choise;
		switch (choise)
		{
		case 1:
			system("cls");
			employee->Display();
			break;
		case 2:
			ClientManger::updatePassword(employee);
			FileManager::updateEmployees();
			break;
		case 3:
			newClient(employee);
			break;
		case 4:
			searchForClient(employee);
			break;
		case 5:
			listAllClients(employee);
			break;
		case 6:
			editClientInfo(employee);
			break;
		case 7:
			return false;
			break;
		default:
			system("cls");
			employeeOptions(employee);
			return false;
		}
		back(employee);
		return true;
	}
};