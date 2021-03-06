# schemeMate

schemeMate is a command line interpreter for the [scheme](http://www.scheme.com/tspl4/intro.html#./intro:h1) language written in C. 

## Installation:

Clone the repository and execute "make" to build the source code.  
If you have make and gcc installed and in your path environment,  
you can afterwards launch schemeMate by typing "schemeMate".  

====================================================================

The repository also contains config files to use Visual Studio Code  
in combination with GCC / GDB to develop with the interpreter.  
The json config files would need to be adopted to your compiler location.  

====================================================================

### Types:  
* #t - Logical True
* #f - Logical False
* #void - Empty Type
* 42 - Numbers (integer)
* nil/() - Null Type
* "a" - Strings
* cons/car/cdr - List Access
* functions
* symbols

### Implemented math functions:  
* "+" - Addition
* "-" - Substraction
* "*" - Multiplikation
* "/" - Division
* max - Maximum
* min - Minimum
* magnitude - Absolute Value
* modulo - Modulo Operation

### Implemented logic functions:  
* eq? - Memory based comparison (eq? Auto Auto) => #t
* = - Number based comparison (= 5 4 3) => #f
* string= - String based comparsion (string= "abc" "abc") => #t
* </> <=/>= - lesser / greater equal then
* and / or / not - logic operators
* if - conditional function in the form (if cond-expr if-expr else-expr)

### Implemented list functions:
* car - Returns head element of a list
* cdr - Returns tail element of a list
* cons - Constructs a new list from given element and list
* list - Constructs a list from the given arguments

### Implemented type check functions:  
* int? - All parameters int type?
* string? - All parameters string type?
* zero? - All parameters 0?
* pos? - All parameters positive?
* neg? - All parameters negative?

### Implemented utility functions:  
* display - prints the given input to the console
* ' - uses the given input without evaluating it
* exit - exits the program with the given error code
* define - define new symbols or functions
* set! - override existing symbols or functions
* mode - Switches between CP and recursive mode. 1 for recursive, 2 for CP-Style

### Possible future Improvemenets:
* Garbage Collection
* Overflow / Underflow Detection
* State Serialization

// Stefan Seibert, September 2017
