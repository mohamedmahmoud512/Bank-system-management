#pragma once
#include "Client.hpp"
#include "Employee.hpp"
#include "FileManager.hpp"
class ClientManger {
public:
	static void printClientMenu()
	{
		system("cls");
		cout <<"1-Dispaly My Info"<<endl;
		cout <<"2-Check Balance"<<endl;
		cout <<"3-Update Password"<<endl;
		cout <<"4-Withdraw"<<endl;
		cout <<"5-Deposit"<<endl;
		cout <<"6-Transfer amount"<<endl;
		cout <<"7-Logout"<<endl;
	}
	static void back(Client* client)
	{
		cout << endl;
		system("puse");
		clientOptions(client);
	}

    static void updatePassword(Person* person)
    {
    	string password;
    	cout << "Enter Password : ";
    	cin >> password;
    	if (Validation::validPassword(password))
    	{
    		person->setPassword(password);
    		cout <<"\nPassword Updated..."<<endl;
    	} else {
    		updatePassword(person);
    	}
    }
	
	static Client* login(int id, string password)
	{
		for (clIt = allClient.begin(); clIt != allClient.end(); clIt++)
		{
			if (clIt->getId() == id && clIt->getPassword() == password) return &(*clIt);
		}
		return NULL;
	}

	static bool clientOptions(Client* client)
	{
		printClientMenu();
		cout << "Your Choice is: ";
		Employee e;
		double amount;
		int n,id;
		cin >>n;
		switch(n){
		case 1:
			system("cls");
			client->Display();
			break;
		case 2:
			system("cls");
			client->checkBalance();
			break;
		case 3:
			system("cls");
			updatePassword(client);
			FileManager::updateClients();
			break;
		case 4:
			system("cls");
			cout << "Enter amount to Withdraw : ";
			cin>>amount;
			client->withdraw(amount);
			FileManager::updateClients();
		case 5:
			system("cls");
			cout << "Enter amount to deposit : ";
			cin >> amount;
			client->deposit(amount);
			FileManager::updateClients();
		case 6:
			system("cls");
			cout << "Enter Id.\n";
			cin>>id;
			while(e.searchClient(id) == NULL){
				cout << "Invalid id.\n";
				cout << "\nEnter ID :";
				cin>>id;
			}
			cout << "\n Enter anount to transfer: ";
			cin >> amount;
			client->transferTo(amount, *e.searchClient(id));
			FileManager::updateClients();
			break;
		case 7:
			return false;
			break;
		default:
			system("cls");
			clientOptions(client);
			return true;
		}
		back(client);
		return true;

	}	
};