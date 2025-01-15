#include "Cat.h"
#include <iostream>  

using namespace std;  

int Cat::numberOfCats = 0;

Cat::Cat(string name, int age, double weight, string breed, 
         string color, string health, string sound)
: Animal("Cat", name, age, weight, color, health, sound), breed(breed) {
    //each time cat created static counter incremenmted
    numberOfCats++;  
    myCatNumber = numberOfCats;  
    // Debugging: Log creation of a cat
    // cout << "Debug: Cat created with Name: " << name << " and Breed: " << breed << endl;
}

void Cat::printInfo() {
    Animal::printInfo(); 
    cout << "Breed: " << breed << endl;  
    // Debugging: Print additional breed information
    // cout << "Debug: Additional Breed Info for Cat: " << breed << endl;
}

void Cat::introduce(ostream& out) {
    out << sound << "- I am " << name << ", a " << breed << " cat. Age: " << age
       << ", Weight: " << weight << " kg, Color: " << color
       << ", Health: " << health << "." << endl;  
    // Debugging: Log introduction message specific to cats
    // cout << "Debug: Cat introduction sent to output stream for " << name << endl;
}