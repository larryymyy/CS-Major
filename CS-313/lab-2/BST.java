public class BST<E extends Comparable<E>> {
	// BST properties
	private Node<E> root;

	// Constructor
	public BST() { this.root = null; }

	// Access data of BST
	public Node<E> getRoot() { return this.root; }

	// Insert value into BST
	public void insert(E data) {
		// Create a new node with the passed data
		Node<E> newNode = new Node<E>(data);

		// If the tree is empty, set the root the new node and return
		if(this.root == null) {
			this.root = newNode;
			return;
		}


		// Iterate through tree to find proper spot
		// Keep track of current node AND parent
		Node<E> current = this.root;
		Node<E> parent = null;
		while(true) {

			// Update parent node to current (current is about to be changed)
			parent = current;

			// If current holds the same value as the data passed, return (duplicate value)
			if(data.compareTo(current.getData()) == 0) {
				return;
			}
			
			// If the data passed is less than current's value, set current to its left child.
			else if(data.compareTo(current.getData()) < 0) {
				current = current.getLeft();

				// If current had no left child, create a left child with the node created at the beginning.
				if(current == null) {
					parent.setLeft(newNode);
					return;
				}
			}
			
			// If the data passed is greater than current's value, set current to its right child.
			else {
				current = current.getRight();

				// If current had no right child, create a right child with the node created at the beginning.
				if(current == null) {
					parent.setRight(newNode);
					return;
				}
			}
		}
	}


	// Find node containing value in BST
	public Node<E> find(E data) {
		// Initialize current the top of the BST
		Node<E> current = this.root;
		while(current != null) {

			// If the current node holds the value of the passed data, return the current node
			if(data.compareTo(current.getData()) == 0) {
				return current;
			}

			// If the current node holds a value greater than the passed data, set current to its left child
			else if(data.compareTo(current.getData()) < 0) {
				current = current.getLeft();
			}

			// If the current node holds a value less than the passed data, set current to its right child
			else {
				current = current.getRight();
			}
		}

		// If the node containing the passed data was not found, return null
		return null;
	}

	// Delete the node containing value in BST
	public void delete(E data) {

		// Keep track of parent node and current node
		Node<E> parent = this.root;
		Node<E> current = this.root;

		// Keep track of what side the current node is on in relation to its parent (left child or right child?)
		boolean isLeft = false;

		// Iterate until the node containing the passed value is found
		while(current.getData().compareTo(data) != 0) {
			// Update parent
			parent = current;

			// If current node holds a value less than the passed data, set current to its left child
			// the current node is a left child of the parent
			if(data.compareTo(current.getData()) < 0) {
				isLeft = true;
				current = current.getLeft();
			}
			
			// Otherwise, the current node is a right child of the parent
			// Set current to its right child
			else {
				isLeft = false;
				current = current.getRight();
			}

			// If current does not exist (i.e. node containing value does not exist), return
			if(current == null) {
				return;
			}
		}

		// Case 1: No Children
		if(current.getLeft() == null && current.getRight() == null) {
			// Delete node, with no regard for a successor as it has no children
			if(current == this.root) {
				this.root = null;
			}
			if(isLeft) {
				parent.setLeft(null);
			}
			else {
				parent.setRight(null);
			}
		}

		// Case 2: One Child
		// Current has a left child
		else if(current.getRight() == null) {
			// If current is the root, set the root to current's child
			if(current == this.root) {
				this.root = current.getLeft();
			}
			
			// If current is a left child, set the parent's left child to current's child
			else if(isLeft) {
				parent.setLeft(current.getLeft());
			}

			// Otherwise, set the parent's right child to current's child
			else {
				parent.setRight(current.getLeft());
			}
		}
		
		// Current has a right child
		else if(current.getLeft() == null) {
			// If current is the root, set the root to current's child
			if(current == this.root) {
				this.root = current.getRight();
			}

			// If current is left child, set the parent's left child to current's child
			else if(isLeft) {
				parent.setLeft(current.getRight());
			}

			// Otherwise, set the parent's right child to current's child
			else {
				parent.setRight(current.getRight());
			}
		}

		// Case 3: Two Children
		else if(current.getLeft() != null && current.getRight() != null) {
			// Find a successor for current
			Node<E> successor = getSuccessor(current);

			// If current is the root, set the root to current's successor
			if(current == this.root) {
				this.root = successor;
			}

			// If current is a left child, set the parent's left child to current's successor
			else if(isLeft) {
				parent.setLeft(successor);
			}

			// Otherwise, set the parent's right child to current's successor
			else {
				parent.setRight(successor);
			}
			successor.setLeft(current.getLeft());
		}

		return;
	}

	// Find the successor of a node (to be deleted)
	private Node<E> getSuccessor(Node<E> root) {
		// track current successor, parent, and current node
		Node<E> successor = null;
		Node<E> successorParent = null;
		Node<E> current = root.getRight();

		// Traverse the right sub tree of root
		while(current != null) {
			// Update parent, successor, and current
			successorParent = successor;
			successor = current;
			current = current.getLeft();
		}

		if(successor != root.getRight()) {
			successorParent.setLeft(successor.getRight());
			successor.setRight(root.getRight());
		}

		return successor;
	}

	// Traverse BST and print result
	public void traverse(String order, Node<E> root) {
        if (root != null) {
            switch (order) {
                case "preorder":
					System.out.print(root.getData() + " ");
					if(root.getLeft() != null)
						traverse("preorder", root.getLeft());
					if(root.getRight() != null)
						traverse("preorder", root.getRight());
                    break;
                case "inorder":
					if(root.getLeft() != null)
						traverse("inorder", root.getLeft());
					System.out.print(root.getData() + " ");
					if(root.getRight() != null)
						traverse("inorder", root.getRight());
                    break;
                case "postorder":
					if(root.getLeft() != null)
						traverse("postorder", root.getLeft());
					if(root.getRight() != null)
						traverse("postorder", root.getRight());
					System.out.print(root.getData() + " ");
                    break;
            }
        }
	}
}
