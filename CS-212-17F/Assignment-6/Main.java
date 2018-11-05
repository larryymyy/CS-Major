/*
 * Kevin A. Conte
 * 951620146
 * 
 * Assignment 6
 * Nov. 15, 2017
 */

import java.util.Random;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) {		
		System.out.println("\r\nThe set will hence forth be printed as follows:\r\n"
				+ "[T: Integer, T: Integer, ..., T: Integer]\r\n"
				+ "That is, the key followed by the count of that key.\r\n"
				+ "===================================================\r\n\r\n");
		
		// Used to populate the lists
		Random r = new Random();
		
		OccurrenceSet<Integer> intSet = new OccurrenceSet<Integer>();
		ArrayList<Integer> intArrList = new ArrayList<Integer>();
		
		// add() functionality test
		for(int i = 0; i < 1000; i++) {
			intSet.add(r.nextInt(5) + 1);
		}
		System.out.println("add() functionality test:");
		System.out.println(intSet.toString());
		System.out.println();
		intSet.clear();
		
		// addAll() functionality test
		for(int i = 0; i < 1000; i++) {
			intSet.add(r.nextInt(5) + 1);
			intArrList.add(r.nextInt(5) + 1);
		}
		System.out.println("addAll() functionality test:");
		System.out.println(intSet.toString());
		intSet.addAll(intArrList);
		System.out.println(intSet.toString());
		System.out.println();
		intSet.clear();
		intArrList.clear();
		
		// remove() functionality test
		for(int i = 0; i < 1000; i++) {
			intSet.add(r.nextInt(5) + 1);
		}
		System.out.println("remove() functionality test:");
		System.out.println(intSet.toString());
		int intKeyToRemove = r.nextInt(5) + 1;
		System.out.println("Removing: [" + intKeyToRemove + "]");
		intSet.remove(intKeyToRemove);
		System.out.println(intSet.toString());
		System.out.println();
		intSet.clear();
		
		// removeAll() functionality test
		for(int i = 0; i < 1000; i++) {
			intSet.add(r.nextInt(5) + 1);
		}
		for(int i = 3; i <= 5; i++) intArrList.add(i);
		System.out.println("removeAll() functionality test: ");
		System.out.println(intSet.toString());
		System.out.println("Removing: " + Arrays.toString(intArrList.toArray()));
		intSet.removeAll(intArrList);
		System.out.println(intSet.toString());
		System.out.println();
		intSet.clear();
		intArrList.clear();
		
		// retainAll() functionality test
		for(int i = 0; i < 1000; i++) {
			intSet.add(r.nextInt(5) + 1);
		}
		for(int i = 3; i <= 5; i++) intArrList.add(i);
		System.out.println("retainAll() functionality test:");
		System.out.println(intSet.toString());
		System.out.println("Retaining: " + Arrays.toString(intArrList.toArray()));
		intSet.retainAll(intArrList);
		System.out.println(intSet.toString());
		System.out.println();
		intSet.clear();
		
		// contains() functionality test
		for(int i = 0; i < 1000; i++) {
			intSet.add(r.nextInt(5) + 1);
		}
		System.out.println("contains() functionality test:");
		System.out.println(intSet);
		int intKeyTest = r.nextInt(5) + 6;
		System.out.println("Contains [" + intKeyTest + "]: " + intSet.contains(intKeyTest));
		intKeyTest = r.nextInt(5) + 1;
		System.out.println("Contains [" + intKeyTest + "]: " + intSet.contains(intKeyTest));
		System.out.println();
		intSet.clear();
		
		// containsAll() functionality test
		for(int i = 0; i < 1000; i++) {
			intSet.add(r.nextInt(5) + 1);
		}
		System.out.println("containsAll() functionality test:");
		System.out.println(intSet);
		intArrList.clear();
		for(int i = 7; i <= 9; i++) intArrList.add(i);
		System.out.println("Contains: " + Arrays.toString(intArrList.toArray()) + ": " + intSet.containsAll(intArrList));
		intArrList.clear();
		for(int i = 1; i <= 3; i++) intArrList.add(i);
		System.out.println("Contains: " + Arrays.toString(intArrList.toArray()) + ": " + intSet.containsAll(intArrList));
		System.out.println();
		intSet.clear();
		intArrList.clear();
		
		// size(), isEmpty(), and clear() functionality test
		for(int i = 0; i < 1000; i++) {
			intSet.add(r.nextInt(5) + 1);
		}
		System.out.println("size(), isEmpty(), clear() functionality test:");
		System.out.println(intSet.toString());
		System.out.println("Size: " + intSet.size());
		System.out.println("Is Empty: " + intSet.isEmpty());
		intSet.clear();
		System.out.println(intSet.toString());
		System.out.println("Size: " + intSet.size());
		System.out.println("Is Empty: " + intSet.isEmpty());
		System.out.println();
		intSet.clear();
		
		// toArray() functionality test
		for(int i = 0; i < 1000; i++) {
			intSet.add(r.nextInt(5) + 1);
		}
		System.out.println("toArray() functionality test:");
		System.out.println(intSet.toString());
		Object[] intArr = intSet.toArray();
		System.out.println(Arrays.toString(intArr));
		System.out.println();
		intSet.clear();
		
		System.exit(0);
	}
}
