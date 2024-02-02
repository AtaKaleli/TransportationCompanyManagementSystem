// Ata Kaleli 2385474
//I read and accept the submission rules and the extra rules specified in each question.This is my own work that is done by myself only.


#ifndef MONTLYRENTALAPARTMENT_H
#define MONTLYRENTALAPARTMENT_H

class MonthlyRentalApartment :public Apartment {
private:
	bool hasFurniture;
public:
	MonthlyRentalApartment();
	MonthlyRentalApartment(int apartmentID, int numberOfRooms, int price, int size,int type, bool hasFurniture);
	int calculatePrice(int numberOfDays);
	void printApartment();
};
#endif
