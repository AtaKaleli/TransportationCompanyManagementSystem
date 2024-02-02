// Ata Kaleli 2385474
//I read and accept the submission rules and the extra rules specified in each question.This is my own work that is done by myself only.


#include<iostream>
using namespace std;

#include"Apartment.h"
#include"DailyRentalApartment.h"


DailyRentalApartment::DailyRentalApartment() :Apartment() {
	this->DecorationSytle = NotDefined;
}

DailyRentalApartment::DailyRentalApartment(int apartmentID, int numberOfRooms, int price, int size,int type, apartType DecorationStyle) : Apartment(apartmentID, numberOfRooms, price, size,type) {
	this->DecorationSytle = DecorationStyle;
}

int DailyRentalApartment::calculatePrice(int numberOfDays) {
	return numberOfDays * price;
}

void DailyRentalApartment::printApartment() {
	Apartment::printApartment();
	cout << "DecorationStyle: ";
	if (this->DecorationSytle == Minimalist) {
		cout << "Mininalist" << endl;
	}
	else if (this->DecorationSytle == Modern) {
		cout << "Modern"<< endl;
	}
	else if (this->DecorationSytle == Classic) {
		cout << "Classic" << endl;
	}
	else {
		cout << "NotDefined" << endl;
	}
}

