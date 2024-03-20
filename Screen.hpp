#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <windows.h>

#include "AdminManager.hpp"
#include "EmployeeManager.hpp"
#include "ClientManger.hpp"
#include "FileManager.hpp"
#include "FilesHelper.hpp"
class Screen {
public:
	static void BankName(){
            cout << "U.S. Bank" << endl;
    }

    static void Welcome(){
        system("Color 0A");
        cout << "\t    @@       @@   @@@@@@    @@      @@       @@@@@@@@    @@  @  @  @@   @@@@@@\n";
        cout << "\t    @@   @   @@   @@        @@      @@       @@    @@    @@   @@   @@   @@\n";
        cout << "\t    @@  @@@  @@   @@@@@@    @@      @@       @@    @@    @@        @@   @@@@@@\n";
        cout << "\t    @@ @@ @@ @@   @@        @@      @@       @@    @@    @@        @@   @@\n";
        cout << "\t    @@       @@   @@@@@@    @@@@@@  @@@@@@   @@@@@@@@    @@        @@   @@@@@@\n";
        BankName();
		Sleep(3000);
		system("cls");
		system("Color 0f");
    }
    static void Invalid(int c){
        system("cls");
        cout << "Incorrect ID or Password" << endl;
        LoginScreen(c);
    }

	static void LoginOptions(){
	    cout << "Login AS: " << endl;
		cout << "(1) Admin" << endl;
		cout << "(2) Employee" << endl;
		cout << "(3) Client\n" << endl;
	}
	static int LoginAs(){
        LoginOptions();
        cout << "Please select an option to login!" << endl;
        int option;
        cin >> option;
        if(option == 1 || option == 2 || option == 3){
            system("cls");
            return option;
        }else{
            system("cls");
            cout << "Note: only a number from 1 to 3" <<  endl;
        	return LoginAs();
            }
        }
  static void Logout(){
            system("cls");
            LoginScreen(LoginAs());
        }
        static void LoginScreen(int c){
           int option = c;
           int id;
           string password;
           cout << "Please enter your ID: " << endl;
           cin >> id;
           cout << "Please enter your password" << endl;
           cin >> password;
           switch (option){
           case 1:
                if (AdminManager::login(id, password) != NULL) {
				   while (AdminManager::adminOptions(AdminManager::login(id, password)) != false);
                   Logout();
                }else{
                    Invalid(1);
                }
                break;
            case 2:
			     if (EmployeeManager::login(id, password) != NULL) {
				    while (EmployeeManager::employeeOptions(EmployeeManager::login(id, password)) != false);
				    Logout();
			     }else{
                     Invalid(2);
                 }
                break;
		   case 3:
			    if (ClientManger::login(id, password) != NULL){
				   while (ClientManger::clientOptions(ClientManger::login(id, password)) != false);
				   Logout();
			    }else{
			        Invalid(3);
                }
			    break;
           default:
			   system("cls");
               LoginOptions();
            }
        }

        static void RunApp(){
            FileManager::getAllData();
            Welcome();
            LoginScreen(LoginAs());
        }
};