#include <iostream>

using namespace std;

class Game {
public:
    virtual string result() = 0;
};

class FakeFootballGame : public Game {
public:
    string result() {
        return "20 points";
    }
};

int main()
{
    try {
        FakeFootballGame game;
        string result = game.result();
        if (result != "20 points") {
            throw exception("invalid game result");
        }
        else {
            cout << result;
        }
    }
    catch (const exception&e) {
        cout << e.what() << endl;
        return 1;
    }

    return 0;
}

