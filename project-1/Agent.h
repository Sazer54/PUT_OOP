#pragma once
#include <iostream>
#include "CreditCard.h"
#include "Banks.h"
using namespace std;

class Agent {
private:
	Agent() {}
public:
	static Agent& instance() {
		static Agent mInstance;
		return mInstance;
	}

	void askMenuAction(int& menuAction) {
		cout << "Choose action:\n1. View cards\n2. Generate new card\n3. Validate my cards\n4. Quit\n";
		cin >> menuAction;
	}

	void displayCards(vector<CreditCard*> creditCards) {
		system("cls");
		if (creditCards.size() == 0) {
			cout << "-------------------\nYOU HAVE NO CARDS\n-------------------\n";
		}
		else {
			cout << "----------------\nDISPLAYING CARDS\n----------------\n";
			int counter = 1;
			for (CreditCard* card : creditCards) {
				cout << "Card no. " << (counter++)
					<< "\nCard number: "
					<< card->formattedNumber()
					<< "\nBrand: "
					<< card->brandName()
					<< "\nBank: "
					<< card->bank()->name()
					<< "\n-------------\n";
			}
		}
	}

	void askBankChoice(int& bankChoice) {
		bool bankChosen = false;
		while (!bankChosen) {
			system("cls");
			cout << "------------\nCHOOSE BANK\n------------\n1. Bank of America\n2. Wells Fargo\n3. Citibank\n";
			cin >> bankChoice;
			if (!(bankChoice != 1 && bankChoice != 2 && bankChoice != 3)) {
				bankChosen = true;
			}
		}
	}

	Bank* determineBank(int bankChoice) {
		switch (bankChoice)
		{
		case 1:
			return new BankOfAmerica;
		case 2:
			return new Wells;
		case 3:
			return new Citibank;
		}
	}

	void askBrandChoice(int& brandChoice) {
		bool brandChosen = false;
		while (!brandChosen) {
			cout << "---------------------\nCHOOSE BRAND\n---------------------\n1. Visa\n2. Mastercard\n3. American Express\n";
			cin >> brandChoice;
			if (!(brandChoice != 1 && brandChoice != 2 && brandChoice != 3)) {
				brandChosen = true;
			}
		}
	}

	void askScamChoice(bool& scamChoice) {
		bool scamChosen = false;
		int scamChoiceAsInt = 0;
		while (!scamChosen) {
			cout << "Do you want the source to be legit (0) or shady (1)? ";
			cin >> scamChoiceAsInt;
			if (scamChoiceAsInt == 0 || scamChoiceAsInt == 1) {
				scamChosen = true;
			}
		}
		scamChoice = scamChoiceAsInt == 1 ? true : false;
	}

	void printCardGenMsg() {
		system("cls");
		cout << "------------------------\nCARD GENERATED SUCCESSFULLY!\n------------------------\n";
	}

	void askCardId(int& cardId, int numberOfCards) {
		bool cardIdSelected = false;
		while (!cardIdSelected) {
			cout << "Enter ID of card u wish to valdate: ";
			cin >> cardId;
			if (!(cardId > numberOfCards)) {
				cardIdSelected = true;
			}
		}
	}

	void printValidatingMsg(string num) {
		system("cls");
		cout << "------------------------\nValidating "	<< num << "...";
	}

	void printIsValidMsg(pair<bool, int> validityCheck) {
		printf(validityCheck.first ? "\nCard is valid" : "\nCard is invalid");
		printf("\nThe correct checksum is: %d\n-------------------------\n", validityCheck.second);
	}
};