@SuppressWarnings("unchecked")
public class pQueue<E extends Comparable<E>> {

	// pQueue properties
	private MaxHeap<E> heap; // heap that will contain data for queue

	// Constructor
	// Makes a new heap with the provided input size
	public pQueue(int size) {
		this.heap = new MaxHeap<E>(size);
	}

	// Insert a value, data, into the queue by inserting it into the heap
	public void insert(E data) {
		this.heap.insert(data);
	}

	// Get the maximum node of the queue by getting the maximum from the heap
	public Comparable<E> maximum() {
		return this.heap.maximum();
	}

	// Extract maximum node from queue by extracting maximum from the heap
	public Comparable<E> extractMax() {
		return this.heap.extractMax();
	}

	// Determine if the queue is empty by determining if the heap is empty
	public boolean isEmpty() {
		return this.heap.isEmpty();
	}
	
	// Print the current contents of the queue
	public void print() {
		if(this.isEmpty())
			return;
		System.out.print("Current Queue: ");
		int size = this.heap.getSize();
		for(int i = 0; i < size - 1; i++) {
			System.out.print(this.heap.getItem(i));
			System.out.print(", ");
		}
		System.out.println(this.heap.getItem(size - 1));
	}

	// Build a new queue with a provided array
	public void build(E[] array) {
		this.heap.buildHeap(array);
	}
}
