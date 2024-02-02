// Ata Kaleli 2385474
//I read and accept the submission rules and the extra rules specified in each question.This is my own work that is done by myself only.


#ifndef APARTMENT_H
#define APARTMENT_H

class Apartment {
protected:
	int apartmentID;
	int numberOfRooms;
	int price;
	int size;
	int type;// I added an additional attribute to apartment, which is namely type, represents the type of the apartment. (0 for daily rental, 1 for monthly rental aparment)
public:
	Apartment();
	Apartment(int apartmentID, int numberOfRooms, int price, int size,int type);
	void setApartmentID(int apartmentId);
	void setNumberOfRooms(int numberOfRooms);
	void setPrice(int price);
	void setSize(int size);
	void setType(int type);
	int getApartmentID();
	int getNumberOfRooms();
	int getPrice();
	int getSize();
	int getType();
	virtual void printApartment();//I used virtual to print the details of my apartment considering its type. Based on the type, print result will change.
	virtual int calculatePrice(int numberOfDays);// I used virtual for this function too. If the apartment is daily rental, I used directly the number of days, if it is monthly, I used (numberOFdays/30)+1
	
};
#endif 