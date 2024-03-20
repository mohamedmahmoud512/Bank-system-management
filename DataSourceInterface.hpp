#pragma once
#include <iostream>
#include <vector>
#include "Client.hpp"
#include "Employee.hpp"
#include "Admin.hpp"

using namespace std;
class DataSourceInterface
{
protected:
	 void addClient(Client c) {}; 
	 void addEmployee(Employee e) {};
	 void addAdmin(Admin a) {};

	 void getAllClients() {};
	 void getAllEmployees() {};
	 void getAllAdmins() {};

	 void removeAllClients() {};
	 void removeAllEmployees() {};
	 void removeAllAdmins() {};

};