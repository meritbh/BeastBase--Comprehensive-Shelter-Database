#ifndef DOG_H
#define DOG_H
#include "Animal.h"
using namespace std;
//defining dog class
class Dog : public Animal {
private:
    string breed;

public:
    //keeps track of total dog object created
    static int numberOfDogs;
    int myDogNumber;
    //constructor with defualt parameter used to initialize new objects 
    Dog(string name = "", int age = 0, double weight = 0.0, string breed =
    "Unknown", 
        string color = "Unknown", string health = "Unknown", string sound = 
        "Bark");
    void printInfo() override;
    void introduce(ostream& out) override;
};
#endif