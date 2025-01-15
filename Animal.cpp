#include "Animal.h"
#include <iostream> 

using namespace std;

int Animal::totalAnimals = 0;

Animal::Animal(string type, string name, int age, double weight, 
               string color, string health, string sound)
: type(type), name(name), age(age), weight(weight), color(color), 
health(health), sound(sound) {
    //whenever animal counter is created static counter is incremented
    totalAnimals++;  
    // Debugging: Log creation of an animal
    // cout << "Debug: Animal created with Type: " << type << " Name: " << name << endl;
}

Animal::~Animal() {
    // Debugging: Log destruction of an animal
    // cout << "Debug: Animal destroyed with Name: " << name << endl;
}

void Animal::makeSound() {
    //animal sound to standard output
    cout << sound << endl;  
    // Debugging: Log the sound made by the animal
    // cout << "Debug: Animal making sound: " << sound << endl;
}

void Animal::printInfo() {
    cout << "Type: " << type << ", Name: " << name << ", Age: " << age
         << ", Weight: " << weight << " kg, Color: " << color
         << ", Health: " << health << ", Sound: " << sound << endl;
}

void Animal::introduce(ostream& out) {
    out << sound << "! I am " << name << ". I'm a " << type << ". Age: " << age 
       << ", Weight: " << weight << " kg, Color: " << color 
       << ", Health: " << health << "." << endl;
    // Debugging: Log introduction message
    // cout << "Debug: Introduction sent to output stream for " << name << endl;
}