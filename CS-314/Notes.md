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
+ ~ = NOT<br/>
<pre>
AND
'&' | 0 | 1
  --+---+---
  0 | 0 | 0
  --+---+---
  1 | 0 | 1
</pre><br/>
<pre>
OR
'|' | 0 | 1
  --+---+--
  0 | 0 | 1
  --+---+--
  1 | 1 | 1
</pre><br/>
<pre>
XOR
'^' | 0 | 1
  --+---+--
  0 | 0 | 1
  --+---+--
  1 | 1 | 0
</pre><br/>

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
	- !0x41 - 0x00
	- !0x00 - 0x01
	- !!0x41 - 0x01
	- 0x69 && 0x55 - 0x01
	- 0x69 || 0x55 - 0x01
	- p && \*p (avoids null pointer access)
---
## Shift Operations
+ Left Shift: x << y
	- Shift bit-vector x left y positions
		+ Throw away extra bits on left
	- Fill with 0's on right
	- Example:
		+ 01100010 << 3 - 00010000
+ Right Shift: x >> y
	- Shift bit-vector x right y positions
		+ Throw away extra bits on right
	- Logical Shift:
		+ Fill with 0's on the left
	- Arithmetic Shift
		+ Replace most significant bit on right
+ Undefined Behavior
---
### 1 October 2018
---
## Encoding Integers
+ Unsigned
	- B2U(X) = sum(0, w-1, x\_i\*2^i)
+ Two's Complement
	- B2T(X) = -x\_(w-1)\*2^(w-1)+sum(0, w-2, x\_i\*2^i)

<pre>
short int x =  15213;
short int y = -15213;
</pre>

+ C short <b>2 bytes</b> long
+ Sign Bit
	- For Two's Complement, most significant bit indicates sign
		+ 0 for nonnegative
		+ 1 for negative
---
## Negation: Complement and Increment
+ Claim: following holds for Two's Complement
<pre>~x + 1 = -x</pre>
+ Complement
	- Observation: ~x + x == 1111...111 == -1
<pre>
   x | 10011101
+ ~x | 01100010
---------------
  -1 | 11111111
</pre>
---
## Casting Suprises
+ Expression Evaluation
	- If there is a mix of unsigned and signed in single expression, <b><i>signed values implicitly cast to unsigned</i></b>
	- Including comparison operations <, >, ==, <=, >=
	- Examples for W = 32: <b><i>TMIN = -2,147,483, 648 | TMAX = 2,147,483,647</i></b>
## Sign Extension
+ Task:
	- Given w-bit signed integer x
---
### 3 October 2018
---
### Addition, Negation, Mutiplication, and Shifting
<b><i>CHECK SLIDES FOR NOTES</i></b>
---
### Multiplication in C
+ Standard Multiplication Function
	- Ignores high order *w* bits
+ Implements Modular Arithmetic
	- UMult(u, v) = u \* v mod 2^w
+ Mult two 'ints' and store in a 'long'
---
### Power-of-2 Multiply with shift
+ Operation
	- u \<\< k gives u \* 2^k
	- Both signed and unsigned
+ Examples
	- u \<\< 3 == u \* 8
	- u \<\< 5 - u \<\< 3 == u \* 24
	- Most machines shift and add faster than multiply
		+ Compiler generates this code automatically
---
### Power-of-2 Divide with Shift
+ Operation
	- u \>\> k gives floor(u / 2^k)
	- Uses logical shift for unsigned, arithmetic shift for signed
---
### Why Should I Use Unsigned?
+ *Don't* Use Just Because Number Nonnegative
	- Easy to make mistakes
<pre>
unsigned i;
for (i = cnt-2; i >=0; i--)
	a[i] += a[i+1];
</pre>
+ *Do* Use When Using Bits to Represent Sets
	- Logical right shift, no sign extension
---
## Floating Point Representations
---
### Fractional binary numbers
+ 1110011 can represent lots of things
	- Positive Integer
	- Negative Integer
	- Character in a string
	- Color
	- Etc.
+ What is 111.0011?
+ Representation
	- Bits to the right of "binary point" represent fractional powers of 2
	- Represents rational number
		+ sum(k = -j, i, b\_k \* 2^k)
+ Back to 111.0011
	- 111 . 0011
	- 4 + 2 + 1 . (0 + 0 + .125 + 0625)
	- 7.1875
---
### IEEE Floating Point Standard
+ IEEE Standard 754
	- Established in 1985 as uniform standard for floating point arithmetic
		+ Before that, many idiosyncratic formats
	- Supported by all major CPU's
+ Driven by numerical concerns
	- Nice standards for rounding, overflow, underflow, infinity
	- Hard to make fast in hardward
		+ Numerical analysts predominated over hardware designers in defining standard
		+ Lots of cases!
+ How to encode / decode?
+ Numerical Form
	- (-1)^s M 2^E
	- Sign bit s determines whether number is negative or positive
	- Significand M normally a fractional value in range [1.0, 2.0)
	- Exponent E weights value by power of two
