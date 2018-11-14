import java.util.Arrays;
import java.util.Comparator;

public class MaxHeap<E extends Comparable<? super E>> {
	private E[] heap;
	private int size;

	@SuppressWarnings("unchecked")
	public MaxHeap(int size) {
		this.heap = (E[]) new Comparable[size];
		this.size = 0;
	}

	public int getSize() { return this.size; }

	public void insert(E data) {
		// NULL value
		if(data == null)
			return;

		// Heap is full
		if(this.size == this.heap.length)
			return;
		
		this.heap[this.size] = data;
		bubbleUp(this.size);
		this.size++;
	}

	public E maximum() {
		return this.heap[0];
	}

	public boolean isEmpty() {
		return this.size == 0;
	}

	public E extractMax() {
		if(this.size == 0)
			return null;

		E val = heap[0];
		this.heap[0] = this.heap[this.size - 1];
		heap[this.size - 1] = null;
		this.size--;
		heapify(0);

		return val;
	}
	
	public void heapify(int i) {
		int left = (2 * i) + 1;
		int right = (2 * i) + 2;
		int largest = i;
		if(left < this.size && this.heap[left].compareTo(this.heap[i]) < 0) {
			largest = left;
		}
		if(right < this.size && this.heap[right].compareTo(this.heap[largest]) < 0) {
			largest = right;
		}
		if(largest != i) {
			E swap = this.heap[i];
			this.heap[i] = this.heap[largest];
			this.heap[largest] = swap;
		}
	}

	public void bubbleUp(int child) {
		int parent = (child - 1) / 2;
		if(child == 0)
			return;
		if(this.heap[child].compareTo(this.heap[parent]) > 0) {
			E swap = this.heap[child];
			this.heap[child] = this.heap[parent];
			this.heap[parent] = swap;
			bubbleUp(parent);
		}
	}
}
