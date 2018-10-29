import java.util.Scanner;

public class lab2 {
	public static void main(String[] args) {
		// Scan stdin
		Scanner scanner = new Scanner(System.in);

		// create a new tree to operate on
		BST<Integer> tree = new BST<Integer>();

		int numLines = Integer.parseInt(scanner.nextLine());

		for(int i = 0; i < numLines; i++) {
			// Split line on space character
			String[] line = scanner.nextLine().split("\\s+");

			// Apply appropriate operation to the tree
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

		// close scanner and exit
		scanner.close();
		System.exit(0);
	}
}
