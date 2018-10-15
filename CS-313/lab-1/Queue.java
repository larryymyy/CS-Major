
public class Queue<E> {
	private Node<E> head;
	private Node<E> tail;
	
	public Queue(){
		// We want to initialize our Queue to be empty
		// (ie) set head and tail to be null
		this.head = this.tail = null;
	}
	
	public void enqueue(E newData){
		// Create a new node whose data is newData and whose next node is null
		// Update head and tail
		// Hint: Think about what's different for the first node added to the Queue
		Node<E> newNode = new Node<E>(newData, null);
		if(this.tail == null) {
			this.head = this.tail = newNode;
			return;
		}
		this.tail.setNext(newNode);
		this.tail = newNode;
	}
	
	public Node<E> dequeue(){
		// Return the head of the Queue
		// Update head
		// Hint: The order you implement the above 2 tasks matters, so use a temporary node
	 	//	     to hold important information
		// Hint: Return null on a empty Queue
		if(this.head == null)
			return null;
		Node<E> headNode = this.head;
		this.head = this.head.getNext();
		if(this.head == null)
			this.tail = null;
		return headNode;
	}
	
	public boolean isEmpty(){
		// Check if the Queue is empty
		return this.head == null && this.tail == null;
	}
	
	public void printQueue(){
		// Loop through your queue and print each Node's data
		if(this.isEmpty()) {
			System.out.println("Queue is empty!");
			return;
		}
		Node<E> current = this.head;
		while(current != null) {
			System.out.println(current.getData());
			current = current.getNext();
		}
	}
}
