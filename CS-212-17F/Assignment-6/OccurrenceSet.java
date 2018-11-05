
import java.util.*;
import java.util.Map.*;

public class OccurrenceSet<T> implements Set<T> {
	
	private Map<T, Integer> map;
	
	// Constructor
	public OccurrenceSet() {
		super();
		map = new HashMap<T, Integer>();
	}
	
	// Method to add an element to the set
	@Override
	public boolean add(T t) {
		int value = 0;
		boolean hasBeenModified = false;
		if(map.get(t) != null) value = map.get(t);
		else hasBeenModified = true;
		map.put(t, value + 1);
		return hasBeenModified;
	}
	
	// Method to add all elements of a collection to the set
	@Override
	public boolean addAll(Collection<? extends T> c) {
		boolean hasBeenModified = false;
		Iterator<? extends T> i = c.iterator();
		while(i.hasNext()) {
			if(add(i.next())) 
				hasBeenModified = true;
		}
		return hasBeenModified;
	}
	
	// Method to remove an element from the set
	@Override
	public boolean remove(Object o) {
		boolean hasBeenModified = false;
		if(map.containsKey(o)) 
			hasBeenModified = true;
		map.remove(o);
		return hasBeenModified;
	}
	
	// Method to remove all elements of a given collection from the set
	@Override
	public boolean removeAll(Collection<?> c) {
		boolean hasBeenModified = false;
		Iterator<?> i = c.iterator();
		while(i.hasNext()) {
			if(remove(i.next()))
				hasBeenModified = true;
		}
		return hasBeenModified;
	}
	
	// Method to remove all elements not in the collection from the set
	@Override
	public boolean retainAll(Collection<?> c) {
		boolean hasBeenModified = false;
		Iterator<?> i = iterator();
		while(i.hasNext()) {
			if(!c.contains(i.next()))
				i.remove();
		}
		return hasBeenModified;
	}
	
	// Method to determine if the set contains an element
	@Override
	public boolean contains(Object o) {
		return map.containsKey(o);
	}
	
	// Method to determine if the set contains all elements in a collection
	@Override
	public boolean containsAll(Collection<?> c) {
		Iterator<?> i = c.iterator();
		while(i.hasNext()) {
			if(!contains(i.next()))
				return false;
		}
		return true;
	}
	
	// Method to determine the size of the set (# of unique keys)
	@Override
	public int size() {
		return map.size();
	}
	
	// Method to clear the set
	@Override
	public void clear() {
		map.clear();
	}
	
	// Method to determine if the set is empty
	@Override
	public boolean isEmpty() {
		return map.isEmpty();
	}
	
	// Method to create an iterator object based on the set
	@Override
	public Iterator<T> iterator() {
		return map.keySet().iterator();
	}
	
	// Methods to convert set to array
	@Override
	public Object[] toArray() {
		Object[] r = new Object[size()];
		Iterator<?> it = iterator();
		for(int i = 0; i < size(); i++) {
			r[i] = it.next();
		}
		return r;
	}
	
	@Override
	public <T> T[] toArray(T[] a) {
		return null;
	}
	
	// Method to sorts and converts the set to a string
	@Override
	public String toString() {
		String result = "[";
		Set<Entry<T, Integer>> set = map.entrySet();
		List<Entry<T, Integer>> list = new ArrayList<Entry<T, Integer>>(set);
		Collections.sort(list, new Comparator<Map.Entry<T, Integer>>() {
			public int compare(Map.Entry<T, Integer> o1, Map.Entry<T, Integer> o2) {
				return o1.getValue().compareTo(o2.getValue());
			}
		});
		
		for(Entry<T, Integer> e : list) {
			result += e.getKey() + ": " + e.getValue() + ", ";
		}
		if(result.length() > 3) result = result.substring(0, result.length() - 2) + "]";
		else result += "]";
		return result;
	}
}
