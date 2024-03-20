#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Client.hpp"
#include "Admin.hpp"
#include "Employee.hpp"
#include "Parser.hpp"
using namespace std;

class FilesHelper {
public:
	static void saveLastId(string fileName, int id){
			ofstream file;
			file.open(fileName);
			file << id;
			file.close();
	}
	static int getLast(string fileName){
		ifstream file;
		file.open(fileName);
		int id;
		file >> id;
		file.close();
		return id;
	}
	static void saveClient(Client c){
		int id = getLast("ClientLastId.txt");
		ofstream file;
		file.open("Client.txt");
		file << id + 1 << "&" << c.getName() <<"&"<< c.getPassword() <<"&"<< c.getBalance();
		saveLastId("ClientLastId.txt",id+1);
		file.close();
	}
	static void saveEmployee(string fileName, string lastIdFile, Employee e){
		int id = getLast(lastIdFile);
		ofstream file;
		file.open(fileName , ios::app);
		file << id + 1 << "&" << e.getName() <<"&"<< e.getPassword() <<"&"<< e.getSalary();
		saveLastId(lastIdFile, id+1);
		file.close();
	}
	static void getClients(){
		//cout <<"getClients"<<endl;
        ifstream file("Client.txt");
		string line;
		
		while(getline(file,line))
		{
			Client c = Parser::parseToClient(line);
			allClient.push_back(c);
		}
		file.close();
	}
	static void getEmployees(){
		ifstream file("Employee.txt");
		string line;
		while(getline(file,line)){
			Employee e = Parser::parseToEmployee(line);
			allEmployees.push_back(e);
		}
		file.close();
	}
	static void getAdmins(){
		string line;
		ifstream file("Admin.txt");
		while(getline(file,line))
		{
			Admin a = Parser::parseToAdmin(line);
			allAdmin.push_back(a);
		}
		file.close();
	}
	static void clearFile(string fileName, string lastIdFile){
       ofstream file(fileName);
       ofstream lastIdFileStream(lastIdFile);
        if (!file.is_open() || !lastIdFileStream.is_open())
        {
            cerr << "Failed to open file or lastIdFile." << endl;
            return;
        }
        file.close();
        lastIdFileStream.close();
        cout << "File cleared successfully." << endl;
   }
};