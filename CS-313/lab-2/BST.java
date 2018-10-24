
public class BST<E extends Comparable<E>> {
	// Properties of the BST
    private Node<E> root = null;

	// Constructor
    public BST() { root = null; }

	// Access data of the tree (i.e. root)
    public Node<E> getRoot() { return root; }

	// Insert a value into the BST
    public void insert(E data) {
        // Find the right spot in the tree for the new node
        // Make sure to check if anything is in the tree
        // Hint: if a node n is null, calling n.getData() will cause an error
		Node<E> current = this.root;
		if(current == null) {
			this.root = new Node<E>(data);
			return;
		}
		Node<E> parent = current.getParent();
		while(true) {
			if(data.compareTo(current.getData()) < 0) {
				parent = current;
				current = current.getLeftChild();
				if(current == null) {
					current = new Node<E>(data);
					current.setParent(parent);
					parent.setLeftChild(current);
					return;
				}
			} else if(data.compareTo(current.getData()) > 0) {
				parent = current;
				current = current.getRightChild();
				if(current == null) {
					current = new Node<E>(data);
					current.setParent(parent);
					parent.setRightChild(current);
					return;
				}
			} else {
				return;
			}
		}
    }

	// Find the node containing the passed data, if it exists
    public Node<E> find(E data) {
        // Search the tree for a node whose data field is equal to data
		Node<E> current = this.root;
		if(current == null)
			return null;
		while(true) {
			if(current.getData().compareTo(data) == 0) {
				return current;
			} else if(current.getData().compareTo(data) < 0) {
				current = current.getLeftChild();
				if(current == null)
					return null;
			} else {
				current = current.getRightChild();
				if(current == null)
					return null;
			}
		}
    }

	// Delete the node containing the passed data, if it exists
    public void delete(E data) {
        // Find the right node to be deleted

        // If said node has no children, simply remove it by setting its parent to point to null instead of it.
        // If said node has one child, delete it by making its parent point to its child.
        // If said node has two children, then replace it with its successor,
        //          and remove the successor from its previous location in the tree.
        // The successor of a node is the left-most node in the node's right subtree.
        // If the value specified by delete does not exist in the tree, then the structure is left unchanged.

        // Hint: You may want to implement a findMin() method to find the successor when there are two children
    }

	// Traverse the tree given an order and a root
    public void traverse(String order, Node<E> top) {
        if (top != null) {
            switch (order) {
                case "preorder":
                    // Your Code here
					System.out.print(top.getData() + " ");
					if(top.getLeftChild() != null)
						traverse("preorder", top.getLeftChild());
					if(top.getRightChild() != null)
						traverse("preorder", top.getRightChild());
                    break;
                case "inorder":
                    // Your Code here
					if(top.getLeftChild() != null)
						traverse("inorder", top.getLeftChild());
					System.out.print(top.getData() + " ");
					if(top.getRightChild() != null)
						traverse("inorder", top.getRightChild());
                    break;
                case "postorder":
                    // Your Code here
					if(top.getLeftChild() != null)
						traverse("postorder", top.getLeftChild());
					if(top.getRightChild() != null)
						traverse("postorder", top.getRightChild());
					System.out.print(top.getData() + " ");
                    break;
            }
        }
    }

	// Find the node containing the minimum value of the tree
    public Node<E> getMin(Node<E> top) {
        // Return the min node
		Node<E> current = this.root;
		while(current.getLeftChild() != null) {
			Node<E> parent = current;
			current = current.getLeftChild();
			current.setParent(parent);
		}
		return current;
    }
}
