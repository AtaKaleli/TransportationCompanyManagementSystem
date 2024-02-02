// Ata Kaleli 2385474
//I read and accept the submission rules and the extra rules specified in each question.This is my own work that is done by myself only.


#ifndef BUILDING_H
#define BUILDING_H

class Apartment;

class Building {
private:
	int buildingID;
	char* Address;
	Apartment* apartments[50];
	int numberOfApartments;
public:
	Building();
	Building(int buildingID, const char* Address);
	Building(const Building& othB);
	~Building();
	void operator=(const Building& othB);
	int getBuildingID();
	const char* getAddress();
	int getNumberOfApartments();
	void setBuildingID(int buildingID);
	void setAddress(const char* Address);
	void addApartment(Apartment& newA);
	void printApartmentWithAllDetails();
	void printApartmentConsideringRooms(int rooms);
	void printApartmentConsideringSize(int size);
	void printApartmentConsideringCheaper(int numberOfDays,int price);
	void printConsideringRentalType(int type);
	void calculateRentalPriceConsideringID(int ID,int numberOfDays);
	void printBuildingWithAddress();
	void printBuildingWithAllDetails();
};

#endif