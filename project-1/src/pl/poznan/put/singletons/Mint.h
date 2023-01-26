#pragma once
#include <iostream>
#include <string>
#include <random>
#include <cmath>

using namespace std;
class Mint {
private:
	Mint() {}

	string generatePersonalId(int personalIdLength) {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<unsigned long long> dis(0, pow(10,personalIdLength-1)-1);
		unsigned long long num = dis(gen);
		string numAsString = to_string(num);
		int numberOfZerosToAdd = personalIdLength - numAsString.length();
		string zerosPrefix = "";
		for (int i = 0; i < numberOfZerosToAdd; i++) {
			zerosPrefix += '0';
		}

		return zerosPrefix + to_string(num);
	}

	int sumOfDigits(int num) {
		int sum = 0;
		while (num > 0) {
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}

	int generateChecksum(string payload, bool isScam) {
		if (isScam) {
			srand(time(NULL));
			return rand() % 10;
		}

		int* multipliers = new int[payload.length()];
		int currentMultiplierValue = 2;
		for (int i = 0; i < payload.length(); i++) {
			multipliers[payload.length() - 1 - i] =
				currentMultiplierValue == 2 ?
				currentMultiplierValue-- :
				currentMultiplierValue++;
		}
		int* digitsToSum = new int[payload.length()];
		for (int i = 0; i < payload.length(); i++) {
			digitsToSum[i] = sumOfDigits((payload[i] - '0') * multipliers[i]);
		}
		int sum = 0;
		for (int i = 0; i < payload.length(); i++) {
			sum += digitsToSum[i];
		}
		int checkSum = (10 - (sum % 10) % 10);
		return checkSum;
	}

public:
	static Mint& instance() {
		static Mint mInstance;
		return mInstance;
	}

	string generateCardNumber(string prefix, string bankCode, int PIDLength, bool isScam) {
		string payload = prefix + bankCode + this->generatePersonalId(PIDLength);
		return payload + (to_string(this->generateChecksum(payload, isScam)));
	}
	
	pair<bool, int> isValid(string cardNumber) {
		string payload = cardNumber.substr(0, cardNumber.length()-1);
		string checksumToValidate = cardNumber.substr(cardNumber.length() - 1, 1);
		int validChecksum = this->generateChecksum(payload, false);
		return make_pair((to_string(validChecksum) == checksumToValidate), validChecksum);
	}
};