import java.util.Scanner;

public class EC {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int numProblems = Integer.parseInt(scanner.nextLine());
		for(int i = 0; i < numProblems; i++) {
			String test = scanner.nextLine();
			if(isPalindrome(test)) {
				System.out.println("This is a Palindrome.");
			} else {
				System.out.println("Not a Palindrome.");
			}
		}
		scanner.close();
		System.exit(0);
	}

	public static boolean isPalindrome(String s) {
		TwoStackQueue<Character> queue = new TwoStackQueue<Character>();
		Stack<Character> stack = new Stack<Character>();
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
