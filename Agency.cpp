// Ata Kaleli 2385474
//I read and accept the submission rules and the extra rules specified in each question.This is my own work that is done by myself only.


#include<iostream>
#include"Agency.h"
#include"Building.h"

using namespace std;

Agency::Agency() {
	this->name = new char[15];
	strcpy(this->name, "Not Defined");
	this->numberOfBuildings = 0;
	for (int i = 0;i < 20;i++) {
		this->buildings[i] = NULL;
	}
}

Agency::Agency(const char* name) {
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
	this->numberOfBuildings = 0;
	for (int i = 0;i < 20;i++) {
		this->buildings[i] = NULL;
	}
}

Agency::Agency(const Agency& othA) {
	this->name = new char[strlen(othA.name) + 1];
	strcpy(this->name, othA.name);
	this->numberOfBuildings = othA.numberOfBuildings;
	for (int i = 0;i < 20;i++) {
		this->buildings[i] = othA.buildings[i];
	}
}

Agency::~Agency() {
	delete[] this->name;
}

void Agency::operator=(const Agency& othA) {
	delete[] this->name;
	this->name = new char[strlen(othA.name) + 1];
	strcpy(this->name, othA.name);
	this->numberOfBuildings = othA.numberOfBuildings;
	for (int i = 0;i < 20;i++) {
		this->buildings[i] = othA.buildings[i];
	}
}

const char* Agency::getName() { return this->name; }

int Agency::getNumberOfBuildings() { return this->numberOfBuildings; }

void Agency::setName(const char* name) {
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
//I dont write setter for numberOfBuilding, as it has to be incremented based on the building number

void Agency::addBuilding(Building& newB) {
	this->buildings[numberOfBuildings++] = &newB;
}
void Agency::printBuildingWithAddress() {
	
	for (int i = 0;i < numberOfBuildings;i++) {
		cout << "ID: " << this->buildings[i]->getBuildingID() << ", Address: " << this->buildings[i]->getAddress() << endl;
	}
}

void Agency::printBuildingWithAllDetails() {
	for (int i = 0;i < numberOfBuildings;i++) {
		cout << "ID: " << this->buildings[i]->getBuildingID();
		cout << ", Address: " << this->buildings[i]->getAddress() << endl;
	}
}

void Agency::printApartmentWithAllDetails() {
	
	for (int i = 0;i < numberOfBuildings;i++) {
		this->buildings[i]->printApartmentWithAllDetails();
	}
}

void Agency::printApartmentConsideringSize(int size) {
	for (int i = 0;i < numberOfBuildings;i++) {
		this->buildings[i]->printApartmentConsideringSize(size);
		cout << "\n";
	}
}

void Agency::printApartmentConsideringRooms(int rooms) {
	for (int i = 0;i < numberOfBuildings;i++) {
		this->buildings[i]->printApartmentConsideringRooms(rooms);
		cout << "\n";
	}
}

void Agency::printApartmentConsideringCheaper(int numberOfDays, int price) {
	for (int i = 0;i < numberOfBuildings;i++) {
		this->buildings[i]->printApartmentConsideringCheaper(numberOfDays, price);
		cout << "\n";
	}
}

void Agency::printConsideringRentalType(int type) {
	for (int i = 0;i < numberOfBuildings;i++) {
		this->buildings[i]->printConsideringRentalType(type);
		cout << "\n";
	}
}

void Agency::calculateRentalPriceConsideringID(int ID, int numberOfDays) {
	for (int i = 0;i < numberOfBuildings;i++) {
		this->buildings[i]->calculateRentalPriceConsideringID(ID, numberOfDays);
	}
}