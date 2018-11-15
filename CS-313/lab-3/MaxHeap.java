@SuppressWarnings("unchecked")
public class MaxHeap<E extends Comparable<E>> {

	// Max Heap properties:
	private E[] heap; // Holds the actual data for the heap
	private int maxSize; // Maximum heap size
	private int heapSize; // Current heap size

	// Constructor
	// Creates a new heap with the given size
	// Sets the maximum size to the given size
	// Sets the current heap size to 0, as the heap is initially empty
	public MaxHeap(int size) {
		this.heapSize = 0;
		// Determine the next highest power of two, to ensure that the heap is large enough, and able to be complete
		size = (int) Math.pow(2, Math.ceil(Math.log10(size) / Math.log10(2)));

		this.maxSize = size;
		this.heap = (E[]) new Comparable[size];
	}

	// Returns the maximum heap size
	public int getMaxSize() {
		return this.maxSize;
	}
	
	// Returns the item at index i, used in printing the heap out
	public Comparable<E> getItem(int i) {
		return (Comparable<E>) this.heap[i];
	}

	// Returns the current heap size
	public int getSize() {
		return this.heapSize;
	}

	// Determine if the heap is currently empty by seeign if the current heap size is 0
	public boolean isEmpty() {
		return this.heapSize == 0;
	}


	// Determine the parent node index of a given index
	public int parent(int i) {
		if(i == 0)
			return i;
		return (i - 1) / 2;
	}


	// Insert a value, data, in to the heap, maintaining its shape
	public void insert(E data) {
		if(this.heapSize == maxSize)
			return;
		this.heap[this.heapSize] = data;
		bubbleUp(this.heapSize);
		this.heapSize++;
	}


	// Return the first element of the heap, it must be the maximum since we ensure heap properties in the insert method
	public Comparable<E> maximum() {
		return (Comparable<E>) this.heap[0];
	}


	// Return the first element of the heap and remove it from the heap
	public Comparable<E> extractMax() {
		Comparable<E> max = (Comparable <E>) this.heap[0];
		this.heap[0] = this.heap[--this.heapSize];
		heapify(0);
		return max;
	}
	

	// Ensure heap properties, from index i to onwards
	public void heapify(int i) {
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		int largest = i;
		if(left < this.heapSize && this.heap[left].compareTo(this.heap[i]) > 0)
			largest = left;
		if(right < this.heapSize && this.heap[right].compareTo(this.heap[largest]) > 0)
			largest = right;
		if(largest != i) {
			E data = this.heap[i];
			this.heap[i] = this.heap[largest];
			this.heap[largest] = data;
			heapify(largest);
		}
	}


	// Ensure heap properties when inserting a value, taking in the index of the inserted value
	private void bubbleUp(int i) {
		if(i == 0)
			return;
		if(this.heap[i].compareTo(this.heap[parent(i)]) > 0) {
			E data = this.heap[i];
			this.heap[i] = this.heap[parent(i)];
			this.heap[parent(i)] = data;
			bubbleUp(parent(i));
		}
	}


	// Build a max heap with a given array
	public void buildHeap(E[] array) {
		this.heap = array;
		this.maxSize = array.length;
		this.heapSize = array.length;
		for(int i = (this.maxSize / 2); i >= 0; i--) {
			heapify(i);
		}
	}
}
