public class pQueue<E extends Comparable<E>> {
	private MaxHeap<E> heap;

	public pQueue(int size) {
		this.heap = new MaxHeap<E>(size);
	}

	public void insert(E data) {
		this.heap.insert(data);
	}

	public Comparable<E> maximum() {
		return this.heap.maximum();
	}

	public Comparable<E> extractMax() {
		return this.heap.extractMax();
	}

	public boolean isEmpty() {
		return this.heap.isEmpty();
	}
	
	public void print() {
		System.out.print("Current Queue: ");
	}
}
