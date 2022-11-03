#include <iostream>
#include <ctime>

using namespace std;

class Author{
private:
    string name;
    string surname;
    int age;
    bool likesPinappleOnPizza;

public:
    Author(string n, string s, int a, bool l) {
        this->name = n;
        this->surname = s;
        this->age = a;
        this->likesPinappleOnPizza = l;
    }

    void changeEatingPreferences() {
        this->likesPinappleOnPizza = !this->likesPinappleOnPizza;
    }

    string info() {
        return this->name + " " + this->surname + ", " + to_string(this->age)
        + " | " + (this->likesPinappleOnPizza ? "Pinapple lover" : "Pinapple hater");
    }
};


class Engine{
private:
    double marketShare;
    string name;
    Author* authors;
    string programmingLanguage;
    string dateOfLastUpdate;

public:
    Engine(double ms, string n, Author* a, string l, string lu) {
        this->marketShare = ms;
        this->name = n;
        this->authors = a;
        this->programmingLanguage = l;
        this->dateOfLastUpdate = lu;
    }

    void update() {
        time_t now = time(0);
        char *date = ctime(& now);
        this->dateOfLastUpdate = date;
    }

    string info() {
        string s = "";
        s += "Name: " + this->name + "Market share: "
                + to_string(this->marketShare)+ "\n"
                + "Programming language: " + this->programmingLanguage;
        for(Author a : &this->authors) {
           s+= "\n" + a.info();
        }
        return s;
    }
};


class Device{
private:
    string name;
    int screenSizeInInches;
    double marketShare;

public:
    Device(string n, int s, double ms) {
        this->name = n;
        this->screenSizeInInches = s;
        this->marketShare = ms;
    }

    int changeScreenSize(int newSize) {
        return (this->screenSizeInInches = newSize);
    }

    string info(){
        return this->name + " " + to_string(this->screenSizeInInches)
                + "\nMarket share: " + to_string(this->marketShare);
    }
};


class Game {
private:
    string dateOfRelease;
    Author* authors;
    Engine gameEngine;
    Device* supportedDevices;

public:
    Game(string date, Author* a, Engine e, Device* d){
        this->dateOfRelease = date;
        this->authors = a;
        this->gameEngine = e;
        this->supportedDevices = d;
    }

    string info() {
        string s = "";
        s+="date of release: " + this->dateOfRelease+"\n";
        s+="Authors: \n";
        for(Author a : this->authors) {
            s+=a.info()+"\n";
        }
        s+="Game engine: \n";
        s+=this->gameEngine.info();
        s+="Devices:\n";
        for(Device d : this->supportedDevices) {
            s+=d.info()+"\n";
        }
        return s;
    }
};

int main()
{
    Author firstAuthor("Szymon", "Skowronski", 21, false);
    Author secondAuthor("Kubus", "Bromber", 20, true);
    Author authors[2] = {firstAuthor, secondAuthor};

    Engine engine(20.2, "best engine", authors, "C++", "2022-11-03");

    Device device1("Iphone X", 10, 50.8);
    Device device2("Iphone XIII", 18, 49.2);
    Device devices[2] = {device1, device2};

    Game game("2022-11-03", authors, engine, devices);
    cout<<game.info()<<endl;

    return 0;
}
