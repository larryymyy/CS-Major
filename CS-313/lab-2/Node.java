public class Node<E extends Comparable<E>> {

	// Node properties
	private E data;
	private Node<E> left;
	private Node<E> right;

	// Constructor
	public Node(E data) {
		this.data = data;
		this.left = null;
		this.right = null;
	}

	// Methods to access data in the node
	public E getData() { return this.data; }
	public Node<E> getLeft() { return this.left; }
	public Node<E> getRight() { return this.right; }
	public void setData(E data) { this.data = data; }
	public void setLeft(Node<E> node) { this.left = node; }
	public void setRight(Node<E> node) { this.right = node; }
}
