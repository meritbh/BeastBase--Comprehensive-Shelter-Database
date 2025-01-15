/*Homework 6 – Animal Shelter
Merit Bhusal
4/17/24
CS 1337.012
Purpose: The purpose of this code is to  write a small database system for an 
Animal Shelter. This is a no-kill shelter that accepts animal “donations” to
the shelter, but mostly only dogs and cats.It tracks all the animals in the 
shelter. It will add animals to the database and print reports based
on the database.
4/17/24 - I created the three classes and the dog and cat will be subclasses
add the differnt attributes to the classes. Make use of the csv file, where 
each line of the file will read in info for one animal. 
4/17/24 -instead of writing into the parent function write the specified data 
into the specific dog or cat class. 
4/18/24 - I made use of static the static variables to keep track of object 
created for each type. This will let me know the amount of animals created. 
4/19/24 - I seperated my files into h file and cpp files so that it is better 
read and used vectors to maintain the three different objects. I made it so the
input file data is read line by line and if the objects were missing i used hte 
default values to create the base class. 
4/21/24 - After reading the entire data base i made the four different reports,
for the toal animal amount, animal report, cat report , and dog report.  
Notes: Next time use your time more efficientyly and practice how to do the 
code segments in the book on your own time. I took too long with the easy 
stuff and left all the hard stuff till the end. 
Special features: Ther are a couple speacial features in my code. Mainly the 
debugging comments, which help the reader understant how the program wroks. 
*/
#include "Dog.h"
#include "Cat.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

//this function split a string by a delimiter into a vector of strings
vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    size_t start = 0;
    for (size_t i = 0; i <= s.length(); i++) {
        if (i == s.length() || s[i] == delimiter) {
            //the token gets extracted here 
            token = s.substr(start, i - start); 
            tokens.push_back(token);
            //start index moves past the delimiter
            start = i + 1; 
        }
    }
    return tokens;
}
//this function prints all reports using a single ostream reference
void printReports(ostream& out, const vector<Animal*>& allAnimals, 
const vector<Cat*>& cats, const vector<Dog*>& dogs) {
    //first report
    out << "Report 1: Summary of Animals\n";
    out << "Total Animals: " << Animal::totalAnimals << "\n";
    out << "Total Cats: " << Cat::numberOfCats << "\n";
    out << "Total Dogs: " << Dog::numberOfDogs << "\n\n";
    //second report
    out << "Report 2: Animal Introductions\n";
    for (const auto& animal : allAnimals) {
        animal->introduce(out);
    }
    out << "\n";
    //third report
    out << "Report 3: Cat Introductions\n";
    for (const auto& cat : cats) {
        cat->introduce(out);
    }
    out << "\n";
    //fourth report
    out << "Report 4: Dog Introductions\n";
    for (const auto& dog : dogs) {
        dog->introduce(out);
    }
    out << "\n";
}
int main() {
    ifstream file("Operations.csv");
    ofstream reportFile("reports.txt");
    // Debugging: Check if files have opened correctly
    // cout << "Debug: Checking if input file opened successfully: " 
    //<< file.is_open() << endl;
    // cout << "Debug: Checking if output file opened successfully: " 
    //<< reportFile.is_open() << endl;
    string line;
    vector<Animal*> allAnimals;
    vector<Dog*> dogs;
    vector<Cat*> cats;

    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }
    if (!reportFile.is_open()) {
        cout << "Error opening report file" << endl;
        return 1;
    }

    getline(file, line); 
    while (getline(file, line)) {
        vector<string> tokens = split(line, ',');
        // Debugging: Output the number of tokens parsed
        // cout << "Debug: Parsed " << tokens.size() << " tokens from line." 
        //<< endl;
        if (tokens.size() < 8) {
            //this skips incomplete lines
            // Debugging: Log skipped line due to insufficient data
            // cout << "Debug: Skipped line due to insufficient tokens: " << line << endl;
            continue; 
        }
        //take out type of the animal from the first token 
        string type = tokens[0];
        //take out name of the animal from the second token 
        string name = tokens[1];
        //take out age of the animal from the third token and convert to integer
        //0 is the default value if the token is empty
        int age = !tokens[2].empty() ? stoi(tokens[2]) : 0;
        //take out weiht of the animal from the fourth token and converttodouble
        //0.0 is the default value if the token is empty
        double weight = !tokens[3].empty() ? stod(tokens[3]) : 0.0;
        //take out breed of the animal from the fifth token
        string breed = tokens[4];
        //take out color of the animal from the sixth token
        string color = tokens[5];
        //take out health status of the animal from the seventh token
        string health = tokens[6];
        //take out sound that the animal makes from the eighth token
        string sound = tokens[7];
        // Debugging: Log details of the animal being processed
        // cout << "Debug: Processing animal of type " << type << " with name " << name << endl;
        if (type == "dog") {
            //parsed attributes used to make new dog object
            Dog* dog = new Dog(name, age, weight, breed, color, health, sound);
            //add new dog object to the vector of dogs
            dogs.push_back(dog);
            //add dog object to the regular vector aswell
            allAnimals.push_back(dog);
            //do the same as before here but for cat
            // Debugging: Log creation of a new dog
            // cout << "Debug: Created new dog named " << name << endl;
        } else if (type == "cat") {
            Cat* cat = new Cat(name, age, weight, breed, color, health, sound);
            cats.push_back(cat);
            allAnimals.push_back(cat);
            //do the same here 
            // Debugging: Log creation of a new cat
            // cout << "Debug: Created new cat named " << name << endl;
        } else {
            Animal* animal = new Animal(type, name, age, weight, color, health,
            sound);
            allAnimals.push_back(animal);
            // Debugging: Log creation of a new general animal
            // cout << "Debug: Created new animal of type " << type << " named " << name << endl;
        }
    }
    // Debugging: Start report generation
    // cout << "Debug: Starting report generation." << endl;

    //this outputs the reports to console 
    printReports(cout, allAnimals, cats, dogs);

    //this ouputs report to file
    printReports(reportFile, allAnimals, cats, dogs);
    
    // Debugging: Completion of report generation
    // cout << "Debug: Report generation completed and written to file." << endl;
    reportFile.close();
    return 0;
}