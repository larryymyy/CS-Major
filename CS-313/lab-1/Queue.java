
public class Queue<E> {
	Node<E> head, tail;

	public Queue() {
		this.head = this.tail = null;
	}

	public void enqueue(E data) {
		Node<E> newNode = new Node<E>(data, null);
		if(this.tail == null) {
			this.head = this.tail = newNode;
			return;
		}
		this.tail.setNext(newNode);
		this.tail = newNode;
	}

	public Node<E> dequeue() {
		if(this.head == null)
			return null;

		Node<E> headNode = this.head;
		this.head = this.head.next;
		if(this.head == null)
			this.tail = null;
		return headNode;
	}

	public boolean isEmpty() {
		return this.head == null && this.tail == null;
	}

	public void print() {
		if(this.isEmpty()) {
			System.out.println("Queue is empty!");
			return;
		}
		Node<E> current = head;
		while(current != null) {
			System.out.print(current.getData());
			current = current.getNext();
			if(current != null)
				System.out.print(" <- ");
		}
		System.out.println();
	}
}
