// Ata Kaleli 2385474
//I read and accept the submission rules and the extra rules specified in each question.This is my own work that is done by myself only.


#ifndef DAILYRENTALAPARTMENT_H
#define DAILYRENTALAPARTMENT_H
 
enum apartType { NotDefined, Minimalist, Modern, Classic };

class DailyRentalApartment :public Apartment {
private:
	apartType DecorationSytle;

public:
	DailyRentalApartment();
	DailyRentalApartment(int apartmentID, int numberOfRooms, int price, int size,int type,apartType DecorationStyle);
	int calculatePrice(int numberOfDays);
	void printApartment();
};
#endif