// Animal.h

#ifndef Animal_H
#define Animal_H


// ---------- Classes (definitions) ----------

 	class Animal {
 		// Attributes and methods:
 	private:
 		// Can only be changed by the functions inside the class
 		int height;
 		int weight;
 		string name;

 	static int numOfAnimals;
 		// Static vars are shared between ALL Animal objects created

 	public:
 		// Here we are combining definitions and declarations. Alterntively you delare these in the cpp like:
 		int echoHeight() {return height;}
 		int echoWeight() {return weight;}
 		string echoName() {return name;}

 		void setHeight(int howTall) {height = howTall;}
 		void setWeight(int howHeavy) {weight = howHeavy;}
 		void setName(string animalName) {name = animalName;}

 		void setAll(int, int, string);
 		// Class prototype

 		Animal(int, int, string);
 		// Constructor: function that is called when an object is created
 		// Name starts with the class name
 		Animal();
 		// Another constructor, no attributes. Same as overloading

 		~Animal();
 		// Destructor:


 		// Protected: available to the members of the same class AND sub-classes but nothing else.

 	static int getNumOfAnimals() {return numOfAnimals;}
 		// Method to access static members.

 		void toString();
 		
 	}; // remember the ;


 #endif