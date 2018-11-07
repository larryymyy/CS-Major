#include <stdio.h>
#include <stdlib.h>

/* NOTE:
 * - you may not use atoi
 * - you may not use *any* built-in functions -- strlen, strcpy, etc.
 * - you may assume all integers have <10 digits
 */

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <integer> <+ or -> <integer>", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *number1 = argv[1];
    char *operation = argv[2];
    char *number2 = argv[3];

    /* Turn number1 into an integer.  You will need to do this by
       looking at the character string one character at a time, and multiplying
       by 10 as you go.
       For example: if the string is "214", then I would start by finding the
       '2'.  I would think (for the time being) the number is 2.  When I go
       to the next character, I would see the "1".  I would then make the 
       number 21, by multiplying my previous number (2) by 10 and adding the
       current number (1) ... 2*10+1 = 21.
       The next number is 4.  Again, take the previous number (21) times 10
       and add the current number (4).  This makes 214.
       The next character is the NULL character.  So we are done parsing the
       string.  And stop at 214.
       TRICK #1! --->
          char digit = '5';
          int digit_as_number = digit - '0'; <--- gives you 5.
       TRICK #2! --->
          when you encounter a '\0', then use break to terminate the loop
          right then.
     */

	int first_number = 0;
	for(int i = 0; i < 10; i++) {
		if(number1[i] == '\0')
			break;
		first_number *= 10;
		first_number += (number1[i] - '0');
	}

    /* Now figure out which operation to do: plus or minus.
       You will do this by inspecting the variable named "operation". */

    /* Now turn number2 into an integer. */
	int second_number = 0;
	for(int i = 0; i < 10; i++) {
		if(number2[i] == '\0')
			break;
		second_number *= 10;
		second_number += (number2[i] - '0');
	}

    /* Perform the operation and print the result */
	switch(operation[0]) {
		case '-':
			printf("%d\n", first_number - second_number);
			break;
		case '+':
			printf("%d\n", first_number + second_number);
			break;
		default:
			break;
	}

	return 0;
}
