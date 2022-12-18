#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "Banks.h"
#include "Mint.h"
using namespace std;

class CreditCard {
protected:
	string mPrefix;
	Bank* mBank;
	string mNumber;
	string mBrandName;
	int mNumberLength;

	int pidLength() {
		return mNumberLength - mPrefix.length() - mBank->code(mBrandName).length() - 1;
	}

	void generateNumber(bool isScam) {
		mNumber = Mint::instance().generateCardNumber(mPrefix, mBank->code(mBrandName), pidLength(), isScam);
	}

public:
	virtual ~CreditCard() {
		delete mBank;
	}

	virtual string formattedNumber() = 0;

	string number() {
		return mNumber;
	};
	string prefix() {
		return mPrefix;
	}
	string brandName() {
		return mBrandName;
	}
	Bank* bank() {
		return mBank;
	}
};

class VisaCreditCard : public CreditCard {
public:
	VisaCreditCard(Bank* bank, bool isScam) {
		mPrefix = "4";
		this->mBank = bank;
		mNumberLength = 16;
		mBrandName = "Visa";
		generateNumber(isScam);
	}

	string formattedNumber() {
		string formatted = "";
		for (int i = 0; i < 4; i++) {
			formatted += this->mNumber.substr(i * 4, 4);
			if (i != 3) formatted += " ";
		}
		return formatted;
	}
};

class MastercardCreditCard : public CreditCard {
public:
	MastercardCreditCard(Bank* bank, bool isScam) {
		mPrefix = "5";
		this->mBank = bank;
		mNumberLength = 16;
		mBrandName = "Mastercard";
		generateNumber(isScam);
	}

	string formattedNumber() {
		string formatted = "";
		for (int i = 0; i < 4; i++) {
			formatted += this->mNumber.substr(i * 4, 4);
			if (i!=3) formatted += " ";
		}
		return formatted;
	}
};

class AmericanExpressCreditCard : public CreditCard{
private:
	void generatePrefix() {
		srand(time(NULL));
		int r = rand() % 2;
		mPrefix = r == 0 ? "34" : "37";
	}

public:
	AmericanExpressCreditCard(Bank* bank, bool isScam) {
		generatePrefix();
		this->mBank = bank;
		mNumberLength = 15;
		mBrandName = "American Express";		
		generateNumber(isScam);
	}

	string formattedNumber() {
		string formatted = "";
		formatted += mNumber.substr(0, 4);
		formatted += " ";
		formatted += mNumber.substr(4, 6);
		formatted += " ";
		formatted += mNumber.substr(10, 5);
		return formatted;
	}
};