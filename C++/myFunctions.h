// ---------- Functions ----------

// Or can define them in the cpp file, before the main();

#include <iostream>
using namespace std;

void someFunction() {
	cout << "Hello from some function!" << endl;
}

int addNumbers(int firstNum, int secondNum = 0) {
	return firstNum + secondNum;
	// note the default value for secondNum is 0
	// default parameter types have to come after the regular ones
}

// function overloading: Can reuse function names,
// but different attributes

int addNumbers(int firstNum, int secondNum, int thirdNum) {
	return firstNum + secondNum + thirdNum;
}

// Recursive functions: calls itself

int calFactorial(int number) {
	int sum;
	if (number == 1) {
		sum = 1;
	} else {
		sum = calFactorial (number - 1) * number;
		// cout << sum << endl;
	}
	return sum;
}

// Pass by reference

void changeGlobally(int* num) {
	*num = 42;
}

void passByRef(int& num) {
	num = 7;
}

 void europeIsFucked(int numOfEuropeanMen) {
        while(numOfEuropeanMen != 0) {
        std::cout << "You are a pussy!" << endl;
        numOfEuropeanMen--;
        }
    } 
