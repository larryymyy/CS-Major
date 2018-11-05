/*
 * Kevin A. Conte
 * 8 October 2017
 * 
 * CIS 212
 * Assignment 2
 */

import java.util.*;

public class Assignment2 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int length = 0;
		double density = 0;
		
		// Receiving user input for length and density
		while(length <= 0) {
			System.out.println("Please array length:");
			length = input.nextInt();
		}
		
		while(true) {
			System.out.println("Enter density:");
			density = input.nextDouble();
			if(density >= 0 && density <= 1.0) break;
		}
		
		// Create a dense array
		long time = System.nanoTime();
		int[] dense = makeDenseArray(length, density);
		time = System.nanoTime() - time;
		System.out.printf("create dense length: %d time: %.5f ms\n", length, (double)time / 1e6); //1e6 == 1000000
		
		// Convert to sparse array
		time = System.nanoTime();
		ArrayList<int[]> sparse = convertToSparse(dense);
		time = System.nanoTime() - time;
		System.out.printf("convert to sparse length: %d time: %.2f ms\n", sparse.size(), (double)time / 1e6);
		
		// Create a sparse array
		time = System.nanoTime();
		sparse = makeSparseArray(length, density);
		time = System.nanoTime() - time;
		System.out.printf("create sparse length: %d time: %.3f ms\n", sparse.size(), (double)time / 1e6);
		
		// Convert to dense array
		time = System.nanoTime();
		dense = convertToDense(sparse, length);
		time = System.nanoTime() - time;
		System.out.printf("convert to dense length: %d time: %.3f ms\n", dense.length, (double)time / 1e6);
		
		// Finding max of dense array
		dense = makeDenseArray(length, density);
		time = System.nanoTime();
		int[] max = findMaxDense(dense);
		time = System.nanoTime() - time;
		System.out.printf("find max (dense): %d at: %d\ndense find time: %.3f ms\n", max[1], max[0], (double)time / 1e6);
		
		// Finding max of sparse array
		sparse = makeSparseArray(length, density);
		time = System.nanoTime();
		max = findMaxSparse(sparse);
		time = System.nanoTime() - time;
		System.out.printf("find max (sparse): %d at %d\nsparse find time: %.3f ms\n", max[1], max[0], (double)time / 1e6);
	}
	
	// Creating a dense array from the user-entered length and density
	private static int[] makeDenseArray(int length, double density) {
		Random rand = new Random();
		int[] dense = new int[length];
		for(int i = 0; i < length; i++) {
			double d = rand.nextDouble();
			if(d <= density) dense[i] = rand.nextInt(1000000) + 1;
			else dense[i] = 0;
		}
		return dense;
	}
	
	// Creating a sparse array from the user-enterd length and density
	private static ArrayList<int[]> makeSparseArray(int length, double density) {
		Random rand = new Random();
		ArrayList<int[]> sparse = new ArrayList<int[]>();
		for(int i = 0; i < length; i++) {
			double d = rand.nextDouble();
			if(d <= density) sparse.add(new int[] {i, rand.nextInt(1000000) + 1});
		}
		return sparse;
	}
	
	// Creating a sparse array from a dense array
	private static ArrayList<int[]> convertToSparse(int[] dense) {
		ArrayList<int[]> sparse = new ArrayList<int[]>();
		for(int i = 0; i < dense.length; i++) {
			if(dense[i] != 0) sparse.add(new int[] {i, dense[i]});
		}
		return sparse;
	}
	
	// Creating a dense array from a sparse array and a length
	private static int[] convertToDense(ArrayList<int[]> sparse, int length) {
		int[] dense = new int[length];
		for(int a = 0; a < length; a++) dense[a] = 0;
		for(int i = 0; i < sparse.size(); i++) {
			dense[sparse.get(i)[0]] = sparse.get(i)[1];
		}
		return dense;
	}
	
	// Finding the max value and its index in a dense array
	private static int[] findMaxDense(int[] dense) {
		int[] max = new int[] {0, 0};
		for(int i = 0; i < dense.length; i++) {
			if(dense[i] > max[1]) max = new int[] {i, dense[i]};
		}
		return max;
	}
	
	// Finding the max value and its index in a sparse array
	private static int[] findMaxSparse(ArrayList<int[]> sparse) {
		int[] max = new int[] {0, 0};
		for(int i = 0; i < sparse.size(); i++) {
			if(sparse.get(i)[1] > max[1]) max = new int[] {sparse.get(i)[0], sparse.get(i)[1]};
		}
		return max;
	}
}
