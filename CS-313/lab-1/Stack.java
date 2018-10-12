public class Stack<E> {
	Node<E> top;

	public Stack() {
		top = null;
	}

	public void push(E data) {
		Node<E> stack = top;
		top = new Node<E>(data, stack);
		return;
	}

	public Node<E> pop() {
		Node<E> topNode = top;
		top = top.getNext();
		return topNode;
	}

	public boolean isEmpty() {
		return top == null;
	}

	public void print() {
		if(this.isEmpty()) {
			System.out.println("Stack is empty!");
			return;
		}
		Node<E> current = top;
		while(current != null) {
			System.out.print(current.getData());
			current = current.getNext();
			if(current != null)
				System.out.print(" - ");
		}
		System.out.println();
	}
}
