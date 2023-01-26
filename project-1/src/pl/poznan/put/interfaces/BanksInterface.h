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

