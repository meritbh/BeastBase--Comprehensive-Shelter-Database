# BeastBase--Comprehensive-Shelter-Database

Overview

This project implements a comprehensive Animal Shelter Database System designed to manage and track animals in a no-kill shelter. The program categorizes animals, primarily dogs and cats, and generates insightful reports based on their attributes and statuses. This application demonstrates object-oriented programming principles, file handling, and debugging techniques, making it an excellent showcase of programming expertise.

Note: This project was completed as part of the CS 1337 course during my freshman year at the University of Texas at Dallas.

Features

Animal Management

Tracks various animals with attributes like name, age, weight, breed, color, health, and sound.

Supports dynamic addition of animals using a CSV input file.

Organizes animals into specific categories (dogs, cats, or others).

Static Variables

Keeps track of the total number of animals, dogs, and cats.

Dynamic Polymorphism

Uses virtual functions for customized behavior in derived classes.

Report Generation

Produces four detailed reports:

Summary of total animals, cats, and dogs.

Detailed animal introductions.

Specific reports for cats.

Specific reports for dogs.

Outputs reports to both console and a file (reports.txt).

Debugging Features

Includes detailed debugging comments for easy troubleshooting and understanding of the program's flow.

Code Structure

Files

Animal.h / Animal.cpp: Base class for general animals.

Cat.h / Cat.cpp: Derived class for cats with specific attributes.

Dog.h / Dog.cpp: Derived class for dogs with specific attributes.

main.cpp: Entry point of the program.

Classes

Animal: Base class for all animals.

Attributes: type, name, age, weight, color, health, sound.

Static variable: totalAnimals.

Virtual functions: makeSound, printInfo, introduce.

Cat: Derived from Animal.

Additional attribute: breed.

Static variable: numberOfCats.

Dog: Derived from Animal.

Additional attribute: breed.

Static variable: numberOfDogs.

Notable Functions

split: Splits a string into tokens using a delimiter.

printReports: Generates and outputs reports based on the animal data.

Usage

Input File: Ensure a properly formatted CSV file (e.g., HW 6 - Operation Kindness.csv) is present in the project directory. Each line represents an animal with attributes separated by commas.

Example:

AnimalType,Name,Age,Weight,Breed,Color,Health,Sound
cat,Morris,9,3,,yellow,good,Moan
dog,Fido,5,7,,spotted,good,Bark

Compilation and Execution:

Compile the program: g++ main.cpp Animal.cpp Cat.cpp Dog.cpp -o AnimalShelter

Run the program: ./AnimalShelter

Output:

Console: Displays reports directly in the terminal.

File: Saves detailed reports in reports.txt.

Special Features

Default Values: Handles missing or incomplete data gracefully by applying default values.

Dynamic Memory Management: Allocates and deallocates memory for objects efficiently.

Report Customization: Generates tailored reports for cats and dogs, enhancing usability.

Future Enhancements

Add support for additional animal types.

Implement a GUI for user-friendly interaction.

Integrate a database for persistent data storage.

Learning Outcomes

This project demonstrates proficiency in:

Object-Oriented Programming (inheritance, polymorphism, encapsulation).

File I/O operations and data parsing.

Debugging and code optimization.

Dynamic memory management.

Effective use of C++ standard library features like vector.


Special Notes

This project emphasizes clean code, modular design, and practical application of programming concepts, showcasing skills that align with industry standards. The inclusion of debugging features and detailed reports highlights a focus on quality and user-centric development.

## Contact
If you find this project impressive and want to discuss potential opportunities, please feel free to reach out:

- **Email**: meritbhusal@gmail.com
- **LinkedIn**: [linkedin.com/in/merit-bhusal](https://www.linkedin.com/in/merit-bhusal-53304832b/)
- **GitHub**: [github.com/meritbh](https://github.com/meritbh)

Thank you for taking the time to review my project. I'm excited about the opportunity to contribute to innovative teams and grow as a software developer!

