import java.util.Scanner;

public class lab2 {
    public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

        // Loop over the Scanner
        // Split each line into the task and the corresponding number (if one exists)
        // Depending on what the input task was, preform the corresponding function
        //      (ie) insert, delete, find, inoder, preorder, or postorder
        // Hint: Use a switch-case statement

		BST<Integer> tree = new BST<Integer>();

		int numLines = scanner.nextInt();
		scanner.nextLine();

		while(scanner.hasNextLine()) {
			String[] line = scanner.nextLine().split("\\s+");
			switch(line[0]) {
				case "insert":
					tree.insert(Integer.parseInt(line[1]));
					break;
				case "delete":
					tree.delete(Integer.parseInt(line[1]));
					break;
				case "preorder":
					tree.traverse(line[0], tree.getRoot());
					System.out.println();
					break;
				case "inorder":
					tree.traverse(line[0], tree.getRoot());
					System.out.println();
					break;
				case "postorder":
					tree.traverse(line[0], tree.getRoot());
					System.out.println();
					break;
				default:
					break;
			}
		}

        // Don't forget to close your Scanner!
		scanner.close();
		System.exit(0);
    }
}
