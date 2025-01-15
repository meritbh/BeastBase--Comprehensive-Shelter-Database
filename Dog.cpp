#include "Dog.h"
#include <iostream>  
using namespace std;  

int Dog::numberOfDogs = 0;

Dog::Dog(string name, int age, double weight, string breed, 
         string color, string health, string sound)
: Animal("Dog", name, age, weight, color, health, sound), breed(breed) {
    //whenever dog created static counter is incremented
    numberOfDogs++;  
    myDogNumber = numberOfDogs;  
    // Debugging: Log creation of a dog
    // cout << "Debug: Dog created with Name: " << name << " and Breed: " << breed << endl;
}

void Dog::printInfo() {
    //outputs common attributes
    Animal::printInfo();  
    cout << "Breed: " << breed << endl; 
    // Debugging: Print additional breed information
    // cout << "Debug: Additional Breed Info for Dog: " << breed << endl;
}

void Dog::introduce(ostream& out) {
    out << sound << "- I am " << name << ", a " << breed << " dog. Age: " << age
       << ", Weight: " << weight << " kg, Color: " << color
       << ", Health: " << health << "." << endl;  
    // Debugging: Log introduction message specific to dogs
    // cout << "Debug: Dog introduction sent to output stream for " << name << endl;
}
