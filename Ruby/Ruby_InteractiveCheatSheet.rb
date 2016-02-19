# >>> Here we shall have a Ruby cheatsheet via examples <<<

#######################
# Ignore this bit!
def heading_generator(heading)
	heading = <<EOM
\n#######################
# #{heading}
#######################\n
EOM
	puts heading
end
#######################




# Start here!

#######################
# General Stuff
#######################
heading_generator("General Stuff")

# This is a comment (sublime shortcut cmd+/ or ctrl+/)
# Must define methods/functions BEFORE calling them, order matters

=begin
	This is a multi-line comment. =begin and =end must not be
	indented.
=end

puts "'Puts' prints to console, includes a newline char"
puts " This is a long multi-line string"\
	 " and this is how you break it up without concatenation."\
	 " Can also be done to break up code!"
print "'Print' puts to console, NO newline"
print "Some Variable" , "\n" # adds a newline char
puts [0,1,2].inspect # Print the variable as it is defined
p [0,1,2] # sames as puts [0,1,2].inspect
		  # Prints the content of the argument 

# Escape sequences
# \\  Backslash
# \'  Single-quote
# \"  Double-quote
# \a  Bell
# \b  Backspace
# \f  Formfeed
# \n  Newline
# \r  Carriage
# \t  Tab
# \v  Vertical tab

name = "john"
age = 42
printf "%s is %d years old. \n", name, age

# Some printf tokens
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



# Terminate execution (it is commented out here!)
# exit

# Execute ruby code from another ruby file; common practice in making modules
load "rubyLoadExample.rb"

# Alternative to load is require; relative if in same dir
require_relative "rubyLoadExample"
puts "C_STRING from rubyLoadExample: " + C_STRING
puts "@instance_variable: " + @instance_variable
puts "$global_variable: " + $global_variable


# Difference 'load' and 'require'
# - require doesn't need file extension
# - require searches for the library in all the defined search paths
# - require makes sure a library is included only once
# - load gets loaded every time called, even if already in memory


# User input prompt example; must run from terminal; won't work in sublime or most other IDEs
=begin
puts "Input some integer"
prompt_user_imput = Integer(gets).chomp 
	# chomp removes newline char
	# Integer, asserts Integer
	# Integer, String, Symbol, Boolean
puts "Variable inside a string #{prompt_user_imput}"
	# #{} know as the string interpolation method.
=end

conditional_assignment ||= 0 # disregarded if exists
conditional_assignment.nil? # => false now!

puts " ".object_id # returns the address on the heap

puts " ".class # => String

# Randomness: rand(range {0-n})
puts rand(6) + 1   

# Test code efficiency
require 'Benchmark'
i = 0
puts Benchmark.realtime { 1000.times { i += 1 } } 

# or do it with Time:
def time(a_proc)
  start = Time.now
  a_proc.call
  puts Time.now - start
end
puts time(Proc.new { 1000.times { i += 1 } })


# CRUD: Create Read Update Delete

# Short circuit evaluation:
# true || something = true
# false && something = false 


#######################
# Exception handling
#######################
heading_generator("Exception handling")

num_test = 12
num_zero = 0

# Catch exceptions with begin and rescue
begin
	answer = num_test / num_zero
rescue ZeroDivisionError # ZeroDiv is a predefined class, Can do without.
	puts "You can't divide by zero darling!"
	# exit  ## Will end execution
end

# Defining own exceptions, using ArgumentError
def checkAge(age)
	raise ArgumentError, "Enter a positive integer" unless ((age.is_a? Integer) && age > 0) 
end

begin
	checkAge(-1)
rescue ArgumentError
	puts "Age is not valid, enter a positive integer."
end


#######################
# Variables
#######################
heading_generator("Variables")

this_is_a_string = "Variable"
this_is_an_integer = 3
this_is_a_symbol = :blue
  # Only ONE copy of a symbol allowed
  # Immutable, save memory
  # Make hashes work faster
this_is_a_float = 3.14112341234
  # .floor method rounds down
this_is_a_boolian = true
this_is_an_array = [1, 2, "hi", :hi]

# Constants are by definition capitalized (first letter)
# You could redefine it but you'll get an interpretor warning; defeats the point
A_CONST = 3.14
# To ignore/disregard the warning do this; but safer to leave the warning in place!
A_CONST ||= 3.1415


print "The value of A_CONST is ", A_CONST.to_s, ".\n"
print "A_CONST is of the type ", A_CONST.class, ".\n"
Another_const = 2.1234

# Conversions methods for type-casting:
# .to_s 'string' 
# .to_a 'array'  
# .to_i 'integer' 
# .to_sym OR .intern 'symbol' 

# Check the type
puts this_is_a_string.is_a? Integer # => false
puts this_is_a_string.is_a? String # => true

# Equality methods
puts this_is_a_string == "Variable" # => true # value comparison
puts 5 == 5.0 # => true # despite different types
puts 5.eql? 5.0 # => false # value and type comparison
puts "a".equal? "a" # => false # strict equality, see if same object


#######################
# Strings
#######################
heading_generator("Strings")

# can use both " and ', but ' won't work with interpolation or \n ...
my_string = "      " + "This is my string" 
puts my_string.length # => 23  # Can also use .size
puts my_string.include? 'is' # => true  # Method evaluates to boolean
puts my_string.empty? # same as: my_string == nil
puts my_string.index("my") # => 14
puts "Vowels : " + my_string.count("aeiou").to_s # => 3 # Counts duplicates
puts "Consonants : " + my_string.count("^aeiou ").to_s # => 11 # No duplicates
puts my_string

# formatting
puts my_string.split(" ") # the default is ;
puts my_string.upcase.downcase.capitalize.reverse 
puts my_string.swapcase
puts my_string.strip # Remove white space. lstrip/rstrip : left/right

my_string = "This is a string"
puts my_string.rjust(24, '*') # (total chars, fill with 'char')
puts my_string.ljust(24, '*')
puts my_string.center(24, '*')
puts my_string.chop # Delete last char
puts my_string.chomp('ing') # Chop from the end
puts my_string.delete('i') # Deletes all instances

# Careful with this one! Overwrites the string value
puts my_string.gsub!(/string/, "STR") 
puts my_string # => This is a STR

# String interpolation
first_name = "John"
last_name = "Smith"
puts "My name is #{first_name} #{last_name}."

# For very long multi-line strings use
multiline_string = <<EOM
\nThis is a very long string
that contains interpolation
like #{4 + 5} \n\n
EOM
 
puts multiline_string


# Symbols
# Constant strings, their values can't be changed
:someSymbol

puts :someSymbol
puts :someSymbol.class


#######################
# Control Flow
#######################
heading_generator("Control Flow")

# Comparisons ==; !=; >; >=; <; <=
# Combined comparison <=>
	# returns 1,0,-1 if: descending, equal, ascending
puts "1 <=> 2 = " + (1 <=> 2).to_s 

# Boolean operators && (AND); || (OR); ! (NOT)
# can also type 'and', 'or' and 'not' for logical operators

puts "true && false = " + (true && false).to_s
puts "true || false = " + (true || false).to_s
puts "!true = " + (!true).to_s

# Conditionals
some_condition = false
some_other_condition = true
if some_condition && some_other_condition
	# some code
elsif 1 < 2
	# note syntax; NOT elseif
	puts "1 is less than 2!"
else
	# some other code
end


unless some_condition
	# executes when false
	puts "I'm false"
else
	# executes when true
end


# Single line comparisons, conditions on the output
age = 22
puts "You can legally drink!" if (age >= 21)
return "n must be greater than 0." if some_condition == true

# Ternary shorthands (Refactoring)
puts some_condition == true ? "True Zen" : "else do this"


# Cases
some_case = "case1"
case some_case
when "case1", "CASE1" # Multiple cases
	puts "case 1 is executed"
	# exit    # exits main
else
	# default condition
end

# Case shorthand
case some_condition
	when "case1" then # do this
	when "case2" then # do this
	else # do this
end


#######################
# Loops and iterators
#######################
heading_generator(" Loops and iterators")

# while
some_condition = false
test_number = 134123152
largest_divisor = test_number / 2 + 10
while (largest_divisor > 0)
	puts "We are inside a while loop"
	largest_divisor -= 1
	next unless (test_number % largest_divisor) == 0
	puts "The largest divisor of #{test_number} is: " + largest_divisor.to_s
	break
end

# until: executes when false
until some_condition
	puts "We are inside an until loop"
	some_condition = true
end

# for
for num in 1...5
	puts "We are inside a for loop, iteration number #{num}"
	# ... exclusive, .. inclusive
end

# loop
i = 10
loop {      # or say: loop do ... end
  i -= 1
  next if i % 2 != 0 
  print "#{i} "
  break if i <= 0
} 
puts " "


# Array iterator
this_is_an_array = [1, 2, "hi", :hi]
this_is_an_array.each { |x| print x , " " } 
print "\n"
(0..5).each do |i| print "#{i} " end
puts " "

# Array manipulation
newArray =  ["a", "b", "c"]
newArray2 = newArray.collect! { |val| val + "xxx" }
newArray2.each_with_index { |val, val_index| 
	print "[#{val}, #{val_index}]", "\n"}
	# 'collect' applies the expression in the block to every 
	# element in an array (! to overwrite)


# Range of numbers or letters
2.times { puts "Hola!" }
20.downto(2) { |num|  print num } # won't work on strings
puts " "
"A".upto("K") { |char| print char }
puts " "


#######################
# Data structures
#######################
heading_generator("Data structures")

# Array
# Immutable; zero based index
# NOTE: Arrays are passed to functions as pointers i.e. if the function changes an array, the effect is global. 
# Make local copies to avoid this.
my_array1 = Array.new(5, "empty")
my_array1 = Array.new(10) { |i| "hey" + " you" }
p my_array1
my_2Darray = Array.new(3) {Array.new(4)}   # 3*4 table
p my_2Darray

my_array2 = [1, 2, "hi", :hi] 
puts my_array2.values_at(0,1).join(" - ")  # turn into a string
my_array2.unshift(0)   # Add element to the beginning of array
my_array2.shift(3)    # Remove 3 first elements
my_array2 << "/push new element/" << 100 << [1,2] # same as .push
	# concatenation operator (also known as "the shovel")
my_array2.pop(2)     # Removes the last 2 elements: 100, [1,2]
my_array2.concat([10,20,30])
p my_array2
my_array2.each {|val| print val, " "}
puts" "

puts my_array2.empty?   # => false
puts my_array2.size    # => 6
puts my_array2.include? 20   # => true
puts my_array2.count("hi")   # => 1


my_array = ["alpha", "omega", "bravo"]
my_array.sort! { |a,b| b <=> a } #descending
	# have to be same type for sorting comparison
my_array.each { |val| puts val }

this_is_multidimensional_array = [[1,2],[3,4]]
this_is_multidimensional_array.each { |x|
	x.each { |y|
		puts "(#{x},#{y})"}} #not good for doing matrices

# Hash and Hash methods
this_is_a_hash = {"Answer" => 42}
another_hash = Hash["Batman", "black", "superman", "red", 3, 2]
puts another_hash[3]
hash_with_sym_rocket = { :Answer => 42}
another_hash.update(this_is_a_hash)   # Destructive merge (no duplicates)
									  # .merge() nondestructive 
p another_hash
this_is_a_hash.delete("Answer") # deletes key:val both
puts this_is_a_hash  # => {}  # empty

#hash_with_sym = { Answer: "42" }  ## Ruby 1.9 and above

# Cool definition
# string_AZ = Hash[("a".."z").to_a.zip((1..26).to_a)]
# symbol_AZ = Hash[(:a..:z).to_a.zip((1..26).to_a)]

my_hash = Hash.new("No such key") #initialize, default is nil
my_hash["Answer"] = "Yes" #or use << instead of =
my_hash["Because"] = "No particular reason"
my_hash.each { |key,val| puts "#{key}: #{val}" }
	# Note: unsorted hash is ordered randomly
my_hash = my_hash.sort_by {|a,b| b} #sort by value
my_hash.each { |key,val| puts "#{key}: #{val}" }
my_hash = my_hash.reverse!
my_hash.each { |key,val| puts "#{key}: #{val}" }

# Being Selective
my_hash2 = { :a => 1, :b => 2, :c => 3}
puts my_hash2.select { |k,v| v > 2 }
#puts my_hash2.select { |k,v| k < :b } ## Ruby 1.9 and above
my_hash2.each_key { |k| puts k }  
my_hash2.each_value { |v| puts v }

# Other methods:
# .has_key?
# .has_value
# .empty?
# .size

#######################
# Functions, Methods, Blocks, Procs, lambdas
#######################
heading_generator("Functions")

# Functions (Methods)
def some_method(some_argument=true, *some_array)
	# if arg initialized, passing when calling optional
	## No need to 'return' -> implicit return
	## Can return multiple values ... returns an object
	### pointer used when unknown number of arguments
end

# Check to see if an object responds to a certain method
puts some_method.respond_to?(:next)
puts [1, 2, 3].respond_to?(:push)
puts [1, 2, 3].respond_to?(:to_sym)

# Blocks: anything between {} or do-end
1.times { print "." }
2.times do print ".." end 
puts " "
# abstracting: passing a block to a method

# Procs: save-able blocks
multiples_of_3 = Proc.new do |n|
  n % 3 == 0
end
print (1..100).to_a.select(&multiples_of_3)

hola = Proc.new { puts "\nHola World!" }
hola.call # Unlike blocks, one can 'call' procs

# collect! and map!
cube = Proc.new { |x| x ** 3 }
puts [1, 2, 3].collect!(&cube)
# ==> [1, 8, 27]
puts [4, 5, 6].map!(&cube)
# ==> [64, 125, 216]

# Convert symbols to procs using &
strings = ["1", "2", "3"]
nums = strings.map(&:to_i) # ==> [1, 2, 3]

# Lambdas: same as proc, 2 differences
  # 1. lambda checks the number of args passed to it
  # 2. when lambda returns, it passes control to the 
  #    calling method. Proc does not.
  # Can assign to a variable

sayHi = lambda do |string|  
	puts "Hello #{string}!"
end

sayHi.call("Bob")


#######################
# Modules
#######################

# Usually saved as a separate ruby file
# Toolbox that contains methods and constants
# Can't create instances or sub-classes
# Why? can add functionality to classes, as you can't inherit from multiple classes - can inherit multiple modules

module Circle # naming convention: CapitalizedCamelCase

	# Can have getter/setters like an object
	attr_accessor :name, :color, :diameter    # Can't change, symbols

	# Proper way of defining constants in modules, avoid warning
	unless (const_defined?(:PI))
		PI = 3.141592653589793 # naming ALL_CAPS
	end

	def says_Hi
		puts "Hi, this is #{@name} and you have called my method!"
	end

	def Circle.area(radius)
	PI * radius ** 2
	end

	def self.circumference(radius) # self refers to the current obj
	2 * PI * radius
	end
end

puts Circle.area(3)
puts Circle.circumference(3)
puts Circle::PI # name spacing with the scope resolution operator

# Some modules like Math are already present in the interpreter
# otherwise, have to require them
require 'date'
puts Date.today


#######################
# Objects
#######################
heading_generator("Objects")


class Balance
	include Math 
	prepend Circle    # Methods with same name in Circle will be called instead of the method defined in the class

	# allows instantiation of modules' constants and methods
	# A.K.A. mixing
	# "extend" mixes the methods at the class level
	# getters:
	attr_reader :name  # access the var from outside
	# setters:
	attr_writer :password # can only write to it/no access
	# both getter and setter:
	attr_accessor :bal  # can read/write it
	
	$SomeGlobalVar = true # or define outside any method/class
						  # can be changed from anywhere
	@@SomeClassVar = 0 # one copy shared by all instances
	@@users = {}


	# Constructor:
	def initialize(name, bal, username, password) 
		# boots up the object created
		@name = name # instance variables 
		@bal = bal
		@password = password
		@@SomeClassVar += 1 # keep track of number instances created
		@@users[username] = password
	end

	def says_Hi  # Over-ruled by the Circle module method
		puts "Oops"
	end

	def self.NumberOfInstances
		return @@SomeClassVar
	end

	# setter and getter methods defined manually
	def set_Name(new_name)
		if new_name.is_a? Numeric
			puts "Can't have numbers in the name"
		else
			@name = new_name
		end
	end

	def get_Name
		@name
	end

	# Class methods
	def Balance.get_users # class method to access class var
		@@users
	end

	# private: method cannot be interfaced outside the object
	# 		   cannot be called with an explicit receiver
	# public: by default
	def bank_account_number
		@bank_account_number = "1234" + @password.to_s
	end
end

# instantiation (making an instance of an object)
account1 = Balance.new("Flopsy", 100, "user1", 1111)
puts "Name on the account is: " + account1.get_Name
# set_New_Name = gets.chomp  # Works in the terminal, not sublime
# puts set_New_Name.class
set_New_Name = 1234
account1.set_Name(set_New_Name) # => Can't have numbers in the name
account1.says_Hi    # The superseding method in Circle module is called


puts account1.name # Instead of using the getter method
# puts account1.password    # NOT allowed; write-only
account1.bal = 200    # Read/Write enabled (accessor)
puts account1.bal
puts account1.respond_to?(:SomeMethod) # false
puts account1.bank_account_number 
account1.password = 2222    # Allowed as is write-only
puts account1.bank_account_number 


# Polymorphism: Inheritance
class CheckingAccount < Balance 
	def initialize(name, bal, username, password, type)
		# just use same names for vars and methods to override
		@type = type
		super(name, bal, username, password)
		# access/reference the attributes or methods of a superclass
		# NOT dummy arguments
	end
	# there is only one superclass -> No multi-inheritance
	# chain inheritance still works
	# the above instances of name & bal are NOT inherited, the init
	# method is "inherited".
end	

 
account2 = CheckingAccount.new("Flopsy", 2000, "user2", 4567, "Checking")

print "The number of accounts held at the bank = "
print Balance.NumberOfInstances, "\n" # it's Class method
puts Balance.get_users


# Polymorphism: Duck Typing

class Animal
	def tweet(animal_type) # takes in another object
		animal_type.tweet
	end
end

class Dog
	def tweet
		puts "Woof"
	end
end

class Cat
	def tweet
		puts "Meow"
	end
end

generic_animal = Animal.new
generic_animal.tweet(Dog.new) # => Woof
generic_animal.tweet(Cat.new) # => Meow


#######################
# Enumerable
#######################
heading_generator("Enumerable")

# yield: transferring control from the calling method to the 
# block and back again (can do with a parameter)
def yield_name(name)
  puts "In the method! Let's yield."
  yield name
  puts "Block complete! Back in the method."
end

yield_name("Booboo") { |name| puts "My name is #{name}." }
print "\n"

class Menu
	include Enumerable

	def each
		yield "pizza"
		yield "salad"
		yield "bread"
	end
end


menu_options = Menu.new
menu_options.each do |item|
	puts "Would you like: #{item}"
end


#######################
# File I/O
#######################
heading_generator("File I/O")

# Write to a file; will create if it doesn't exist
write_handler = File.new("someFile.out", "w")   # "a" append
write_handler.puts("Some Text, or variables or anything").to_s
write_handler.close

# Read from file
data_from_file = File.read("someFile.txt")
puts "Data From File: " + data_from_file



puts "THE END!"






