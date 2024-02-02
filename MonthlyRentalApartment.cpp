// Ata Kaleli 2385474
//I read and accept the submission rules and the extra rules specified in each question.This is my own work that is done by myself only.


#include<iostream>
using namespace std;

#include"Apartment.h"
#include"MonthlyRentalApartment.h"

MonthlyRentalApartment::MonthlyRentalApartment() :Apartment() {
	this->hasFurniture = 0;
}

MonthlyRentalApartment::MonthlyRentalApartment(int apartmentID, int numberOfRooms, int price, int size, int type,bool hasFurniture) :Apartment(apartmentID, numberOfRooms, price, size,type) {
	this->hasFurniture = hasFurniture;
}

int MonthlyRentalApartment::calculatePrice(int numberOfDays) {
	return ((numberOfDays / 30)+1) * this->price;
}

void MonthlyRentalApartment::printApartment() {
	Apartment::printApartment();
	if (this->hasFurniture == true) {
		cout << "Furnished: Yes" << endl;
	}
	else {
		cout << "Furnished: No" << endl;
	}
}

