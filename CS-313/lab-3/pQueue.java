public class pQueue<E extends Comparable> {
    private MaxHeap myHeap;

    public pQueue (int s) {
        // Build the Constructor
    }

    public void insert(E data){
        myHeap.insert(data);
    }

    public Comparable<E> maximum(){
        return myHeap.maximum();
    }

    public Comparable<E> extractMax(){
        return myHeap.extractMax();
    }

    public boolean isEmpty(){
        // Return true when the priority queue is empty
        // Hint: Do the actual printing in your lab3.java
    }

	public void build(E[] arr){
    	// used for the extra credit
    }
    
    public void print(){
        // print out ”Current Queue: ” 
        // followed by each element separated by a comma. 
        // Do not add spaces between your elements.
    }
}
