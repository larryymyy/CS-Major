import java.lang.reflect.Array;
import java.util.Comparator;

public class MaxHeap<E extends Comparable> {
	private E[] array;
	private int maxSize;
	private int length;

	public MaxHeap(int size) {
		this.maxSize = size;
		this.length = 0;
	}
}
