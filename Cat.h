#ifndef CAT_H
#define CAT_H
#include "Animal.h"
using namespace std;
//defining cat class
class Cat : public Animal {
private:
    string breed;

public:
    //keeps track of total cat object created
    static int numberOfCats;
    int myCatNumber;

    Cat(string name = "", int age = 0, double weight = 0.0, string breed = 
    "Unknown", 
        string color = "Unknown", string health = "Unknown", string sound = 
        "Meow");
    void printInfo() override;
    void introduce(ostream& out) override;
};
#endif