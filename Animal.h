#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
using namespace std;
//defining animal class
class Animal {
protected:
    string type;
    string name;
    int age;
    double weight;
    string color;
    string health;
    string sound;
public:
    //keeps track of total animal object created
    static int totalAnimals;
    //constructor with defualt parameter used to initialize new objects 
    Animal(string type = "Unknown", string name = "", int age = 0, 
    double weight = 0.0, 
           string color = "Unknown", string health = "Unknown", string sound 
           = "...");
    //virtual function used for different aspects of the animal
    //this can be overridden by derived classes
    virtual ~Animal();
    virtual void makeSound();
    virtual void printInfo();
    virtual void introduce(ostream& out);
};
#endif