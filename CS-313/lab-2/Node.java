public class Node<E extends Comparable<E>> {
	// Properties of the Node
    private E data;
    private Node<E> leftChild = null, rightChild = null, parent = null;

	// Constructor
    public Node(E d) { data = d; }

	// Methods to access data in the Node
    public void setData(E d) { data = d; }
    public void setLeftChild(Node<E> lc) { leftChild = lc; }
    public void setRightChild(Node<E> rc) { rightChild = rc; }
	public void setParent(Node<E> p) { parent = p; }
    public E getData() { return data; }
    public Node<E> getLeftChild() { return leftChild; }
    public Node<E> getRightChild() { return rightChild; }
    public Node<E> getParent() { return parent; }

}
