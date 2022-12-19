#include <iostream>
#include "CreditCard.h"
#include "Banks.h"
#include "Agent.h"


int main()
{
	Bank* bank;
	CreditCard* consumerCard;
	vector<CreditCard*> creditCards;
	int menuChoice, brandChoice, bankChoice;
	bool quit = false;
	bool isScam;
	while (!quit) {
		Agent::instance().askMenuAction(menuChoice);
		switch (menuChoice)
		{
		case 1:
			Agent::instance().displayCards(creditCards);
			break;
		case 2:
			Agent::instance().askBankChoice(bankChoice);
			bank = Agent::instance().determineBank(bankChoice);
			Agent::instance().askBrandChoice(brandChoice);
			Agent::instance().askScamChoice(isScam);
			switch (brandChoice)
			{
			case 1:
				consumerCard = new VisaCreditCard(bank, isScam);
				break;
			case 2:
				consumerCard = new MastercardCreditCard(bank, isScam);
				break;
			case 3:
				consumerCard = new AmericanExpressCreditCard(bank, isScam);
				break;
			default:
				break;
			}			
			creditCards.push_back(consumerCard);
			Agent::instance().printCardGenMsg();
			break;
		case 3:
			int cardToValidate;
			Agent::instance().displayCards(creditCards);
			if (creditCards.size() != 0) {				
				Agent::instance().askCardId(cardToValidate, creditCards.size());
				Agent::instance().printValidatingMsg(creditCards.at(cardToValidate - 1)->formattedNumber());
				pair<bool, int> validityCheck = Mint::instance().isValid(creditCards.at(cardToValidate - 1)->number());
				Agent::instance().printIsValidMsg(validityCheck);
			}	
			break;
		case 4:
			quit = true;
			break;
		default:
			system("cls");
			break;
		}
	}
	for (int i = 0; i < creditCards.size(); i++) {
		delete creditCards.at(i);
	}
	
}
