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

<pre>
AND
'&' | 0 | 1
  --+---+---
  0 | 0 | 0
  --+---+---
  1 | 0 | 1
</pre>

<pre>
OR
'|' | 0 | 1
  --+---+--
  0 | 0 | 1
  --+---+--
  1 | 1 | 1
</pre>

<pre>
XOR
'^' | 0 | 1
  --+---+--
  0 | 0 | 1
  --+---+--
  1 | 1 | 0
</pre>

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
---
### LEAQ
---
+ Load Effective Address [Quad]
+ Arithmetic Instruction to calculate address ONLY
+ leaq SRC, DEST
+ DOES NOT MOVE DATA
---
### Conditional Statements and Loops
---
+ Single bit registers
	- CF [Carry Flag]
	- ZF [Zero Flag]
	- SF [Sign Flag]
	- OF [Overflow Flag]
+ Implicitly set (think of it as side effect) by arithmetic operations
	- Example: <b>addq</b> Src, Dest \<-\> t = a + b
	- CF set if carry out from most significant bit (unsigned overflow - we'll ignore this)
	- ZF set if t == 0
	- SF set if t < 0
	- OF set if two's complement (signed overflow)
+ Not set by leaq or movq instructions
+ Explicitly Setting by Compare Instruction
	- cmpq Src2, Src1
		+ cmpq b,a like computing a- b without setting destination
	- ZF set if a==b
	- SF set if (a-b) < 0 (signed)
	- OF set if two's complement (signed) overflow
+ Explicitly Setting by Test instruction
	- testq Src2, Src1
		+ testq b,a like computing a&b without setting destination
	- ZF set when a&b == 0
---
### Jumping
+ jX instructions
	- Jump to different part of code depending on condition codes
+ __MAKE TABLE FROM SLIDES__
---
### Loops
---
404. Line not found  
---
#### Do-While Loop Example
+ Consider this C code
<pre>
long pcount_do(unsigned long x) {
	long result = 0;
	do {
		result += x & 0x1;
		x >>= 1;
	} while(x);
	return result;
}
</pre>
<pre>
long pcount_goto(unsigned long x) {
	long result = 0;
loop:
	result += x & 0x1;
	x >>= 1;
	if(x) goto loop;
	return result;
}
</pre>
+ __POTENTIAL MIDTERM QUESTION__
+ Count the number of 1's in argument x ("popcount")
+ Use conditional branch to either continue looping or to exit loop
+ CONSTANTS allow compiler to optimize quite a bit
---
### Procedures
---
+ Stack Structure
+ Passing control
+ Passing data
+ Managing local data
+ Illustration of Recursion
---
#### Mechanisms in Procedures
+ Passing Control
	- To beginning of procedure code
	- Back to return point
+ Passing Data
	- Procedure arguments
	- Return Value
+ Managing local data
	- Allocate during procedure execution
	- Deallocate upon return
+ Mechanisms all implemented with machine instructions
---
#### x86-64 Stack
+ Region of memory managed with stack discipline
+ Grows toward lower address
+ Register <b>%rsp</b> contains lowest stack address
	- Address of "top" element
+ <b>pushq Src</b>
	- Fetch operand at Src
	- Decrement <b>%rsp</b> by 8
	- Write operand at address given by <b>%rsp</b>
+ <b>popq Dest</b>
	- Read value at address given by %rsp
	- Increment %rsp by 8
	- Store value at Dest (must be register)
---
#### Procedure Conrole Flow
+ Use stack to support procedure call and return
+ Procedure call: <b>call label</b>
	- Push return address on stack
	- Jump to label
+ Return address:
	- Address of the next instruction right after call
	- Example from disassembly
+ Procedure return: ret
	- Pop address from stack
	- Jump to address
+ __POTENTIAL MIDTERM QUESTION__
---
#### 17 October 2018
---
#### Passing data
+ First 6 Arguments:  
<pre>
%rdi
%rsi
%rdx
%rcx
%r8
%r9
</pre>
+ Return value:  
<pre>
%rax
</pre>
+ Stack:  
<pre>
...
Arg <i>n</i>
...
Arg 8
Arg 7
</pre>
+ Only allocate stack space when needed
	- If args > 6, extra args get pushed to the stack
---
#### Register Saving Conventions
+ When procedure <code>yoo</code> calls <code>who</code>
	- <code>yoo</code> is the __caller__
	- <code>who</code> is the __callee__
+ Can register be used for temporary storage?  
# FIXME
---
<code>
yoo:  
	...  
	movq $15213, %rdx  
	call who  
	addq %rdx, %rax  
	...  
	ret  
who:  
	...  
	subq $18213, %rdx  
	...  
	ret  
</code>
---
+ Contents of register %rdx overwritten by <code>who</code>.
+ This could be trouble, something should be done.
	- Need some coordination
+ Conventions
	- "Caller saved"
	- "Callee saved"
+ %rax
	- Return value
	- Also caller-saved
	- Can be modified by procedure
+ %rdi, ... %r9
	- Arguments
	- Also caller-saved
	- Can be modified by procedure
+ %r10, %r11
	- Caller saved
---
#### Managing Local Data
+ Languages that support recursion
	- C, Pascal, Java
	- Code must be "Reentrant"
		+ Multiple simultaneous instantiations of single procedure
	- Need some place to store state of each instantiation
		+ Arguments
		+ Local variables
		+ Return address
+ Stack allocated in Frames
	- State for single procedure instantiation
	- Data for given procedure needed for limited time
		+ From when called to when return
#### Stack Frames
+ Contents
	- Return information
	- Local Storage
	- Temporary Storage
+ Management
	- Space allocated when enter procedure
		+ "Set-up" code
		+ Includes push by call instruction
	- Deallocated when return
		+ "Finish" code
		+ Includes pop by ret instruction
---
#### 22 October 2018
---
<b><i>Practice Midterm Questions will be posted on Piazza (Noted: 22 October 2018)</i></b></br>
<b><i>Know %rax (RETURN), %rdi (ARG 0), %rsi (ARG 1)</i></b></br>
<b><i>Know Memory Address Calculation Equation!!!</i></b></br>
<<<<<<< HEAD
---
#### 24 October 2018
---
### Structures
+ Structure represented as a block of memory
	- Big enough to hold all the fields
+ Fields ordered according to declaration
	- Even if another ordering could yield a more compact representation
+ Compiler determines overall size + positions of fields
	- Machine-level program has no understanding of the structures in the source code
+ Generating Pointer to Array Element
	- Offset of each structure member determined at compile time
---
Why does C refuse to die?

---
### Memory Layout
+ Stack
	- Runtime Stack
	- E.g. Local Variable
+ Heap
	- Dynamically Allocated as needed
	- When calling malloc(), new X(), etc.
+ Data
	- Statically allocated data
	- E.g. global variables, static variables, string constants
+ Text
	- Executable machine instructions
	- Read-only
---
### Buffer Overflow
+ Memory reference bugs
+ Generally called a "buffer overflow"
	- when exceeding the memory size allocated for an array
+ Why a big deal?
	- Its the #1 technical cause of security vulnerabilities
+ Most common form
	- Unchecked lengths on string inputs
+ Code Injection
	- Input string contains byte representation of executable code
	- Overwrite return address A with address of buffer B
	- When Q executes ret, will jump to exploit code
---
#### 31 October 2018
---
# Y86-64
---
+ Program Registers
	- 15 registers (omit %r15). Each 64 bits
+ Condition Codes
	- Single bit flags set by arithmetic or logical instructions
	- ZF, Zero
	- SF, Negative (Sign)
	- OF, Overflow
+ Program counter
	- Indicates address of next instruction
+ Program Status
	- Indicates either normal operation or some error condition
+ Memory
	- Byte-addressable storage array
	- Words stored in little-endian byte order
---
### Format
---
+ 1-10 bytes of information read from memory
	- Can determine instruction length from first byte
	- Not as many instruction types, and simpler encoding than with x86-64
+ Each accesses and modifies some part(s) of the program state
+ Each register has a 4-bit ID
	- Same encoding as x86-64
+ Register ID 15 (0xF) indicates "no register"
	- Will use this in our hardware design in multiple places
---
### Instructions
---
+ Addition
	- Add value in register rA to that in register in rB
		+ Store result in register rB
		+ Note that Y86-64 only allows addition to applied to register data
	- Set condition codes based on result
	- eg. addq %rax, %rsi
		+ Encoding: 60 06
	- Two-byte encoding
		+ First indicates instruction type
		+ Second gives source and destination registers
+ Arithmetic and Logical Operations
	- Refer to generically as OPq
	- Encodings differ only by "function code"
		+ Low-order 4 bytes in first instruction word
	- Set condition codes as side effect
+ Move Operations
	- Like the x86-64 movq instruction
	- Simpler format for memory addresses
	- Give different names to keep them distinct
+ Conditional Move Instructions
	- Refer to generically as "cmovXX"
	- Encodeings differ only by "function code"
	- Based on values of condition codes
	- Variants of rrmovq instruction
		+ (Conditionally) copy value from source to destination register
+ Jump Instructions
	- Refer to generically as "jXX"
	- Encodings differ only by "function code"
+ Stack operations
	- pushq
	- popq
+ Subroutines
	- call
	- ret
+ Misc.
	- nop
	- halt
---
### Status Conditions
---
+ Normal Operation
+ Halt Instruction
+ Bad Address Encountered
+ Invalid instruction encountered
---
#### 2 November 2018
---
### Overview of Logic Design
---
+ Fundamental Hardware Requirements
	- Communication
		+ How to get values from one place to another
	- Computation
	- Storage
+ Bits are our friends
	- Everything expressed in terms of values of 0 and 1
	- Communication
		+ Low or High Voltage on wire
	- Computation
		+ Compute boolean functions
	- Storage
		+ Store bits of information
+ Computing with Logic Gates
	- Outputs are boolean functions of input
	- Respond continuously to changes in inputs
		+ With some, small delay
+ Bit Level Multiplexor
	- Control signal s
	- Data signals a and b
	- Output a when s=1, b when s=0
+ ALU
	- Combinational Logic
	- Control Signal selects function computed
	- Also computes values for condition codes
---
#### 5 November 2018
---
#### SEQ Stages
+ Fetch
	- Read instruction from instruction memory
+ Decode
	- Read program registers
+ Execute
	- Compute value or address
+ Memory
	- Read/Write Data
+ Write Back
	- Write Program Registers
+ PC
	- Update program counter
---
#### Instruction Decoding
+ Instruction Format
	- Instruction byte
	- Optional register byte
	- Optional constant word
+ Example:
	- icode:ifun rA:rB valc
	- Instruction
		+ icode:ifun
	- Register Byte
		+ rA:rB
	- Constant Word
		+ valc
---
### Y86-64
---
# GET FROM SLIDES (Week 7)
#### Fetch Logic
+ Predefined Blocks
	- PC: Register containing PC
	- Instruction Memory: Read 10 bytes (PC -> PC + 9)
	- Split: Divide instruction byte into icode and ifun
	- Align: Get fields for rA, rB, and valC
+ Constrol Logic:
	- Need regids: Does this instruction have a register byte?
	- Need valC: Does this instruction have a constant word?

#### Decode Logic
+ Register File
	- Read ports A, B
	- Write ports E, M
	- Addresses are register IDs or 15(0xF) (no access)
+ Control Logic:
	- srcA, srcB: read port addresses
	- dstE, dstM: write port addresses

#### Execute Logic
+ Units
	- ALU
		+ Implements 4 required functions
