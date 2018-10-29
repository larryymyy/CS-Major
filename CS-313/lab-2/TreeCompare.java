import java.util.Scanner;

public class TreeCompare {
	public static void main(String[] args) {
		// scan stdin
		Scanner scanner = new Scanner(System.in);

		// two different trees to operate one, to compare later
		BST<Integer> treeOne = new BST<Integer>();
		BST<Integer> treeTwo = new BST<Integer>();

		// Operate on first tree
		int treeOneOperations = Integer.parseInt(scanner.nextLine());
		for(int i = 0; i < treeOneOperations; i++) {
			operate(treeOne, scanner.nextLine().split("\\s+"));
		}

		// Operate on second tree
		int treeTwoOperations = Integer.parseInt(scanner.nextLine());
		for(int i = 0; i < treeTwoOperations; i++) {
			operate(treeTwo, scanner.nextLine().split("\\s+"));
		}

		// Compare the two trees and respond accordingly
		if(areEqual(treeOne.getRoot(), treeTwo.getRoot())) {
			System.out.println("The trees have the same shape.\n");
		} else {
			System.out.println("The trees do not have the same shape.\n");
		}

		// close the scanner and exit
		scanner.close();
		System.exit(0);
	}

	// Apply operation to tree
	public static void operate(BST<Integer> tree, String[] args) {
		// Apply appropriate operation on tree
		switch(args[0]) {
			case "insert":
				tree.insert(Integer.parseInt(args[1]));
				break;
			case "delete":
				tree.delete(Integer.parseInt(args[1]));
				break;
			default:
				break;
		}
	}

	// Compare two trees
	public static boolean areEqual(Node<Integer> a, Node<Integer> b) {
		// Empty trees have the same shape
		if(a == null && b == null){
			return true;
		}
		
		// If one node is null and the other is not, they cannot be equal
		if((a != null && b == null)
			|| (a == null && b != null)) {
			return false;
		}

		// Recursively check each sub tree
		return areEqual(a.getLeft(), b.getLeft())
			&& areEqual(a.getRight(), b.getRight());
	}
}
