import java.util.Arrays;
import java.util.Comparator;

public class MaxHeap<E extends Comparable> {
	private E[] heap;
	private int size;

	@SuppressWarnings("unchecked")
	public MaxHeap(int size) {
		this.heap = (E[]) new Comparable[size];
		this.size = 0;
	}

	public int getSize() { return this.size; }

	public boolean isEmpty() { return this.size == 0; }

	public void insert(E data) {

	}

	@SuppressWarnings("unchecked")
	public Comparable<E> maximum() {
		return (Comparable<E>) this.heap[0];
	}

	@SuppressWarnings("unchecked")
	public E extractMax() {
		return null;
	}
	
	public void heapify(int i) {
		int left = (i * 2) + 1;
		int right = (i * 2) + 2;
		int largest = i;
		if(left < this.heap.length && this.heap[left].compareTo(this.heap[i]) > 0)
			largest = left;
		if(right < this.heap.length && this.heap[right].compareTo(this.heap[largest]) > 0)
			largest = right;
		if(largest != i) {
			E swap = this.heap[i];
			this.heap[i] = this.heap[largest];
			this.heap[largest] = swap;
			heapify(largest);
		}
	}
}
