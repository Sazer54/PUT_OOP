#pragma once
#include <iostream>
using namespace std;
class Bank {
protected:
	string mName;
public:
	string name() {
		return mName;
	}
	virtual string code(string brandName) = 0;
};

class BankOfAmerica: public Bank {
public:
	BankOfAmerica() {
		mName = "Bank of America";
	}

	string code(string brandName) {
		if (brandName == "Visa") return "01829";
		if (brandName == "Mastercard") return "12073";
		if (brandName == "American Express") return "4314";
	}
};

class Wells : public Bank {
public:
	Wells() {
		mName = "Wells Fargo";
	}

	string code(string brandName) {
		if (brandName == "Visa") return "09028";
		if (brandName == "Mastercard") return "14030";
		if (brandName == "American Express") return "0034";
	}
};

class Citibank : public Bank {
public:
	Citibank() {
		mName = "Citibank";
	}

	string code(string brandName) {
		if (brandName == "Visa") return "03564";
		if (brandName == "Mastercard") return "13486";
		if (brandName == "American Express") return "4345";
	}
};