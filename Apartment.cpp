// Ata Kaleli 2385474
//I read and accept the submission rules and the extra rules specified in each question.This is my own work that is done by myself only.


#include<iostream>
using namespace std;

#include"Apartment.h"
#include"DailyRentalApartment.h"
#include"MonthlyRentalApartment.h"

Apartment::Apartment() {
	this->apartmentID = 0;
	this->numberOfRooms = 0;
	this->price = 0;
	this->size = 0;
	this->type = -1;
}

Apartment::Apartment(int apartmentID, int numberOfRooms, int price, int size,int type) {
	this->apartmentID = apartmentID;
	this->numberOfRooms = numberOfRooms;
	this->price = price;
	this->size = size;
	this->type = type;
}

void Apartment::setApartmentID(int apartmentID) { this->apartmentID = apartmentID; }

void Apartment::setNumberOfRooms(int numberOfRooms) { this->numberOfRooms = numberOfRooms; }

void Apartment::setPrice(int price) { this->price = price; }

void Apartment::setSize(int size) { this->size = size; }

void Apartment::setType(int type) { this->type = type; }

int Apartment::getApartmentID() { return this->apartmentID; }

int Apartment::getNumberOfRooms() { return this->numberOfRooms; }

int Apartment::getPrice() { return this->price; }

int Apartment::getSize() { return this->size; }

int Apartment::getType() { return this->type; }

void Apartment::printApartment() {
	cout << "ApartmentID: " << this->apartmentID << ", ";
	cout << "NumberOfRooms: " << this->numberOfRooms << ", ";
	cout << "Rent: " << this->price << " GBP," << endl;
	cout << "Size: " << this->size << ", ";
}

int Apartment::calculatePrice(int numberOfDays) {
	if (this->type == 0) {
		return (this->price) * numberOfDays;
	}
	else {
		return this->price * (numberOfDays / 30)+1;
	}
		
}