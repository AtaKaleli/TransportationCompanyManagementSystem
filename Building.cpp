// Ata Kaleli 2385474
//I read and accept the submission rules and the extra rules specified in each question.This is my own work that is done by myself only.


#include<iostream>
using namespace std;

#include"Building.h"
#include"Apartment.h"


Building::Building() {
	this->buildingID = 0;
	this->numberOfApartments = 0;
	this->Address = new char[15];
	strcpy(this->Address, "Not Defined");
	for (int i = 0;i < 40;i++) {
		this->apartments[i] = NULL;
	}
}

Building::Building(int buildingID, const char* Address) {
	this->buildingID = buildingID;
	this->numberOfApartments = 0;
	this->Address = new char[strlen(Address)+1];
	strcpy(this->Address, Address);
	for (int i = 0;i < 40;i++) {
		this->apartments[i] = NULL;
	}
}

Building::Building(const Building& othB) {
	this->buildingID = othB.buildingID;
	this->numberOfApartments = othB.numberOfApartments;
	this->Address = new char[strlen(othB.Address) + 1];
	strcpy(this->Address, othB.Address);
	for (int i = 0;i < 40;i++) {
		this->apartments[i] = othB.apartments[i];
	}
}

Building::~Building() {
	delete[] this->Address;
}

void Building::operator=(const Building& othB) {
	delete[] this->Address;
	this->buildingID = othB.buildingID;
	this->numberOfApartments = othB.numberOfApartments;
	this->Address = new char[strlen(othB.Address) + 1];
	strcpy(this->Address, othB.Address);
	for (int i = 0;i < 40;i++) {
		this->apartments[i] = othB.apartments[i];
	}
}

int Building::getBuildingID() { 
	return this->buildingID; 
}

const char* Building::getAddress() { 
	return this->Address; 
}
int Building::getNumberOfApartments() { 
	return this->numberOfApartments; 
}

void Building::setBuildingID(int buildingID) { 
	this->buildingID = buildingID; 
}

void Building::setAddress(const char* Address) {
	delete[] this->Address;
	this->Address = new char[strlen(Address) + 1];
	strcpy(this->Address,Address);
}

void Building::addApartment(Apartment& newA) {
	this->apartments[numberOfApartments++] = &newA;
}

void Building::printApartmentWithAllDetails() {
	int notfound = 1;
	cout << "\nDaily Rental apartments: " << endl;
	for (int i = 0;i < numberOfApartments;i++) {
		if (this->apartments[i]->getType() == 0) {
			this->apartments[i]->printApartment();
			notfound = 0;
		}
	}
	if (notfound == 1) {
		cout << "Not found!" << endl;
	}
	notfound = 1;
	cout << "\nMonthly Rental apartments: " << endl;
	for (int i = 0;i < numberOfApartments;i++) {
		if (this->apartments[i]->getType() == 1) {
			this->apartments[i]->printApartment();
			notfound = 0;
		}
	}
	if (notfound == 1) {
		cout << "Not found!" << endl;
	}
}

void Building::printApartmentConsideringRooms(int rooms) {
	int notfound = 1;
	cout << "\nDaily Rental apartments: " << endl;
	for (int i = 0;i < numberOfApartments;i++) {
		if (this->apartments[i]->getNumberOfRooms() == rooms&&this->apartments[i]->getType()==0) {
			this->apartments[i]->printApartment();
			notfound = 0;
		}
	}
	if (notfound == 1) {
		cout << "Not found!";
	}
	notfound = 1;
	cout << "\nMonthly Rental apartments: " << endl;
	for (int i = 0;i < numberOfApartments;i++) {
		if (this->apartments[i]->getNumberOfRooms() == rooms && this->apartments[i]->getType() == 1) {
			this->apartments[i]->printApartment();
			notfound = 0;
		}
	}
	if (notfound == 1) {
		cout << "Not found!";
	}
}

void Building::printApartmentConsideringSize(int size) {
	int notfound = 1;
	cout << "\nDaily Rental apartments: " << endl;
	for (int i = 0;i < numberOfApartments;i++) {
		if (this->apartments[i]->getSize() > size && this->apartments[i]->getType() == 0) {
			this->apartments[i]->printApartment();
			notfound = 0;
		}
	}
	if (notfound == 1) {
		cout << "Not found!";
	}
	notfound = 1;
	cout << "\nMonthly Rental apartments: " << endl;
	for (int i = 0;i < numberOfApartments;i++) {
		if (this->apartments[i]->getSize() > size && this->apartments[i]->getType() == 1) {
			this->apartments[i]->printApartment();
			notfound = 0;
		}
	}
	if (notfound == 1) {
		cout << "Not found!";
	}
}

void Building::printApartmentConsideringCheaper(int numberOfDays, int price) {
	int notfound = 1;
	cout << "\Daily Rental apartments: " << endl;
	for (int i = 0;i < numberOfApartments;i++) {
		if (this->apartments[i]->calculatePrice(numberOfDays) < price && this->apartments[i]->getType() == 0) {
			this->apartments[i]->printApartment();
			notfound = 0;
		}
	}
	if (notfound == 1) {
		cout << "Not found!";
	}
	notfound = 1;
	cout << "\nMonthly Rental apartments: " << endl;
	for (int i = 0;i < numberOfApartments;i++) {
		if (this->apartments[i]->calculatePrice(numberOfDays) < price && this->apartments[i]->getType() == 1) {
			this->apartments[i]->printApartment();
			notfound = 0;
		}
	}
	if (notfound == 1) {
		cout << "Not found!";
	}
}

void Building::printConsideringRentalType(int type) {
	int notfound = 1;
	if (type == 0) {
		cout << "\Daily Rental apartments: " << endl;
		for (int i = 0;i < numberOfApartments;i++) {
			if (this->apartments[i]->getType() == 0) {
				this->apartments[i]->printApartment();
				notfound = 0;
			}
		}
		if (notfound == 1) {
			cout << "Not found!";
		}
	}
	else {
		notfound = 1;
		cout << "\nMonthly Rental apartments: " << endl;
		for (int i = 0;i < numberOfApartments;i++) {
			if (this->apartments[i]->getType() == 1) {
				this->apartments[i]->printApartment();
				notfound = 0;
			}
		}
		if (notfound == 1) {
			cout << "Not found!";
		}
	}
	
	
}
void Building::calculateRentalPriceConsideringID(int ID, int numberOfDays) {
	int notfound = 1;
	for (int i = 0;i < numberOfApartments;i++) {
		if (this->apartments[i]->getApartmentID() == ID) {
			cout<<this->apartments[i]->calculatePrice(numberOfDays);
			notfound = 0;
		}
	}
	if (notfound == 1) {
		cout << "Not found!";
	}
}

void Building::printBuildingWithAddress() {
	cout << "Address Detail of Building:" << endl;
	cout << "Address: " << this->Address;
}

void Building::printBuildingWithAllDetails() {
	cout << "ID: " << this->buildingID << endl;
	cout << "Address: " << this->Address << endl;
}


