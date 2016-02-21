// This is a comment
/* 
	This is a multi-line comment
*/

// Compiling in terminal; version 11
	// g++ -std=c++11 filename.cpp
	// ./a.out

// Importing some libraries
#include <iostream> // Main library
#include <string>
#include <vector>
#include <fstream>  // File IO
#include <math.h>   // All the math functions
#include "myFunctions.h" // Here be the functions
	// Make sure to use "" and not < > for header files

#include "Animal.h"


using namespace std; // To avoid typing std:: all the time

///////////////////////////////////////////////////////
// Skip the following down to int main();
// Come back to it when you get to classes on line 548
///////////////////////////////////////////////////////


// ---------- Classes (declaration) ----------

	int Animal::numOfAnimals = 0;
	// How static variables are declared. Part of the class, not the object itself.

	void Animal::setAll(int height, int weight, string name) {
		this -> height = height;
		// Refers to the object not the class
		this -> weight = weight;
		this -> name = name;

		Animal::numOfAnimals++;
		// Increment the number of Animal objects created
	}

	// Constructor
	Animal::Animal(int height, int weight, string name) {
		this -> height = height;
		// Refers to the object not the class
		this -> weight = weight;
		this -> name = name;

		Animal::numOfAnimals++;
		// Increment the number of Animal objects created
	}

	// Destructor
	Animal::~Animal() {
		cout << "Animal " << this -> name << " destroyed" << endl;
	}

	// Overloaded constructor
	Animal::Animal() {
		Animal::numOfAnimals++;
	}

	void Animal::toString() {
		cout << this -> name << " is " << this -> height 
			 << " cms tall and " << this -> weight 
			 << " kgs in weight." << endl;
	}

	// End of class declarations

// ---------- Classes (Inheritance) ----------
	// Dog sub-class inheriting all the methods and attributes of parent.

	class Dog : public Animal {
	private:
		string sound;
	public:
		void setSound(string bark) {sound = bark;}
		void getSound() {cout << sound << endl;}
		void getFamily() {cout << "I'm a dog." << endl;}

	    void getClass() {cout << "I'm a doggie." << endl;}
		// Example of polymorphism, we expect the sub-class to overwrite this.

		// Constructors
		Dog(int, int, string, string);
		Dog() : Animal(){};

		// Destructor modification
		~Dog();

		void toString();
	}; // remember the ;

	// Constructor declaration
	Dog::Dog(int height, int weight, string name, string bark) : 
		Animal(height, weight, name) {
		// The new attribute
		this -> sound = bark;
	}
	Dog::~Dog() {
		cout << "Dog " << this -> echoName() << " destroyed" << endl;
	}
	// Note: both Dog and Animal destructor all called to release the Dog object.

	void Dog::toString() {
		cout << this -> echoName() << " is "
			 << this -> echoHeight() << " cms tall and "
			 << this -> echoWeight() << " kgs in weight"
			 << ", and it goes " << this -> sound 
			 << "."<< endl;
	}


// ---------- Classes (polymorphism) ----------
	class Samoyed : public Dog {
	public:
		void getClass() {cout << "I'm a Samoyed." << endl;}
	}; // remember the ;

void whatClassAreYou(Dog *someAnimal){
	someAnimal -> getClass();
}



///////////////////////////////////////////////
///////////////////////////////////////////////

int main(int argc, const char * argv[]) 
{

// Everything goes here.
	std::cout << "Hello World!"; // Call out
	cout << "Hello World! Again!" << endl; // End the line
	cout << "This is a new line" << endl;

// User input
// Won't work in Sublime though
	// string userInput;
	// cout << "Enter a character: " << endl;
	// getline(cin, userInput);
	// cout << "You entered: " << userInput << endl;


// ---------- Variables ----------
	cout << "---------- Variables ----------" << endl;
	const double PI = 3.1415926535;
	// const vars cannot be changed
	// Custom to make the all UPPERCASE
	char myGrade = 'A';
	// Only one letter
	// Single quotes used for chars
	// Will take up 1 bite in the memory
	bool someCondition = true; // or false
	int myAge = 123; 
	// 4 bytes
	// largest 32bit signed int: 2,147,483,647 (7FFF,FFFF)
	// 2^31 -1 .. is a prime number!
	float someNumber = 3.141592;
	// Accurate to 6 decimal places
	double anotherNumber = 3.1415926535;
	// Accurate to 15 decimal places
	// 8 bytes

	// Other types:
	// short int: At least 16 bits
	// long int: At least 32 bits
	// long long int: At least 64 bits
	// unsigned int: Same size as signed int, no sign
	// long double: Same as double

	cout << "Size of myAge is: " << sizeof(myAge) << " bytes; "
	     << "Value of myAge is: " << myAge 
	     << " and the grade I got was: " << myGrade << endl;


	// Overflow:
	int theLargestInteger = 2147483647;
	int plusOne = theLargestInteger + 1;
	cout << "The largest unsigned int is " << theLargestInteger
		 << " and if you add 1 to it you get " << plusOne
		 << endl;


	// Arithmetic:
	cout << "5/3 quotiant = " << 5/3 << endl; // 2
	cout << "5%3 remainder = " << 5%3 << endl; // 1
	cout << "5/3 typecasted to float = " << (float) 5/3 << endl;


	// Shortcuts for increments and decrements:
	int five = 5;
	int plusEquals = five += 6;
	cout << "5++ = " << five++ << endl; // five = 6
	cout << "++5 = " << ++five << endl; // five = 7
	cout << "5-- = " << five-- << endl; // five = 6
	cout << "--5 = " << --five << endl; // five = 5
	cout << "five +=6 = " << plusEquals << endl;


	// Order of Operation states * and / is performed before + and - 
	cout << "1 + 2 - 3 * 2 = " << 1 + 2 - 3 * 2 << endl;
	cout << "(1 + 2 - 3) * 2 = " << (1 + 2 - 3) * 2 << endl;

	// Random numbers
	int randomNumber = (rand() % 100) + 1; // modulo range
	// Psuedo random, smaller numbers more likely
	cout << "Your random number is: " << randomNumber << endl;


// ---------- Arrays ----------
	cout << "---------- Arrays ----------" << endl;
	// Zero indexed
	// Store multiple variables of the same type

	int myArrayOfNumbers[5];
	int moreNumbers[5] = {12, 23, 34, 45, 56};
	char twoDArray[2][3] = {{'A', 'S', 's'}, 
							{'P', 'J', 'k'}};

	cout << "(1,2) Element is " << twoDArray[1][2] << endl; 

	++moreNumbers[4];
	moreNumbers[0] += moreNumbers[1];
	cout << moreNumbers[4] << endl;
	cout << moreNumbers[0] << endl;


// ---------- Vectors ----------
	cout << "---------- Vectors ----------" << endl;
	// Like arrays but their size is variable
	vector <int> myNumberVector(10); // initialized to 0
	int numArray[5] = {22, 32, 51, 12, 42};

	myNumberVector.insert(myNumberVector.begin(), 1001);
	cout << myNumberVector.at(0) << endl;
	

	// vector.insert(Vector beginning, array or item, length of array)
	myNumberVector.insert(myNumberVector.begin() + 1, numArray,
						  numArray + 3);

	for (int i = 0; i < 10; i++) {
		cout << myNumberVector.at(i);
		if(i < 9) {
			cout << ", ";
		} else {
			cout << endl;
		}
	}   

	// Better way of populating vectors
	vector <int> myNumberVector2;
	cout << myNumberVector2.empty() << endl;
	// 1/true if empty, 0/false if not
	for (int i = 0; i < 5; i++) {
		myNumberVector2.push_back(numArray[i]);
	}
	myNumberVector2.push_back(666);

	for (vector <int>::iterator it = myNumberVector2.begin(); 
		 it != myNumberVector2.end(); it++) {
		cout << *it << ", ";
	} cout << '\n';

	// Finding the index of an element in a vector
	vector <int>::iterator pos;
	pos = find(myNumberVector2.begin(), myNumberVector2.end(),
			   667); // not in the vector
	if (pos == myNumberVector2.end()) {
		cout << "Element is not in this vector" << endl;
	} else {
		int index = pos - myNumberVector2.begin();
		cout <<  "666 is located at index: " << index << endl;	
	}

	// Other vector methods
	cout << myNumberVector2.size() << endl;
	myNumberVector2.pop_back();
	// pop out the last elemnt of the vector
	cout << myNumberVector2.back() << endl;
	cout << myNumberVector2.front() << endl;
	// and more: at, back, capacity, clear, reserve, resize ...


// ---------- Strings ---------- 
	cout << "---------- Strings ----------" << endl;
	char stringOfChars[7] = {'H', 'E', 'L', 'L', 'O', ' ', 0};
	// Strings are null terminated, hence the 0 or '\0'
	string someString = "World!";
	cout << someString << endl;
	cout << stringOfChars + someString << endl; // concatenation

	// String conversion, e.g. from keyboard inputs
	string numString = "3.1415";
	double stringValue = stod(numString); // string to double
	int stringValue2 = stoi(numString);
	cout << stringValue * 2 << " rounded down is "
	     << stringValue2 * 2 << endl;

	// String methods
	cout << "# chars in 'world!' is: " << someString.size() << endl;
	cout << "someString is empty? " << someString.empty() << endl;
	cout << someString.append(" is BIG!") << endl;
	cout << someString << endl;

	string wholeName;
	wholeName.assign("First Last");
	cout << wholeName << endl;
	string firstName;
	firstName.assign(wholeName); // this is assignment
	firstName.assign(wholeName, 0, 5); // This is slicing
	// string.assign(string, start index, # of chars)
	cout << firstName << endl;

	int indexOfLastName = wholeName.find("Last", 0);
	// string.find("sub string", start looking from index)
	string lastName = wholeName.assign(wholeName, indexOfLastName, 4);
	// string lastName.assign(wholeName); won't work!
	cout << lastName << endl;
	cout << wholeName << endl; // Notice how wholeName has changed
							   // after the assignment at 142. 

	wholeName.insert(0, firstName + ' ');
	// string.insert(index, substring)
	cout << wholeName << endl;

	wholeName.erase(6, 1);
	// string.erase(index, # of chars to erase)  
	cout << wholeName << endl;
	cout << wholeName.erase(6, 100) << endl;  // Not limited by size

	wholeName.replace(2, 3, "ona");
	// string.replace(index, # of chars, replace with)
	cout << wholeName << endl;

	// String comparison
	string foo = "foo";
	string bar = "bar";

	cout << foo.compare(bar) << endl; // chars have Numberic value
	cout << foo.compare(foo) << endl;
	cout << bar.compare(foo) << endl;


// ---------- Control Flow ----------
	cout << "---------- Control Flow ----------" << endl;
	// Comparison operators: ==, !==, >, <, >=, <=
	// Logical operators: && || ! (and, or, not)

	int age = 100;
	int ageAtlastExam = 96;
	bool isToxicated = false;

	if((age > 1 && age < 16)) {
		cout << "You can't drive." << endl;
	} else if(isToxicated) {
		cout << "You can't drive." << endl;
	} else if(age >= 80 && 
		(age >= 100 || age - ageAtlastExam > 5)) {
		cout << "You can't drive." << endl;
	} else {
		cout << "Happy driving!" << endl;
	}

	// Switch statement
	int greetingOption = 3;

	switch (greetingOption) {
		case 1: 
			cout << "Hello" << endl;
			break; // Break out of switch

		case 2:
			cout << "Hola" << endl;
			break;

		case 3:
			cout << "Salam" << endl;
			break;

		default :
			cout << "Press a number between 1-3" << endl;
	}

	// Ternary operator
	// Performs an assignment based on a condition
	// variable = (condition) ? if true : if false

	int a = 5;
	int b = 3;
	int biggerNumber = (a>b) ? a : b;
	cout << "Between the numbers " << a << " and " << b
		 << ", " << biggerNumber << " is the bigger number."
		 << endl;


// ---------- Loops and iterators ----------
	cout << "---------- Loops and iterators ----------" << endl; 
	// for(var; cond; increment){}
	for(int i = 1; i <= 10; i++) {
		cout << i << endl;
		if(i % 5 == 0) {
			break; // Stops the loop
		}
	}

	// Loop the loop
	int myTwoDimArray[2][5] = {{1, 2, 3, 4, 5},
							   {6, 7, 8, 9, 10}};
	for(int j = 0; j < 2; j++) {
		for(int k = 0; k < 5; k++) {
			cout << "Row j = " << j << " Col = " << k 
			<< " is: " << myTwoDimArray[j][k] << endl;
		}
	}		
  
	// While loop		
	// while(cond){}
	srand (time(NULL)); // Reset random number generator seed
	int myLuckyNumber = (rand() % 100) + 1;
	while(myLuckyNumber != 77) {
		cout << myLuckyNumber << ", ";
		myLuckyNumber = (rand() % 100) +1;
	}	cout << endl;

	// Do While loop
	// Want to execute the loop at least once
	// do{} while(cond);	


// ---------- Functions ----------
	cout << "---------- Functions ----------" << endl;

	// Refer to myFunction.h for definitions 

	someFunction(); 
	cout << "2 + 0 = " << addNumbers(2) << endl;
	cout << "2 + 3 + 5 = " << addNumbers(2, 3, 5) << endl;
	// same function, overloaded!

	// Recursive functions: calls itself
 	cout << "6! = " << calFactorial(6) << endl;



// ---------- File I/O ----------
 	cout << "---------- File I/O ----------" << endl;
 	string someParagraph = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec a aliquam lectus. Mauris sodales, diam at gravida pulvinar, lorem felis pretium dui, sit amet lobortis felis eros id arcu. Suspendisse lobortis velit eget mi viverra, et efficitur lacus ullamcorper. Duis fermentum eros a diam laoreet, egestas porta dui accumsan. In et pretium mi. Donec eu orci quis arcu eleifend fermentum id non est. Proin eu nibh bibendum, commodo est ac, fringilla ex. Nullam viverra vehicula magna tristique pellentesque.";

 	ofstream writer("LoremIpsumFile.txt");

 	if(! writer) {
 		cout << "Error opening file" << endl;
 		return -1;
 	} else {
 		writer << someParagraph << endl;
 		writer.close();
 	}

	// ios::app : Append to an existing file
	// ios::binary : Treat the file as binary
	// ios::in : Open a file to read input
	// ios::trunc : Default
	// ios::out : Open a file to write output

	ofstream writer2("LoremIpsumFile.txt", ios::app);
	// appending example

	if(! writer2) {
 		cout << "Error opening file" << endl;
 		return -1;
 	} else {
 		writer2 << "\n - A wise man." << endl;
 		writer2.close();
 	}

 	// Reading from a file:
 	char letter;

 	ifstream reader("LoremIpsumFile.txt");

 	if(! reader) {
 		cout << "Error opening file" << endl;
 		return -1;
 	} else {
 		for (int i = 0; ! reader.eof(); i++) {
 			reader.get(letter);
 			cout << letter;
 		}
 		cout << endl;
 		reader.close();
 	}

// ---------- Exception handling ----------
 	cout << "---------- Exception handling ----------" << endl;
 	int number = 0;
 	int toBeDivided = 5;

 	try{
 		if (number !=0) {
 			cout << "All is good" << endl;
 			cout << toBeDivided << "/" << number << " = "
 			<< (float) toBeDivided/number << endl;
 		} else throw(number);
 	} catch(int number) {
 		cout << "Can't divide by 0!" << endl;
 	}


// ---------- * Pointers & references ----------
 	cout << "---------- * Pointers & references ----------" << endl;
 	// Useful for 'passing by reference' to functions
 	// Kinda like using a global variable
 	int someValue = 24;
 	int* valuePtr = &someValue;
 	// Pointer the same data type as the referenced object
 	cout << "someValue is located at " << &someValue << endl;
 	// & is the 'reference operator'
 	cout << "The value stored at " << valuePtr 
 		 << " is: " << *valuePtr << endl;
 	// This is called de-referencing!

 	int someArray[5] = {1, 2, 3, 4, 5};
 	int* numArrayPtr = someArray;
 	// No need to reference; array name is actually a pointer to the
 	// first element of an array.

 	cout << "Address " << numArrayPtr << " Value " << *numArrayPtr << endl;
 	numArrayPtr++;
 	cout << "Address " << numArrayPtr << " Value " << *numArrayPtr << endl;
 	// Can iterate through an array

 	// Pass by reference to a function
 	int theAnswer = 0;
 	cout << "The answer used to be " << theAnswer ;
 	changeGlobally(&theAnswer); // passed the address
 	cout << " but it is now " << theAnswer << endl;

 	int& ansRef = theAnswer;
 	passByRef(ansRef); // passed by reference
 	cout << "Now the answer is: " << theAnswer << endl;
 	
 	// Difference pointers vs. references: Use pointers where you
 	// don't want to have to initialize at declaration.


// ---------- Classes ----------
 	cout << "---------- Classes ----------" << endl;
 	Animal ralphie;
 	// Default constructor
 	Animal moosha(42, 26, "Moosha");
 	// Constructor with attributes
 	Animal mooshi;
 	Animal mooshmoosh;

 	ralphie.setHeight(40);
 	ralphie.setWeight(25);
 	ralphie.setName("Ralphie");

 	cout << ralphie.echoName() << " is " << ralphie.echoHeight()
 		 << " cms tall." << endl;

 	ralphie.toString();
 	moosha.toString();
 	cout << "Number of animals created = " 
 		 << Animal::getNumOfAnimals()
 		 << endl;


 	// Inheritance:
 	Dog buddy(23,55, "Buddy", "woof");
 	buddy.toString();
 	
 	// Calling a super-class method of the 
 	// :: is called the "scope operator"
 	buddy.Animal::toString();

 	cout << "Number of animals created = " 
 		 << Animal::getNumOfAnimals()
 		 << endl;

 	// Polymorphism
 	Dog *dog = new Dog;
 	Samoyed *samoyed = new Samoyed;

 	dog -> getClass();
 	samoyed -> getClass();

 	// But if we try to do this from a function:
 	whatClassAreYou(dog);
 	whatClassAreYou(samoyed);
 	// will return "I'm a doggie" for both.

 	/* solution: change
 	void getClass() {cout << "I'm a doggie." << endl;}
 	// to
 	virtual void getClass() {cout << "I'm a doggie." << endl;}
 	// in the super-class, which is Dog here.
 	// It will tell the compiler to expect a modification to the virtual method in the sub-class, which is Samoyed here.
 	*/

	
 	cout << "---------- THE END ----------" << endl;
	return 0;
}



















