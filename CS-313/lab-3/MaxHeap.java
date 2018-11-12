import java.util.Comparator;
import java.lang.Math;

public class MaxHeap<E extends Comparable> {
	private E[] myArray;
	private int maxSize;
	private int length;

	public MaxHeap(int s) {

	}

	public E[] getArray() { return this.myArray; }
	public void setArray(E[] newArray) {
		if(newArray.length > this.maxSize)
			return;
		this.myArray = newArray;
		this.length = newArray.length - 1;
	}
	
	public int getMaxSize() { return this.maxSize; }
	public void setMaxSize(int ms) { this.maxSize = ms; }

	public int getLength() { return this.length; }
	public void setLength(int l) { this.length = l; }

	public void insert(E data) {

	}

	public Comparable<E> maximum() {

	}

	public Comparable<E> extractMax() {

	}

	public void heapify(int i) {

	}

	public void buildHeap(E[] newArr) {

	}
}
