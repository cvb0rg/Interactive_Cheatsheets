# Ruby load example

# Usual variables are local only
variableFromLoadRubyExample = 42

# Will get executed with both load and require
puts "variableFromLoadRubyExample is: " + variableFromLoadRubyExample.to_s

# Constants (which include modules and classes) 
# are added to the shared global environment
C_STRING ||= "Constants added to the shared global environment"

# Instance variables declared in main are all part of the same main
@instance_variable = "Instance variable part of the same main"

# Global variables are also all part of the same environment 
$global_variable = "Global variables are also all part of the same environment"


