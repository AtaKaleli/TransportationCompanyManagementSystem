// Ata Kaleli 2385474
//I read and accept the submission rules and the extra rules specified in each question.This is my own work that is done by myself only.

#ifndef AGENCY_H
#define AGENCY_H


class Building;
class Agency {
private:
	char* name;
	Building* buildings[50];
	int numberOfBuildings;
public:
	Agency();
	Agency(const char* name);
	Agency(const Agency& othA);
	~Agency();
	void operator=(const Agency& othA);
	const char* getName();
	int getNumberOfBuildings();
	void setName(const char* name);
	void addBuilding(Building& newB);
	void printBuildingWithAddress();
	void printBuildingWithAllDetails();
	void printApartmentWithAllDetails();
	void printApartmentConsideringRooms(int rooms);
	void printApartmentConsideringSize(int size);
	void printApartmentConsideringCheaper(int numberOfDays, int price);
	void printConsideringRentalType(int type);
	void calculateRentalPriceConsideringID(int ID, int numberOfDays);
};
#endif