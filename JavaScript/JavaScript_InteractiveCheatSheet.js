/**********************
 General Stuff
**********************/

// Interactive JS
// confirm("I am awesome!");
// var userFirstName = prompt("What is your first Name?");
// someAlert = "RED ALERT!";
// alert("This is an alert" + someAlert); 

// write to console: console.log()
// write to browser, inside HTML tags: document.write()

// isNaN
console.log(isNaN("a")); // => true
// Notes on NaN
// NaN is a number object! 
// NaN is toxic, as if it appears anywhere in the course of a series
// of equations, the end result will be NaN
// NaN is NOT ===, >, < than NaN ... i.e. comparison returns false

// Identifiers:
// Avoid reserved names for var such as if, else, break ...
// var break = 2; // SyntaxErr
var $break$ = 2; // or _break_
console.log($break$); // => 2


// bitwise operators:
// & ^ | >> << >>>

// JavaScript is an "untyped" language. i.e. not like C!
console.log(typeof("2")); // => string



/**********************
 Variables
**********************/

// Excluding var will make variable global scope

// Numbers
// ALL numbers are 16 bit doubles ... no int or float
// Max and min numbers that can be stored:
console.log("The largest number: ", Number.MAX_VALUE);
console.log("The smallest number: ", Number.MIN_VALUE);
// Only precise up to 16 digits
var my_int = parseInt(3.23, 10); // Forces integer
console.log("Some integer: ", my_int);
// Note on parseInt:
// It stops at first non-digit char i.e. parseInt(08) => 0
// So ALWAYS use radix to denote the base. parseInt(08, 10) => 8
parseInt(11, 2); // => 3  binary
// Rounding to a specific number of decimal places
console.log("Fraction 2/3 rounded to 4 decimal places: ", (2/3).toFixed(4));
// All the usual mathematical operations
// +, -, *, /, %
console.log(14 % 3); // => 2 (mod)
// Shorthand inc. dec.
var someNum = 42;
console.log("someNum++: ", someNum++); // => 42 , then it's incremented
console.log("--someNum: ", --someNum); // => 42 , first decremented the logged
console.log("someNum /= 7: ", someNum /= 7); // => 6
console.log("someNum *= 5: ", someNum *= 5); // => 30
// Order operations matter * / + -
// Built-in math functions:
console.log("The value of pi: ", Math.PI);
console.log("The value of e: ", Math.E);
// Math methods:
  // abs, pow, sqrt, cbrt, ceil, floor, max, min, round, log ...
// Random numbers Math.random => [0,1)
var choice = Math.floor(Math.random() * 3 + 1); // [1,2,3]
console.log(choice);
// Unary operator can convert strings to numbers +"42" => 42
console.log(+"4" + +"3"); // => 7


// Strings
// Strings are immutable
// "this" == "this", with double equals
// String methods:
  // CharAt, concat, indexOf, lastIndexOf, match, replace(str, str), search(char)
  // slice, split, substring(startIndex, endIndex), toLowerCase(), toUpperCase(), trim()
var my_string = "String";
console.log(my_string.length < my_int); // => false
console.log(my_string.substring(3,5)); // => in // [) and 0 index
// same for slice(startIndex, endIndex - 1)
console.log(my_string.substr(2, 2)); // => ri , (startIndex, length)
my_string += " append";  // concatenation with '+'
console.log(my_string); // => String append
console.log("\'app\' is at index: ", my_string.indexOf("app")); // => 7
console.log("Character at index 5: ", my_string.charAt(5)); // => g
console.log(my_string.search('g')); // => 5
// Browser styling methods:
  // big(), small(), bold(), fontcolor(str), fontsize(str), italics(), 
  // link(url), sub(), sup(), strike(), 


// Arrays
// Can be variable in size
// Can hold multiple data types
// methods: concat, join, pop, push, slice, sort, splice
var new_array = [];
var New_Array = [];  // This is literal notation is preferred to the above

var my_array = ["Hello", "World!", 42, [1,2,3]];
console.log(my_array[3][2]); // => 3
console.log(my_array.length); // => 4
my_array.push([]); // Append to the end
delete my_array[1]; // Leaves a hole behind; NULL
console.log(my_array[1]); // => undefined 
// Overwrite an array splice(index, # to delete)
my_array.splice(1, 1);
console.log(my_array); // => [ 'Hello', 42, [ 1, 2, 3 ], [] ]
console.log("my_array contains: ", my_array.join(" - "));
// notice the last element is occupied by NULL, but exits!
console.log(my_array.sort());  // The original array is overwritten

// Array sorting
var unsortedArray = [10, 32, 4, 1, 12, 5, 65];
unsortedArray.sort(function(x,y){return y-x});
console.log(unsortedArray);

// Concatenation
var combinedArray = unsortedArray.concat(my_array);
console.log(combinedArray);
combinedArray.shift();  // First element is deleted
console.log(combinedArray);
combinedArray.unshift('#1');  // Push element to the beginning 
console.log(combinedArray);


// Jagged array:
var jagged = [[1, 2, 3], [4, 6], [7]];
for (var i = 0; i < 3; i++) {
    for (var j = 0; j < 3; j++) {
        console.log("[" + (i+1) + (j+1) + "]" 
        	+ " = " + jagged[i][j]); // [23] == undefined
   }
}


// Typecasting:
// Number("string"), 
// String("number"), .toString, .valueOf
// parseInt("string", number)
// parseFloat("string", number)



/**********************
 Control Flow
**********************/

// Relational operators ===; !==; ==, !=, >; >=; <; <=; 
// logical operators &&; ||; !
// === and !== DON'T do type coercion 
console.log("5" == 5);// => true
console.log("5" === 5); // => false

// Boolean operators: true, false
// falsy values: false, null, undefined, "", 0, NaN
// truthy values: everything else! e.g. "0", "false"

//noinspection JSDuplicatedDeclaration
var condition = true;

if ((condition === true) || (false)) {
	console.log("Condition is true!");
} else if (condition === false){
	// Some code
} else {
	;
}

// default operator ||: If first operand is falsy, use default
input = 4; // i.e. falsy
condition = false;
var someInput = input || condition;
console.log(someInput); // => 4

// guard operator &&: If the first operand is truthy, then result
// is the second operand
// return a && a.member 
  // means if(a) {return a.member;} else {return a;}
// Doesn't necessarily return true or false!


// Switch statement
someCase = 'Banana'; // Note: Cases are case-sensitive! lol
switch(someCase.toLowerCase()) {
	case 'apple':
	  console.log("Okay here is your apple!");
	  break;
	case 'banana':
	  console.log("No problem, here is a banana.");
	  break;
	default:
	  console.log("Sorry we don't have that.");
	  break;
}


// Ternary operators
x = 10;
y = 9;
result = x > y ? "good job" : 20; // condition ? if true : else ;
console.log(result); // => good job



/**********************
 Loops 
**********************/

// The for loop
for (var counter = 2; counter < 11; counter += 2) {
  if (counter % 6 == 0){
    console.log(counter + ' is divisible by 2 and 3');
    break;
  } else {
    console.log(counter);

  }
}

// labeled statement break
loop: for (var i = 1; i < 11; i++ ) {
  for (var j = 1; j < 6; j++) {
    console.log(i, j);
    if ( i % 7 == 0) {
      break loop;
    }
  }
}
// When i,j = 7,1, the above breaks out of the whole loop
// If we only had break, 7,1 to 7,5 would be omitted.


// for (in), array search example
var multiplesOfEight = [8,16,24,32,40,58];

for (arrayIndex in multiplesOfEight) {
    var answer = multiplesOfEight[arrayIndex] % 8 !== 0; // Type Boolean
    console.log(answer);
    if (answer) {
        console.log(multiplesOfEight[arrayIndex]);
    }
}


// The while loop
while(condition) {
  console.log("We are inside the while loop");
  var condition = false;
}

// The do while loop; must go through the loop at least once
do {
  condition = false;
  console.log("The condition is: %s", condition);
} while(condition);


/**********************
 Functions
**********************/

// Naming convention: lowerCamelCase
// Only blocks have scopes, i.e. any var outside a function is
// Visible to All functions
// Can assign to a var, for storing an array of functions for e.g.
var someFunction = function(someInput) {
	console.log("-----\n" + "We are inside some function!");
	return someInput += 1;
};
console.log(someFunction(2));

// There is no void type ... every function will return.
// Empty return will return 'undefined'

function anotherFunction(someInput) {

}
console.log(anotherFunction(12)); // => null

// Can pass functions as an argument
function by3(num) {
  return num += 3;
}
function by5(num)  {
  return num += 5;
}
function increment(func, num) {
  return func(num);
}
console.log(increment(by5, 5));  // => 10


// Function overloading (undetermined number of arguments)
function SumNumbers() {
  var sum = 0;
  var i = 0;
  console.log(arguments);
  while(i < arguments.length) {
    sum += arguments[i];
    i++;
  }
  return sum;
}
console.log(SumNumbers(10,20,30,40,50));

// Recursive functions:
function factorial(n) {
  if (n <= 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}
console.log(factorial(4));



/**********************
 Objects
**********************/

// Unordered collection of name/value pairs, names are strings, 
// values can be anything, including other objects.
// Like a database, good for representing records and trees.
// Always passed by reference, not value

// Object literal notation (more efficient)

var outsideMethod = function () {
  return "Hello! My name is " + this.name + ".";
};

var myObject = {  	// Or var myObject = {};
    name: "John",
    age: 12,
    sexMale: true,
    interests: ['books', 'coffee', 'video games'],

    // Define methods
    sayName: function(someName) {
      console.log("My name is: " + someName)
    }, // VERY IMPORTANT: Don't forget the ","

    // Can reference methods outside of the object with "this".
    sayHello: outsideMethod
};

// Calling an outside method
console.log(myObject.sayHello());

// Accessing public attributes and methods
myObject.name = "Tom";
console.log(myObject.name);
myObject.sayName("Mary");

// Object constructor
var me = {};

me["name"] = "John";
me["age"] = 12;
me.sexMale = true;

var yearOfBirth = function(now) {
	return now - this.age; 
};

me.birthDate = yearOfBirth; // Set the function as a method for
							// any object

console.log(me.name);
console.log(me["sexMale"]);
console.log(me.birthDate(2012));


// Accessing attributes with "prop in obj"
for (prop in me) {
  console.log(prop);
}

for (name in me) {
  if(me.hasOwnProperty(name)) {
    // Use this all the time to avoid error later in the code
    console.log("My name is " + me.name);
    break;
  }
}


// Define Classes:
// There are really no classes in js, objects and constructors can be modified
function Rectangle(height, width) {
  this.height = height; // Public property
  this.width = width;
  this.sides = 4;
  var password = 1234; // Private property
  
  this.calcArea = function() {
      return this.height * this.width;
  };

  this.showPassword = function() { // Access private properties
  	return password * 3;
  };

  var returnPassword = function() { // Private method
  	return password;
  };

  this.accessPrivateMethod = function(key) {
  	if (key == 0000) {         // Username password implementation
  	  	return returnPassword; // Note: DON'T include ();
  	  						   // Must return the method itself
  	  						   // See below for access
	}  	  						   
  };
}

// Array of objects:
var Rectangles = []; // Or var Rectangles = [];
Rectangles[0] = new Rectangle(7,3);
Rectangles[1] = new Rectangle(10,2);
console.log(Rectangles[1].calcArea());

// Access private method:
var privateMethod = Rectangles[0].accessPrivateMethod(0000);
console.log(privateMethod());


// Passing Objects into functions
// Useful to avoid passing lots of parameters to function
function compareArea(Rec1, Rec2) {
	if(Rec1.hasOwnProperty("calcArea") && 
		Rec2.hasOwnProperty("calcArea")) {
		if (Rec1.calcArea() > Rec2.calcArea()) {
			return Rec1;
		} else {return Rec2}
	} else {console.log("Error!");}
}	
console.log(compareArea(Rectangles[0],Rectangles[1]));

// Object prototyping: Add an attribute or method to all instances 
// of an object by adding it to the 'class' as a prototype
Rectangle.prototype.id = 5412703512;
Rectangle.prototype.calcPerimeter = function() {
      return ( 2 * (this.height + this.width));
};
console.log(Rectangles[1].id);  // => 5412703512
console.log(Rectangles[0].calcPerimeter());

// Inheritance: Allows one class to see and use the methods and
// properties of another class
Square.prototype = new Rectangle();
function Square(side) {
  this.height = side; // must be defined like the parent IF used in
  this.width = side;  // the inherited methods!
}
var someSquare = new Square(2,2);
console.log(someSquare.calcPerimeter()); // => 8
console.log(someSquare.sides); // => 4 Inherited property!


// Augmentation:
// Can add new members and methods to an existing obj
// Customization has less overhead than class definition
someSquare.colour = "blue";
console.log(someSquare.colour); // => blue
delete someSquare.colour;
console.log(someSquare.colour); // => undefined
someSquare.colour = "red";

// Linkage
// Obj with a secret link to another object; if undefined in the
// first obj, will inherit from the link
// Only single inheritance; but can daisy chain 
var someNewSquare = Object(someSquare);
someNewSquare.height = 3;
console.log(someNewSquare.calcPerimeter()); // => 10 instead of 8
console.log(someNewSquare.colour); // => red



/**********************
 Error Handling
**********************/

// Error types:
// 'Error', 'EvalError', 'RangeError', 'SyntaxError',
// 'TypeError', 'URIError'

// try and catch
try {
  console.log(nonExistingVariable);
} catch(err) {
  txt = "There was an error on this page.\n";
  txt += "Error description: " + err.message + "\n";
  txt += "Click OK to continue.\n";
  console.log(txt);
}


// throw: allows you to create a custom error
someString = "a";

try {
  if (someString == "") {
    throw {  // Object literal notation
      name: "emptyStringError",
      message: "The string is empty dude!"
    };
  } else if (isNaN(someString)) {
    throw new Error("Not a number");  // Object constructor
  } 
} catch(err) {
  txt = err.message;
  console.log(txt);
}


// THE END
