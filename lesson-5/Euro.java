package com.company;

public class Euro implements Currency {
    private float balance;
    private FakeCantor cantor;

    public Euro(float balance){
        this.cantor = new FakeCantor();
        this.balance = balance;
    }

    public Euro(){
        this(0);
    }

    @Override
    public Currency addedCurrency(float value, String currency) {
        return new Euro(this.balance + value * (1/this.cantor.euroToRate(currency)));
    }

    @Override
    public Currency subtractedCurrency(float value, String currency) {
        Euro euroWithNewBalance = new Euro(this.balance - value * (1/this.cantor.euroToRate(currency)));
        try {
            if (Float.parseFloat(euroWithNewBalance.balance()) < 0) {
                throw new ArithmeticException("Negative balance");
            }
        }
        catch (ArithmeticException e) {
            e.printStackTrace();
        }
        return euroWithNewBalance;
    }

    @Override
    public String abbreviation() {
        return "EUR";
    }

    @Override
    public String symbol() {
        return "€";
    }

    @Override
    public String balance() {
        return Float.toString(this.balance);
    }

    @Override
    public float toDollarExchangeRate() {
        return this.cantor.euroToRate(this.abbreviation());
    }
}
