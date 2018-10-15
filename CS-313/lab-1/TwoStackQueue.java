
public class TwoStackQueue<E> {
	private Stack<E> inbox, outbox;

	public TwoStackQueue() {
		this.inbox = new Stack<E>();
		this.outbox = new Stack<E>();
	}

	public void enqueue(E newData) {
		this.inbox.push(newData);
	}

	public Node<E> dequeue() {
		if(this.inbox.isEmpty() && this.outbox.isEmpty()) {
			return null;
		}
		while(this.outbox.isEmpty()) {
			while(!this.inbox.isEmpty()) {
				this.outbox.push(this.inbox.pop().getData());
			}
		}
		return this.outbox.pop();
	}

	public boolean isEmpty() {
		return this.inbox.isEmpty() && this.outbox.isEmpty();
	}

	public void printQueue() {
		if(this.inbox.isEmpty() && this.outbox.isEmpty()) {
			System.out.println("Queue is empty!");
		}

		while(this.outbox.isEmpty()) {
			while(!this.inbox.isEmpty()) {
				this.outbox.push(this.inbox.pop().getData());
			}
		}

		while(!this.outbox.isEmpty()) {
			E data = this.outbox.pop().getData();
			System.out.print(data + " ");
			this.inbox.push(data);
		}
		System.out.println();
	}

}
