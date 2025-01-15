// RunTimePolymorphism.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;

// Abstract class and pure virtual function
class CarModel {
public:
	int carTemplateSN;
	string companyName;
	static int templateSoldUnits;

	CarModel() : carTemplateSN(100), companyName("Default Company under CarModel") { setSoldNums(); }

	CarModel(int carTemplateSN, string companyName) : carTemplateSN(carTemplateSN), companyName(companyName) { setSoldNums(); }

	CarModel(CarModel* other) : carTemplateSN(other->carTemplateSN), companyName(other->companyName) {}

	void static setSoldNums() {
		CarModel::templateSoldUnits += 1;
	}

	int static getSoldNums() {
		return CarModel::templateSoldUnits;
	}

	// Creating pure virtual function to make class abstract
	virtual void displayFeature()
		/*{
			cout << endl << "Car Model Features: " << endl;
			cout << "Car Template Serial Number: " << carTemplateSN << endl;
			cout << "Car Company Name: " << companyName << endl;
			cout << "Total Template sold: " << (CarModel::getSoldNums()) << endl << endl;
		} */
		= 0;
};

class Jaguar : virtual public CarModel {
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

	Jaguar(Jaguar* other) : CarModel(other), jaguarSQ(other->jaguarSQ), jaguarPrice(other->jaguarPrice) { setSoldNums(); }

	Jaguar(CarModel* carModel, int jaguarSQ, double jaguarPrice) : CarModel(carModel), jaguarSQ(jaguarSQ), jaguarPrice(jaguarPrice) { setSoldNums(); }

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

	// Static polymorphism: operator overloading
	friend ostream& operator<< (ostream& os, const Jaguar& jaguar) {
		os << endl << "Welcome to Jaguar." << endl;
		os << "Company Name: " << jaguar.companyName << endl;
		os << "Company Serial Number: " << jaguar.carTemplateSN << endl;
		os << "Jaguar Serial Number: " << jaguar.jaguarSQ << endl;
		os << "Jaguar Price: " << jaguar.jaguarPrice << endl;
		os << "Jaguar Total Sold Units: " << (Jaguar::getSoldNums()) << endl << endl;

		return os;
	}
};

class Audi : virtual public CarModel {
public:
	int audiSQ;
	double audiPrice;
	static int audiSoldUnits;

	Audi() : CarModel(), audiSQ(100), audiPrice(75.5) { setSoldNums(); }

	Audi(int carTemplateSN, string companyName, int audiSQ, double audiPrice)
		: CarModel(carTemplateSN, companyName), audiSQ(audiSQ), audiPrice(audiPrice)
	{
		setSoldNums();
	}

	Audi(Audi* other) : CarModel(other), audiSQ(other->audiSQ), audiPrice(other->audiPrice) { setSoldNums(); }

	Audi(CarModel* carModel, int audiSQ, double audiPrice) : CarModel(carModel), audiSQ(audiSQ), audiPrice(audiPrice) { setSoldNums(); }

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

	friend ostream& operator<< (ostream& os, const Audi& audi) {
		os << endl << "Welcome to Audi." << endl;
		os << "Company Name: " << audi.companyName << endl;
		os << "Company Serial Number: " << audi.carTemplateSN << endl;
		os << "Audi Serial Number: " << audi.audiSQ << endl;
		os << "Audi Price: " << audi.audiPrice << endl;
		os << "Audi Total Sold Units: " << (Audi::getSoldNums()) << endl << endl;

		return os;
	}
};

class Segment : public Jaguar, public Audi {
public:
	string type = "Brand new";

	void displayFeature() {
		cout << endl << "Welcome to Segment." << endl;
		cout << "Company Name: " << companyName << endl;
		cout << "Company Serial Number: " << carTemplateSN << endl;
		cout << "Jaguar Serial Number: " << jaguarSQ << endl;
		cout << "Jaguar Price: " << jaguarPrice << endl;
		cout << "Audi Serial Number: " << audiSQ << endl;
		cout << "Audi Price: " << audiPrice << endl;
		cout << "Segment type: " << type << endl << endl;
	}
};

int CarModel::templateSoldUnits = 0;
int Jaguar::jaguarSoldUnits = 0;
int Audi::audiSoldUnits = 0;

int main()
{
	Jaguar* sg = new Segment;
	sg->displayFeature();

	/*Audi* sg2 = new Segment;
	sg2->Segment::Audi::displayFeature();*/

	return 0;
}