// RunTimePolymorphism.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std; 

class CarModel {
public:
	int carTemplateSN;
	string companyName; 
	static int templateSoldUnits;

	CarModel() : carTemplateSN(100), companyName("Default Company under CarModel") { setSoldNums(); }

	CarModel(int carTemplateSN, string companyName): carTemplateSN(carTemplateSN), companyName(companyName){ setSoldNums(); }

	CarModel(CarModel *other) : carTemplateSN (other->carTemplateSN), companyName(other->companyName){ setSoldNums(); }

	
	void static setSoldNums() {
		CarModel::templateSoldUnits += 1;
	}

	int static getSoldNums() {
		return CarModel::templateSoldUnits;
	}


	virtual void displayFeature() {
		cout << endl<< "Car Model Features: " << endl;
		cout << "Car Template Serial Number: " << carTemplateSN << endl;
		cout << "Car Company Name: " << companyName << endl;
		cout << "Total Template sold: " << (CarModel::getSoldNums()) << endl << endl;
	}
};

class Jaguar : public CarModel {
public: 
	int jaguarSQ;
	double jaguarPrice;
	static int jaguarSoldUnits;

	Jaguar() : CarModel(), jaguarSQ(100), jaguarPrice(1.5) { setSoldNums(); }

	Jaguar(int carTemplateSN, string companyName, int jaguarSQ, double jaguarPrice) 
		: CarModel(carTemplateSN, companyName), jaguarSQ(jaguarSQ), jaguarPrice(jaguarPrice)
	{
		setSoldNums();
	}
	
	Jaguar(Jaguar *other) : CarModel(other), jaguarSQ(other->jaguarSQ), jaguarPrice(other->jaguarPrice){ setSoldNums(); }

	void static setSoldNums() {
		Jaguar::jaguarSoldUnits += 1;
	}

	int static getSoldNums() {
		return Jaguar::jaguarSoldUnits;
	}

	void displayFeature() {
		cout << endl << "Welcome to Jaguar." << endl;
		cout << "Company Name: " << companyName << endl;
		cout << "Company Serial Number: " << carTemplateSN << endl;
		cout << "Jaguar Serial Number: " << jaguarSQ << endl;
		cout << "Jaguar Price: " << jaguarPrice << endl;
		cout << "Jaguar Total Sold Units: " << (Jaguar::getSoldNums()) << endl << endl;
	}
};

class Audi : public CarModel {
public: 
	int audiSQ;
	double audiPrice;
	static int audiSoldUnits;

	Audi(): CarModel(), audiSQ(100), audiPrice(75.5){ setSoldNums(); }

	Audi(int carTemplateSN, string companyName, int audiSQ, double audiPrice)
		: CarModel(carTemplateSN, companyName), audiSQ(audiSQ), audiPrice(audiPrice) 
	{
		setSoldNums();
	}

	Audi(Audi* other) : CarModel(other), audiSQ(other->audiSQ), audiPrice(other->audiPrice) { setSoldNums(); }

	void static setSoldNums() {
		Audi::audiSoldUnits += 1;
	}

	int static getSoldNums() {
		return Audi::audiSoldUnits;
	}

	void displayFeature() {
		cout << endl << "Welcome to Audi." << endl;
		cout << "Company Name: " << companyName << endl;
		cout << "Company Serial Number: " << carTemplateSN << endl;
		cout << "Audi Serial Number: " << audiSQ << endl;
		cout << "Audi Price in Cr: " << audiPrice << endl;
		cout << "Audi Total Sold Units: " << (Audi::getSoldNums()) << endl << endl;
	}
};

int CarModel::templateSoldUnits = 0;
int Jaguar::jaguarSoldUnits = 0;
int Audi::audiSoldUnits = 0;

int main()
{
	Jaguar jaguar(501, "Jaguar Corp", 301, 1.5);
	CarModel* model = &jaguar;

	model->displayFeature();

	Audi audi(502, "Audi Corp", 601, 75.5);

	model = &audi;

	model->displayFeature();
}