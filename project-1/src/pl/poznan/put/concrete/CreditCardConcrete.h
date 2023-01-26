#pragma once
#include "./interfaces/CreditCardInterface.h"
#include "BanksConcrete.h"

class VisaCreditCard : public CreditCard {
public:
	VisaCreditCard(Bank* bank, bool isScam) {
		mPrefix = "4";
		this->mBank = bank;
		mNumberLength = 16;
		mBrandName = "Visa";
		generateNumber(isScam);
	}
	
	VisaCreditCard(Bank* bank) : VisaCreditCard(bank, 0) {}

	VisaCreditCard(bool isScam) : VisaCreditCard(new BankOfAmerica, isScam) {}

	VisaCreditCard() : VisaCreditCard(new BankOfAmerica, 0) {}

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

	MastercardCreditCard(Bank* bank) : MastercardCreditCard(bank, 0) {}

	MastercardCreditCard(bool isScam) : MastercardCreditCard(new BankOfAmerica, isScam) {}

	MastercardCreditCard() : MastercardCreditCard(new Wells, 0) {}

	string formattedNumber() {
		string formatted = "";
		for (int i = 0; i < 4; i++) {
			formatted += this->mNumber.substr(i * 4, 4);
			if (i != 3) formatted += " ";
		}
		return formatted;
	}
};

class AmericanExpressCreditCard : public CreditCard {
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

	AmericanExpressCreditCard(Bank* bank) : AmericanExpressCreditCard(bank, 0) {}

	AmericanExpressCreditCard(bool isScam) : AmericanExpressCreditCard(new Citibank, isScam) {}

	AmericanExpressCreditCard() : AmericanExpressCreditCard(new Citibank, 0) {}

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