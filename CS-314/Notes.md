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
+ Left Shift: x \<\< y
	- Shift bit-vector x left y positions
		+ Throw away extra bits on left
	- Fill with 0's on right
	- Example:
		+ 01100010 \<\< 3 - 00010000
+ Right Shift: x \>\> y
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
	- B2U(X) = sum(0, w-1, x<sub>i</sub>\*2<sup>i</sup>)
+ Two's Complement
	- B2T(X) = -x<sub>(w-1)</sub>\*2<sup>(w-1)</sup>+sum(0, w-2, x<sub>i</sub>\*2<sup>i</sup>)

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
	- UMult(u, v) = u \* v mod 2<sup>w</sup>
+ Mult two 'ints' and store in a 'long'
---
### Power-of-2 Multiply with shift
+ Operation
	- u \<\< k gives u \* 2<sup>k</sup>
	- Both signed and unsigned
+ Examples
	- u \<\< 3 == u \* 8
	- u \<\< 5 - u \<\< 3 == u \* 24
	- Most machines shift and add faster than multiply
		+ Compiler generates this code automatically
---
### Power-of-2 Divide with Shift
+ Operation
	- u \>\> k gives floor(u / 2<sup>k</sup>)
	- Uses logical shift for unsigned, arithmetic shift for signed
---
### Why Should I Use Unsigned?
+ *Don't* Use Just Because Number Nonnegative
	- Easy to make mistakes
<pre>
unsigned i;
for (i = count-2; i >=0; i--)
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
		+ sum(k = -j, i, b<sub>k</sub> \* 2<sup>k</sup>)
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
	- (-1)<sup>s</sup> M 2<sup>E</sup>
	- Sign bit s determines whether number is negative or positive
	- Significand M normally a fractional value in range [1.0, 2.0)
	- Exponent E weights value by power of two
---
### 5 October 2018
---
### IEEE Floating Point Standard - Cont.
+ Encoding
	- MSB s is sign bit s
	- exp field encodes E (but is not equal to E)
	- frac field encodes M (but is not equal to M)  
__MIDTERM MATERIAL__  
+ Single Precision: 32-bits
+ Double Precision: 64 Bits
+ Extended Precision: 80 Bits (INTEL ONLY)
---
### "Normalized Values"
+ When: exp != 000...0 and exp != 111...1
	- Special Cases
+ Sign: 0 for positive, 1 for negative
+ Exponent coded as a biased value: E = Exp - Bias
	- Exp: unsigned value of exp field
	- Bias = 2<sup>(k-1)</sup> - 1, where k is number of exponent bits
		+ Single Precision: 127 (Exp: 1...254, E:-126...127)
		+ Double Precision: 1023 (Exp:1...2046, E:-1022...1023)
+ Significand coded with implied leading 1: M = 1.xxx...x<sub>2</sub>
	- xxx...x: bits of frac field
	- Minimum when frac=000...0 (M=1.0)
	- Maximum when frac=111.111 (M=2.0 -[e]) // [e] = epsilon
	- Get extra leading bit for "free" because significand is normalized and 1 is the only significant figure in binary

---
##### Example
<pre>
13.75
sign: 0
binary rep: 1101.11 * 2<sup>0</sup>
normalized: 1.10111 * 2<sup>3</sup>
E = 3
  + 127
  -----
exp:130
binary rep of exp: 10000010

binary rep of 13.75 encoded as IEEE 754 Single-Precision Floating-Point:
	0100 0001 0101 1100 0000 0000 0000 0000

hex rep of 13.75:
	0x415C0000
</pre>
__Second example on slides__
---
__GET SPECIAL CASES FROM SLIDES__
### Special Properties
+ FP Zero same as Integer 0
	- all bits = 0
+ Can (Almost) Use Unsigned Integer Comparison
	- Must first compare sign bits
	- Must consider -0 = 0
	- NaNs problematic
		+ Will be greater than any other values
---
### 8 October 2018
---
## Machine Programming I: Basics
---
+ History of Intel Processors and Architectures
+ C, assembly, machine code
+ Assembly Basic: Registers, operands, move
+ Arithmetic & logic operations
+ Conditional branches
+ Loops
---
### Intel x86 Processors
---
+ Dominate Laptop/Desktop/Server Market
+ Evolutionary Design
	- Backwards compatible up until 8086, introduce 1978
	- Added more features as time goes on
+ Complex instruct set computer (CISC)
	- Many different instructions with many different formats
		+ But, only small subset encountered with Linux programs
	- Hard to match performance of Reduced Instruction Set Computers (RISC)
	- But, Intel has done just that!
		+ In terms of speed. Less so for low power.
---
### C, Assembly, Machine Code
---
#### Definitions
---
+ Instruction Set Architecture: (also ISA) The parts of a processor design that one needs to understand or write assembly/machine code.
	- Examples: instruction set specification, registers.
+ Microarchitecture: Implementation of the architecture
	- Examples: cache sizes and core frequency
+ Code Forms:
	- Machine Code: The byte-level programs that a processor executes
	- Assembly Code: A text representation of machine code
+ Example ISAs:
	- Intel: x86m IA32, Itanium, x86-64
	- ARM: Used in almost all mobile phones
---
### Assembly/Machine Code View
---
#### Programmer-Visible State
+ PC: Program Conunter
	- Address of next instructions
	- Called "RIP" (x86-64)
+ Register File
	- Heavily used program data
+ Condition codes
	- Stores status information about most recent arithmetic or logical operation
	- Used for conditional branching
+ Memory
	- Byte addressable array
	- Code and user data
	- Stack to support procedures
---
### Assembly Characteristics: Data Types
---
+ "Integer" data of 1, 2, 4, or 8 bytes
	- Data values (signed, unsigned)
	- Addresses (untyped pointers)
+ Floating Point data of 4, 8, or 10 bytes
+ No aggregate types such as arrays of structures
	- Just contiguously allocated bytes in memory
---
### Assembly Characteristics: Instructions
---
+ 3 basic types:
	- Arithmetic:
		+ Perform arithmetic function on register or memory data
	- Data transfer:
		+ Load data from memory into register
		+ Store register data into memory
	- Control:
		+ Unconditional jumps to/from procedures
		+ Conditional branches
---
### 10 October 2018
---
### Assembly Basics: Registers, Move, Operands
---
#### x86-64 Integer Registers
+ 16, 64-bit Registers
+ %rax is return register
+ x86-64 allows for access to most of the lower size registers
+ %rsp, %rbp, %ebp are special
---
#### Moving Data
+ Moving Data
	- movq *Source, Dest*
	- Actually a copy instruction, does not clear source register
+ Operand Types
	- __Immediate__: Constant Integer Data
		+ Example: $0x400, $-533
		+ Like C constant, but prefixed with '$'
		+ Encoded with 1, 2, 4, or 8 bytes
	- __Register__: One of 16 integer registers
		+ Example: _%rax, %r13_
		+ But _%rsp_ reserved for special use
		+ Others have special uses for particular instructions
	- __Memory__: 8 consecutive bytes of memory at address given by register
		+ Simplest example: _(%rax)_
		+ Various other "address modes"
