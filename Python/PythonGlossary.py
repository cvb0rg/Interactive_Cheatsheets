#######################
# General Stuff
#######################

# This is a comment (cmd+/ or ctrl+/ in sublime)

''' This is a 
multi-line 
comment '''  # " also works

# Whitespace matters: For grouping indent with 4 spaces or TAB

# Zen of Python; how to import libraries
# Install new libraries: pip install 'someLib'
import this
print this  # (This) is python v3.x

# Print formatting
print ("The answer to %s + %s = %d" % ('a', 'b', 42))
print ("The answer to {:2} + {:<5} = {:5}".format('a', 'b', 42))

# Some print tokens
# %c	character
# %d	decimal (integer) number (base 10)
# %e	exponential floating-point number
# %.2f	floating-point number; 2 decimal places
# %i	integer (base 10)
# %o	octal number (base 8)
# %s	a string of characters
# %u	unsigned decimal (integer) number
# %x	number in hexadecimal (base 16)
# %%	print a percent sign
# \%	print a percent sign

# print without end-line termination
print "Hello",
print "world!"

# Find types
print type("hello") # => 'str'

# Stop the execution, anywhere is the script
# quit()

# Assignment: A = A + 1
# NOTE: Only creates a reference to the object; not a new copy
#		Slicing in lists makes a new copy. B = A[:]
#		This is not a problem with tuples and strings (immutable)
# Augmented assignment: A += 1  
# Multi-assignment: (a,b,c) = (2,3,[4,5]) ; a,d = [2,3]

# Arithmetic operations: 
# +, -, *, /, //(floor division), **(power), %(modulus)
# Order of operations matters.
print -2**2 # => -4
print 2*3**2 # => 18 
# Force float division
print 1/2 # => 0
print 1.0/2 # => 0.5

# Math and graphical libraries (see documentation for each)
import math
# Import modules with alias 
import matplotlib.pyplot as plt
import numpy as np
everythingMath = dir(math) # lists the functions in a module
print everythingMath 
print math.sqrt(10)

# or selectively import
from math import sqrt
print sqrt(10) # note: no need to use dot notation
# Universal import:
# not recommended, may lead to naming conflicts
from math import * # means import EVERY variable and function name
				   # in a module and unpack

# Get user input (as a string): 
# Won't work in sublime! Use PyCharm or run in terminal
# Or install SublimeREPL package; cmd+B won't work though
# var = raw_input("Enter some integer between 1 and 5: ")
# print ("Your answer was %s" % (var))

# Other way of getting user input
# Same as before for SublimeText
# import sys
# print "What is your name?"
# var = sys.stdin.readline()
# print var

# Exception handling

# while True:
# 	try:
# 		x = int(raw_input("Please enter a number: "))
# 		break
# 	except ValueError:
# 		print "Oops!  That was no valid number.  Try again..."


# Multi line code breaker -> use \
	  

# Importing special functionality; date and time module 
from datetime import datetime
print datetime.now() 
	# methods: .year, .month, .day, .hour, .minute, .second

# Randomness
import random
random_num = random.randrange(0,100)  # 0 to 99
print random_num


#######################
# Data types
#######################

This_is_an_integer = 42
This_is_a_bool = True # or False
This_is_a_string = "I\'m a " + "str" + 'ing' # literal notation
	# \ used for 'escaping'
	# String index is zero based
	# Strings are immutable

######## strings ########
my_string = "I'm a string"
print my_string[1] # -> '

# Some string methods
print len(my_string) # -> 12 This is a built-in function
print my_string.lower()
print my_string.upper()
print my_string.capitalize() # Already is capitalized!
print my_string + " " + str(22) # explicit string conversion
print my_string.isalpha() # True if only alphabets
print my_string[:5] # => I'm a

# String formating with %
print "The string says: %s and it has a length of: %s" \
%(my_string, len(my_string))

# Slicing
# [start(inc):end(exc):stride]
# empty defaults to 0:len(lst) - 1:1
print my_string[2:4] # 2 to 4 exclusive # => m
print my_string[1:-1] # -ve counts from the end # => 'm a strin
print my_string[2::2] # Every 2 elements, starting index 2
							 # => masrn
print my_string[::-1] # -ve stride means backwards
							 # => gnirts a m'I

# Searching strings
print my_string.find('ing') # => 9 (1st instance index)

# String manipulation via lists:
text = my_string.split() # => ["I'm", 'a', 'string']
print text
print " ".join(text) # => I'm a string
print my_string.replace('string', 'str')
print my_string # note: the string is not modified

# strip white space at the beginning and the end
print "    A lot of white spaces    ".strip(), '.'


######## Lists ########
# zero based; mutable; can be different data types
This_is_an_empty_list = []

# IMPORTANT note on Lists
# They are mutable so assignment is going to be a problem
x = [1,2,3] 
y = x  # simple assignment
y[0] = 2 
print x[0] # => 2 as well! Changed!
# instead assign like this: y = x[:] => a new list 'slice' is created

my_list = [1, 2, 3, 4, [1, 2, 3]]
print my_list[4] # => [1, 2, 3]
print my_list[4][2] # => 3
# lists are mutable
my_list.append(5)
print my_list # => [1, 2, 3, 4, [1, 2, 3], 5]
# inserting in the middle: insert(index, val)
my_list.insert(5, "cat")
print my_list # => 1, 2, 3, 4, [1, 2, 3], 'cat', 5]
# slicing lists
print my_list[2:4] # => [3,4] => excluding end index
# search through lists with index()
print my_list.index("cat") # => 5
# loop through list
for var in my_list: # remember the colon
	# do stuff
	# note: var is NOT the same as index in a for loop
	print type(var) 
	print my_list.index(var), ": ",# => 0 1 2 3 4 5 6
	print my_list[my_list.index(var)]

# Removing elements from a list
print my_list.pop(6) # pops/returns element at index
					 # default is the last index
					 # => 5
print my_list # => [1, 2, 3, 4, [1, 2, 3], 'cat']
my_list.remove(4) # removes 'element' from list
						 # NOT index
print my_list # => [1, 2, 3, [1, 2, 3], 'cat']
del(my_list[0]) # same as pop; won't return anything
print my_list # => [2, 3, [1, 2, 3], 'cat']

# sorting lists 
my_list.sort() 	   # ascending 
print my_list
my_list.reverse()  # descending
print my_list

# Max and min
print (max(my_list)) # => cat   # numerically highest
print (min(my_list)) # => 2

# note on the Range() function
range(1) # => [0]
range(2) # => [0,1]
range(1,3) # => [1,2]
range(2,9,3) # => [2,5,8] # third arg is the increment

# comparing two lists
list_a = [3, 9, 17, 15, 19]
list_b = [2, 4, 8, 10, 30, 40, 50, 60, 70, 80, 90]
for a, b in zip(list_a, list_b): 
    # zip creates pair of elements, ending at the shorter list.
    print a, b, a + b
    
# 2D lists
some2Dlist = np.zeros(2 * 10).reshape(5,4) # (rows, cols)
some2Dlist[2][3] = 1 # 0-indexed for assignment
print some2Dlist
sliced2Dlist = some2Dlist[:,1:4] # 1-indexed for slicing! 4 excluding
print sliced2Dlist

# List comprehension:
# Making lists with "for/in" plus conditionals "if"
SquaredEvens_to_50 = [i**2 for i in range(51) if i % 2 == 0]
# => list of even numbers squared from 0 to 50 inclusive.
print SquaredEvens_to_50


######## Tuples ########
# Just like lists BUT immutable
# Good for storing data you don't want changed
# To change tuples can convert to lists then back to tuples
This_is_a_tuple = (1, 2, "this", ['that', 3.1423])
print This_is_a_tuple
This_is_a_tuple = This_is_a_tuple + ('a', 2) # can concatenate tuples
print This_is_a_tuple # => (1, 2, "this", ['that', 3.1423], 'a', 2)

# Some list methods also work on tuples, max, min, len ...


######## Dictionary (map) ########
# Same as lists; use access key (number or str) instead of index
my_dict = {'key1' : 1, 'key2' : 2, 'key3' : [1,2,3]}

# iterating over key/values in a dictionary:
print my_dict.items() 
# => ('key3', [1, 2, 3]), ('key2', 2), ('key1', 1)]
print my_dict.keys() # list for keys only  
print my_dict.values() # list for values only
print my_dict['key2'] # => 2

# Dictionaries are mutable like lists
This_is_an_empty_dic = {}
This_is_an_empty_dic['someKey'] = 'SomeVal'
print This_is_an_empty_dic['someKey']
# Can put lists inside dictionaries
# len(dic) is the number of key:val pairs
print 'Lenght of my_dict = ' + str(len(my_dict)) # => 3
# delete items from a dictionary
del my_dict['key1']
print my_dict # => {'key3': [1,2,3], 'key2': 2}

# Dictionary keys have to be hashable and immutable: int, str and tuples
# When you access a value in a dictionary, you have access to that value directly
print my_dict['key3'][1] # => 2
my_dict['key3'].remove(2)
print my_dict['key3'][1] # => 3

# Some dictionary methods:
print my_dict.has_key('key2') # => True
print my_dict.has_key(2.3) # => False
print my_dict.get('key1', 'return not valid if does not exist') # => 'not valid'


#######################
# Control Flow
#######################

# Comparisons ==; !=; >; >=; <; <=
# Logical operators: not; and; or (in order of execution)

some_condition = True
some_other_condition = not(some_condition)

if some_condition or some_other_condition:
	# some code, note the :
	some_condtion = False
	print "done"
elif some_condition:
	# some other code; note the syntax :
	pass # can't leave empty, mess up indentation
else:
	# something else
	print "Meh"


#######################
# Loops and iterators
#######################

######## for loop ########

# Simple iterator
for i in range(10):
	pass # Doesn't do anything, use as placeholder where python 
		 # expects an expression 
	print i,
print ''

# Looping the lists
someList = [11, 22, 33]
for index, numbers in enumerate(someList): # indexes the list
	print index, numbers 

# Looping through dictionaries; unordered
someDictionary = {"Alpha" : 124,
				  "Bravo" : 253,
				  "Charlie" : 235}

for keys in someDictionary:  
	print someDictionary[keys]

# String looping
for letter in "Hello world!":
    print letter

# Nested for loops
nested_list = [[1, 2, 3],[10, 20, 30], [100, 200, 300]]
for x in nested_list:
	for y in x: 
		print x[0], y  
		# note: x is a list, won't work for parsing matrices
for x in range(3):
	for y in range(3):
		print nested_list[x][y]
		# This works for getting the elements


# for/else
# else will execute if the loop executes normally; no breaks

######## The while loop ########

# Used when don't know the exact number of iterations
some_condition = True
while some_condition:
	print "We are in a while loop"
	while True: # Guaranteed to run at least once
		print "We are in the inner loop"
		break
	print "We are in the outer loop"
	some_condition = False
else: # Executes if loop condition is false; no breakpoint reached
	print "We exited the outer while loop normally"

while True:
	dice1 = random.randrange(0,6) + 1
	dice2 = random.randrange(0,6) + 1
	print ("D1: {} D2: {}".format(dice1, dice2))
	
	if (dice1 == dice2):
		print "Hooray, you got a double!"
		break
	else:
		print "Keep trying!"

# Use while loop like a for loop
i = 1
while i <= 20:
	print i,
	i += 1     # don't forget to update iterator!
print''


#######################
# Functions
#######################

def valSquared(someVar, *Splat):
	# Splat arguments: Arguments of arbitrary number
	""" This is a comment about the function """
	ans = someVar ** 2
	print "%d ^ 2 = %d" % (someVar, ans)
	if Splat:
		print "The nights of Ni say: ", Splat # Output is a list
	return ans

valSquared(12, "Ni", "Ni", "Ni")
sevenSquare = valSquared(7)
print sevenSquare


######## Lambda: ########
# Anonymous functions
# Chunks of reusable code
f = lambda x: x**2
print f(3) # => 9

# Often used with  map(), filter() and reduce()
my_list = range(16)
print map(lambda x: x ** 2, my_list) # squares all elements
print filter(lambda x: x % 3 == 0, my_list) # => [0, 3, 6, 9, 12, 15]
print reduce(lambda x, y: x + y, my_list) # sum 0:15

# Nested scopes:
def multiplyBy(val):
	return lambda i: val * i
	# Function makes a function on the fly
f = multiplyBy(3)
print f(10) # => 30

######## Type casting functions ########
print int('1234')
# string, floating point -> integer	

print float(5)	# => 5.0
# string, integer -> floating point number	

print str(12)	
# integer, float, list, tuple, dictionary -> string	

print list('Hello')	# => 
# string, tuple, dictionary -> list	

print tuple([1,2,3])	
# string, list -> tuple


######## Bitwise operations ########
print bin(12) # => 0b1100  Also oct() and hex()
# NOTE: bin() returns a 'str'

# The int() function has a second parameter, base, will return int
# in base 10 ... note: input number as string
print int("0b1010", 2) # => 10

# Shift bits
print bin(0b1010 >> 2) # => 0b10 = 2 shift right
print bin(0b1 << 2) # => 0b100 = 4 shift left
bin_type = 16 # 0b10000
bin_type >>= 4 # Analogues to += -= etc
print bin_type # => 1

# Bitwise boolean operations
print bin(0b1110 & 0b101) # => 0b100    (and)
print bin(0b1110 | 0b101) # => 0b1111   (or)
print bin(0b1110 ^ 0b101) # => 0b1011   (XOR)
print bin(~0b0001) # => -0b10           (NOT) NOT quite bit flip
# NOT x = - (x + 1) !

# Bit Mask
a = 0b1100
mask = 0b1 << 2 # Another way of saying 0b100
desired = a & mask # => 0b100 Check to see if the 3rd bit of a is on
turnon = a | mask # => 0b1100 Turns on the 3rd bit
bitflip = a ^ 0b1111 # => 0b11 : all bits flipped
print bin(desired)



#######################
# Objects
#######################

class Fruit(object): 
	# Inherits from object class
	# User defined classes start with capital letter
	"""A class that makes various tasty fruits."""
	is_a_fruit = True # member variable

	# private attribute: add "__" before 
	# Can't be accessed unless by getter/setter methods
	# Good for verifying inputs (encapsulation)
	__privateAttribute = None # doesn't have a value
	__type = ''

	# Object constructor
	def __init__(self, name, type_, color, flavor, poisonous):
		# __init__() takes a min of one arg: self
		# python uses the 1st parameter to refer to the object itself
		# so it doesn't have to be self, could be 'me'! 
		# convention is to use 'self'
		self.__name = name # instance variable
		self.__type = type_ # not to be confused by function type()
		self.color = color
		self.flavor = flavor
		self.poisonous = poisonous

	# Getter and setter functions
	# Add one for each attribute you want to be able to set
	# and get after the object is created
	def set_name(self, new_name):
		self.__name = new_name

	def get_name(self):
		return self.__name

	def get_flavor(self):
		return self.flavor

	# Method overloading
	# Perform different tasks based off of the attributes sent
	def describe_flavor(self, howIntense=None):
		if howIntense is None:
			print self.flavor
		else:
			print (howIntense + ' ' + self.flavor)

	# polymorphism example
	def get_species(self):
		print "Fruit"
	
	def description(self): 
		print "I'm a %s %s called %s and I taste %s." % \
		(self.color, self.__type, self.__name, self.flavor)
		
	def is_edible(self):
		if not self.poisonous:
			print "Yep! I'm edible."
		else:
			print "Don't eat me! I am super poisonous."

lemon = Fruit("Frank", "lemon", "yellow", "sour", False)
lemon.set_name("Johnny")

# Method overloading
lemon.describe_flavor() # => sour
lemon.describe_flavor("Extremely") # => Extremely sour

# Attempting to access private methods
try:
	print lemon.name
except:
	print "Can't access private attributes like this!"
	pass

lemon.color = "Blue"  # Can do this because name is public!

lemon.description()
lemon.is_edible()
print lemon.is_a_fruit # => True


######## Inheritance ########

# Get all the attributes and methods of the parent
class TropicalFruit(Fruit):
	def partial_description(self, cost):
		self.cost = cost
		return "I'm a %s and I cost $%s." %(self._Fruit__name, self.cost)

	# Note: above is NOT a good way of assigning new attributes
	# The attribute does not exist until the method is called
	# Make a new constructor
	__cost = 0
	def __init__(self, name, type_, color, flavor, poisonous, cost):
		self.__cost = cost
		super(TropicalFruit, self).__init__(name, type_, color, flavor, poisonous)
		# Let the super class constructor handle the rest


	# Also note how the private attribute of the superclass is referred to _super__private

	# access methods of the superclass
	def full_description(self): 
		super(TropicalFruit, self).description()

	# polymorphism example
	def get_species(self):
		print "Tropical Fruit"

	# __repr__ should return a printable representation of the object
	# Change default representation (to something meaningful!)
	def __repr__(self): 
		return "I am a %s %s and I taste %s, costing you $%s." \
		%(self.color, self._Fruit__type, self.flavor, self.cost)


banana = TropicalFruit("Charlie", "banana", "yellow", "sweet", False, 30)
print banana.partial_description(20)
banana.full_description()
print banana  # default __repr__: <__main__.TropicalFruit object at 0x109070f50>


######## Polymorphism ########

#  Ability of an object to adapt the code to the type of the data it is processing.
class Species_identifier:
	def get_species(self, someFruit):
		someFruit.get_species()

test_fruit = Species_identifier() # make a new object
test_fruit.get_species(lemon) # => Fruit
test_fruit.get_species(banana) # => Tropical Fruit


#######################
# File I/O
#######################
my_file = open("output.txt", "w") 
# r+ : read and write
# w  : write (creates the file if doesn't exit)
# r  : read
# a  : add (appends data to the file without overwriting)
my_list = [ i**3 for i in range(1,11) if i % 2 == 0]
for val in my_list:
	my_file.write(str(val) + "\n") # Note: can only write strings
								   # Or binaries
my_file.close()


my_file = open("output.txt", "r")
print my_file.readline() # reads line by line => 8
print my_file.readline() # jumps to the next line => 64
input_string = my_file.read() # starts from the 3rd line
my_file.close()
print input_string # => '16\n512\n1000\n'
txt_list = input_string.split() # defaults to newline char
print txt_list # ['216', '512', '1000']

# The shorthand; i.e no need to close the file manually
with open("text.txt", "w") as textfile:
	textfile.write("Success!")

with open("text.txt", "r") as inputfile:
	print inputfile.read() # => "Success!"
print inputfile.closed # => True (an attri of the file object)


######## Saving/reading from .csv file ########
nrows, ncols = 3,5

image = np.zeros(nrows * ncols)
image = image.reshape((nrows, ncols))
print image


# Save as plain text file
np.savetxt('testNPtoFile.txt', image) 
# Save as csv file
np.savetxt('testNPtoFile.csv', image, delimiter=",")


# Load np.array from text file
image_file = open("testNPtoFile.txt", "r")
input_string = image_file.read()
print input_string


# Load np.array from csv file
from numpy import genfromtxt
my_data = genfromtxt('testNPtoFile2.csv', delimiter=',')
print my_data 
# Note the NaN values generated when the csv was opened 
# and saved to add the 1 in (0, 0) manually
# Remember to slice
print my_data[:3,:]

# Manipulating files from python script using os module
import os
try:
	# delete a file; full path if not in the same directory
	# os.remove("fileName.extension")  
	pass
except IOError as e:
    print "I/O error({0}): {1}".format(e.errno, e.strerror)



print "THE END!"
