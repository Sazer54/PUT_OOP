// Udało mi się jakimiś pokrętnymi ścieżkami dojść do tego, jak zwracać metodą obiekt klasy abstrakcyjnej
// Wystarczy chyba dodać pointer do klasy nadrzędnej, a potem traktować to jak zwykły polimorfizm

#include <iostream>
#define PREFERABLE_DOGS_EYES_NUMBER 2
#define PREFERABLE_SPIDERS_EYES_NUMBER 8
#define MUTATION_TO_MOUTHS_RATIO 3
using namespace std;

class Animal {
public:
    virtual int eyesNumber() = 0;
    virtual int mouthsNumber() = 0;
    virtual string sound() = 0;
    virtual Animal* mutated(int mutationRate) = 0;
};

class Dog : public Animal {
private:
    int numberOfMouths;
    int numberOfEyes;
public:
    Dog() : Dog(0) {}
    Dog(int mutationLevel) {
        this->numberOfMouths = MUTATION_TO_MOUTHS_RATIO * mutationLevel + 1;
        this->numberOfEyes = PREFERABLE_DOGS_EYES_NUMBER * (mutationLevel + 1);
    }

    string sound() {
        string statement = "";
        for (int i = 0; i < this->numberOfMouths; i++) {
            statement += "woof woof\n";
        }
        return statement;
    }
    int eyesNumber() {
        return this->numberOfEyes;
    }
    int mouthsNumber() {
        return this->numberOfMouths;
    }
    Animal* mutated(int mutationLevel) {
        return new Dog(mutationLevel);
    }
};

class Spider : public Animal {
private:
    int numberOfMouths;
    int numberOfEyes;
public:
    Spider() : Spider(0) {}
    Spider(int mutationLevel) {
        this->numberOfMouths = MUTATION_TO_MOUTHS_RATIO * (mutationLevel) + 1;
        this->numberOfEyes = PREFERABLE_SPIDERS_EYES_NUMBER * (mutationLevel + 1);
    }
    string sound() {
        string statement = "";
        for (int i = 0; i < this->numberOfMouths; i++) {
            statement += "Making web ... \n";
        }
        return statement;
    }
    int eyesNumber() {
        return this->numberOfEyes;
    }
    int mouthsNumber() {
        return this->numberOfMouths;
    }
    Animal* mutated(int newMutationLevel) {
        return new Spider(newMutationLevel);
    }
};

int main()
{

    Dog perfectlyNormalDog;
    Spider perfectlyNormalSpider;

    Animal* suspiciousLookingSpider = perfectlyNormalSpider.mutated(2);
    Animal* suspiciousLookingDog = perfectlyNormalDog.mutated(3);
    
    cout << perfectlyNormalDog.sound() << endl;
    cout << perfectlyNormalSpider.sound() << endl;

    cout << suspiciousLookingDog->eyesNumber() << endl;
    cout << suspiciousLookingDog->mouthsNumber() << endl;
    cout << suspiciousLookingDog->sound() << endl;

    cout << suspiciousLookingSpider->eyesNumber() << endl;
    cout << suspiciousLookingSpider->mouthsNumber() << endl;
    cout << suspiciousLookingSpider->sound() << endl;

    return 0;
}
