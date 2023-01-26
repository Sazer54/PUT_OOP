#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "BanksInterface.h"
#include "singletons/Mint.h"
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

