#pragma once
#include "DataSourceInterface.hpp"
#include "FilesHelper.hpp"

class FileManager : public DataSourceInterface{
public:
	 static void addClient(Client c) {
	 	FilesHelper::saveClient(c);
	 } 
	 static void addEmployee(Employee e){
	 	FilesHelper::saveEmployee("Employee.txt","EmployeeLastId.txt",e);
	 }
	 static void addAdmin(Admin a) {
	 	FilesHelper::saveEmployee("Admin.txt","AdminLastId.txt",a);
	 }

	 static void getAllClients() {
	 	FilesHelper::getClients();
	 }
	 static void getAllEmployees(){
	 	FilesHelper::getEmployees();
	 }
	 static void getAllAdmins(){
	 	FilesHelper::getAdmins();
	 }
	 static void getAllData(){
	 	getAllClients();
	 	getAllEmployees();
	 	getAllAdmins();
	 }
	 static void updateClients(){
	 	removeAllClients();
	 	for (clIt = allClient.begin();clIt != allClient.end();clIt++) addClient(*clIt);
	 }
	static void updateEmployees(){
	 	removeAllEmployees();
	 	for (eIt = allEmployees.begin();eIt != allEmployees.end();eIt++) addEmployee(*eIt);
	 }
	 static void updateAdmins(){
	 	removeAllAdmins();
	 	for (aIt = allAdmin.begin();aIt != allAdmin.end() ; aIt++) addAdmin(*aIt);
	 }

	 static void removeAllClients(){
	 	FilesHelper::clearFile("Client.txt","ClientLastId.txt");
	 }
	 static void removeAllEmployees() {
	 	FilesHelper::clearFile("Employee.txt","EmployeeLastId.txt");
	 }
	 static void removeAllAdmins() {
	 	FilesHelper::clearFile("Admin.txt","AdminLastId.txt");
	 }

};