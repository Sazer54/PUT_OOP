#include <iostream>
#define DEAFULT_COLOUR "blue"
#define DEFAULT_CLICKS_LIMIT 10000
using namespace std;

class Pen {
public:
    bool isFunctional;
    string inkColour;
    int clicksLimit;

    Pen(bool isFunctional, string inkColour, int clicksLimit){
        this->isFunctional = isFunctional;
        this->inkColour = inkColour;
        this->clicksLimit = clicksLimit;
    }
    Pen(bool isFunctional, string inkColour):
         Pen(isFunctional, inkColour, DEFAULT_CLICKS_LIMIT){};
    Pen(bool isFunctional, int clicksLimit):
         Pen(isFunctional, DEAFULT_COLOUR, clicksLimit){};
};

int main()
{
    Pen myPen1(true, "black", 5000);
    Pen myPen2(true, "red");
    Pen myPen3(true, 8000);
    return 0;
}
