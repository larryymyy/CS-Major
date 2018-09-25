import java.util.Scanner;                         //import Scanner package

public class lab0 {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int numProblems = scanner.nextInt();          //retrieve the number of lines

		for(int i = 0; i < numProblems; ++i){
			int a = scanner.nextInt();                  //retrieve the first integer
			int b = scanner.nextInt();                  //retrieve the second integer

			int g = gcd(a,b);
			int l = lcm(a,b);

			System.out.println(g + " " + l);
		}

		scanner.close();
	}

	public static int gcd(int a, int b){
		// Find the greatest common divisor of a and b
		// Hint: Use Euclids Algorithm
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	public static int lcm(int a, int b){
		// Find the least common multiple of a and b
		// Hint: Use the gcd of a and b
		return a * (b / gcd(a, b));
	}
}
