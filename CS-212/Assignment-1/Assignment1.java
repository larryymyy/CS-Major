import java.util.Scanner;

public class Assignment1 {
    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);

        int input;
        int sum = 0;

        while(true) {
            // #1: Display text asking the user to enter an integer
            System.out.println("Enter a positive integer (-3 to print, -2 to reset, -1 to quit):");
            
            // #2: Read an integer from the user
            input = scan.nextInt();
            
            // #3: If the user entered '-3', prints sum and asks for another integer
            if(input == -3) {
                System.out.printf("Sum: %d\n", sum);
            }

            // #4: If the user entered '-2', sets the current sum to 0 and asks for another integer
            else if(input == -2) {
                sum = 0;
            }

            // #5: If the user entered '-1', prints sum and quits the application
            else if(input == -1) {
                System.out.printf("Sum: %d\n", sum);
                break;
            }

            // #6: If the user entered a positive integer, add it to the current sum
            else if(input > 0) {
                sum += input;
            }

            //#7: Ignores any number equal to 0 and less than -3 and 
        }
		System.exit(0);
    }
}
