package com.company;

public class Main {

    //Produce a message giving a balance review
    public static String balanceMessage(Currency currency) {
        return "Account balance: " + currency.balance() + currency.symbol();
    }

    public static void main(String[] args) {
        //First Euro object whose balance is 0
        Currency initialEuro = new Euro();

        //Adding 1 euro using JPY
        Currency firstAdded = initialEuro.addedCurrency(145.12f, "JPY");
        System.out.println(balanceMessage(firstAdded));

        //Adding 1 euro using GBP
        Currency secondAdded = firstAdded.addedCurrency(0.87063f, "GBP");
        System.out.println(balanceMessage(secondAdded));

        //Subtracting 1 euro using CHG
        Currency firstSubtracted = secondAdded.subtractedCurrency(0.9881f, "CHF");
        System.out.println(balanceMessage(firstSubtracted));

        //Subtracting 2 euro using USD - will cause an exception thrown by subtractedCurrency()
        Currency overSubtracted = firstSubtracted.subtractedCurrency(2*1.0366f, "USD");
    }
}
