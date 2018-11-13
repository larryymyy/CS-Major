import java.util.Arrays;
import java.util.Comparator;

@SuppressWarnings("unchecked")

public class MaxHeap<E extends Comparable> {
	private E[] heap;
	private int length = 0;
	private int maxSize;

	public MaxHeap(int size) {
		this.maxSize = size;
		this.heap = (E[]) new Comparable[size];
	}

	public E[] getArray() { return this.heap; }
	public void setArray(E[] newArray) {
		if(newArray.length > maxSize) { return; }
		this.heap = newArray;
		this.length = this.heap.length - 1;
	}

	public int getMaxSize() { return this.maxSize; }
	public void setMaxSize(int size) { this.maxSize = size; }

	public int getLength() { return this.length; }
	public void setLength(int length) { this.length = length; }

	public void insert(E data) {
		if(this.length == this.maxSize) {
			return;
		}
		this.length++;
		this.heap[this.length] = data;
	}
}
