# CS 314
### 28 Sept. 2018
---
## Bits and Bitwise Operators
+ Representing information as bits
+ Bit-level manipulations
+ Integers
	+ Representation: unsigned and signed
	+ Conversion, casting
	+ Sign extension
	+ Addition, negation, multiplication, shifting
---
## Boolean Algebra
+ Developed by George Boole in 19th Century
	- Algebraic representation of logic
		+ Encode "True" and "False"
+ Operate on Bit Vectors
	- Operations applied bitwise
+ &, |, ^, ~
+ & = AND
+ | = OR
+ ^ = XOR
+ ~ = NOT
//TODO: Add Logic Tables

<pre>
  01101001        01101001       01101001
& 01010101      | 01010101     ^ 01010101      ~ 01010101
+---------+     +---------+    +---------+     +---------+
  01000001        01111101       00111100        10101010
</pre>
---
## Contrast: Logic Operations in C
+ Contrast to Logical Operators
	- &&, ||, !
	- View 0 as 'False'
	- Anything non-zero is 'True'
	- Always return 0 or 1
	- *Early Termination*
+ Examples (char data type)
	- !0x41 -> 0x00
	- !0x00 -> 0x01
	- !!0x41 -> 0x01
	- 0x69 && 0x55 -> 0x01
	- 0x69 || 0x55 -> 0x01
	- p && *p (avoids null pointer access)
---
## Shift Operations
+ Left Shift: x << y
	- Shift bit-vector x left y positions
		+ Throw away extra bits on left
	- Fill with 0's on right
	- Example:
		+ 01100010 << 3 -> 00010000
+ Right Shift: x >> y
	- Shift bit-vector x right y positions
		+ Throw away extra bits on right
	- Logical Shift:
		+ Fill with 0's on the left
	- Arithmetic Shift
		+ Replace most significant bit on right
+ Undefined Behavior
