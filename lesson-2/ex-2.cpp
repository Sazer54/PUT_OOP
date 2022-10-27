#include <iostream>
using namespace std;

class Lightbulb{
public:
    string manufacturer;
    int wattage;

    Lightbulb(){
        this->manufacturer = "Dell";
        this->wattage = 200;
    }
};

class Lamp {
public:
    bool hasLightbulb;
    Lightbulb lightbulb;
    string colour;
    float MSRP;

    Lamp() {
        this->hasLightbulb = false;
        this->colour = "black";
        this->MSRP = 120.99f;
    }

    void installLightbulb(Lightbulb lightbulb) {
        this->lightbulb = lightbulb;
        this->hasLightbulb = true;
    }

    void repaint(string newColour) {
        this->colour = newColour;
    }

    void reprice(float newMSRP) {
        this->MSRP = newMSRP;
    }

    string lightbulbInfo() {
        if (this->hasLightbulb)
            return "Manufacturer: " + this->lightbulb.manufacturer + "\nWattage: " +
             to_string(this->lightbulb.wattage);
        return "No lightbulb installed :(\n";
    }
};

int main()
{
    Lamp lamp;
    Lightbulb lightbulb;

    string lightbulbDesc = lamp.lightbulbInfo();
    cout<<lightbulbDesc;

    lamp.installLightbulb(lightbulb);
    lightbulbDesc = lamp.lightbulbInfo();
    cout<<lightbulbDesc;

    return 0;
}
