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

		tree.insert(4);
		tree.insert(2);
		tree.insert(1);
		tree.insert(8);
		tree.insert(16);

		tree.traverse("preorder", tree.getRoot());
		System.out.println();
		tree.traverse("inorder", tree.getRoot());
		System.out.println();
		tree.traverse("postorder", tree.getRoot());
		System.out.println();

		tree.delete(1);

		tree.traverse("preorder", tree.getRoot());
		System.out.println();
		tree.traverse("inorder", tree.getRoot());
		System.out.println();
		tree.traverse("postorder", tree.getRoot());
		System.out.println();

		/*
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
		*/

        // Don't forget to close your Scanner!
		scanner.close();
		System.exit(0);
    }
}
