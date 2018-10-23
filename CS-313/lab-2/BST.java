public class BST<E extends Comparable<E>>{
	// Node Class
	class Node<E extends Comparable<E>> {
		private E data;
		private Node<E> leftChild = null, rightChild = null, parent = null;

		// Constructor
		public Node(E data) { this.data = data; }

		// Methods for accessing data in the node
		public void setData(E data) { this.data = data; }
		public E getData() { return this.data; }
		public void setLeftChild(Node<E> child) { this.leftChild = child; }
		public Node<E> getLeftChild() { return this.leftChild; }
		public void setRightChild(Node<E> child) { this.rightChild = child; }
		public Node<E> getRightChild() { return this.rightChild; }
		public void setParent(Node<E> parent) { this.parent = parent; }
		public Node<E> getParent() { return this.parent; }
	}


	// Top of the tree
	private Node<E> root;

	// Constructor
	public BST() { this.root = null; }

	// Get root of tree
	public Node<E> getRoot() { return this.root; }

	// Insert a value into the tree
	public void insert(E data) {
		Node<E> current = this.root;

		// Tree is empty, so we make a root and set the root's data to the passed argument
		if(current == null) {
			this.root = new Node<E>(data);
			return;
		}
	}

	// Delete a value from the tree
	public void delete(E data) {

	}

	// Finds the node containing the value, if it exists
	public Node<E> find(E data) {
		return null;
	}

	// Print out the tree in a specified traversal
	public void traverse(String order, Node<E> root) {
		if(root != null) {

		}
	}

	// Get the node containing the smallest value
	public Node<E> findMin(Node<E> root) {
		Node<E> current = root;
		while(current.getLeftChild() != null) {
			current = current.getLeftChild();
		}
		return current;
	}
}
