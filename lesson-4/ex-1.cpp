#include <iostream>
#define PREFERABLE_DOGS_EYES_NUMBER 2
#define PREFERABLE_SPIDERS_EYES_NUMBER 8
using namespace std;

class Animal {
public:
    virtual string makeSound() = 0;
    virtual int eyesNumber() = 0;
    //virtual Animal& mutated(int mutationRate) = 0;
};

class Dog: public Animal{
private:
    int numberOfEyes;
public:
    Dog() {
        this->numberOfEyes = PREFERABLE_DOGS_EYES_NUMBER;
    }
    Dog(int numberOfEyes) {
        this->numberOfEyes = numberOfEyes;
    }
    string makeSound(){
        return "szczek szczek";
    }
    int eyesNumber() {
        return this->numberOfEyes;
    }
    /*Animal& mutated() {
        //nimal* mutatedVersion = Dog(this->numberOfEyes*2)
        //A mutatedVersion(this->numberOfEyes*2);
        return mutatedVersion;
    }*/
};

class Spider: public Animal{
private:
    int numberOfEyes;
public:
    Spider() {
        this->numberOfEyes = PREFERABLE_SPIDERS_EYES_NUMBER;
    }
    Spider(int numberOfEyes) {
        this->numberOfEyes = numberOfEyes;
    }
    string makeSound(){
        return "...";
    }
    int eyesNumber() {
        return this->numberOfEyes;
    }
    /*Animal& mutated() {
        Spider mutatedVersion(this->numberOfEyes*10);
        return mutatedVersion;
    }*/
};

int main(int argc, char argv[])
{
    Dog dog1;
    Spider spider1;
    Animal& first = dog1;
    Animal& second = spider1;
    //Spider spider2 = spider1.mutated();
    cout<<first.makeSound()<<endl;
    cout<<second.eyesNumber()<<endl;
    //cout<<spider2.eyesNumber();
    return 0;
}
