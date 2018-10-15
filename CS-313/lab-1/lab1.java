import java.util.Scanner;

public class lab1 {
	public static void main(String[] args){
	
		// Create a Scanner that reads system input
		Scanner scanner = new Scanner(System.in);
		int numProblems = Integer.parseInt(scanner.nextLine());
		
		// Loop over the scanner's input
		// For each line of the input, send it to isPalindrome()
		// If isPalindrome returns true, print "This is a Palindrome." 
		// Otherwise print "Not a Palindrome."
		for(int i = 0; i < numProblems; i++) {
			String test = scanner.nextLine();
			if(isPalindrome(test)) {
				System.out.println("This is a Palindrome.");
			} else {
				System.out.println("Not a Palindrome.");
			}
		}
		
		// Close the Scanner
		scanner.close();
		System.exit(0);

	}
	
	public static boolean isPalindrome(String s){
		// Create a stack and a Queue of chars that represents the passed in string
		// Hint: While you loop through the given string, push the same char onto your stack
		//		 that you enqueue into your Queue. This way you can use dequeue to get 
		//       the string from left to right, but you pop the string from right to left
		
		// Compare your Queue and Stack to see if the input String was a Palindrome or not	
		Stack<Character> stack = new Stack<Character>();
		Queue<Character> queue = new Queue<Character>();
		for(char c : s.toCharArray()) {
			stack.push(c);
			queue.enqueue(c);
		}
		while(!stack.isEmpty() && !queue.isEmpty()) {
			if(stack.pop().getData() != queue.dequeue().getData()) {
				return false;
			}
		}
		return true;
	}
}
