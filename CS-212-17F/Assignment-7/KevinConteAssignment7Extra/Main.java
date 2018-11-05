/*
 * Kevin A. Conte
 * 951620146
 * 
 * Assignment 7 - EXTRA CREDIT
 * Nov. 22, 2017
 */


import java.util.ArrayList;
import java.util.LinkedList;
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;

public class Main {

	// Linked List to act as queue and an empty Object 'lock' used for synchronization
	public static LinkedList<String> queue = new LinkedList<String>();
	public static Object lock = new Object();
	
	// main() entry point to the program
	public static void main(String[] args) throws Exception {
		// Creating a list of Producer objects
		ArrayList<Producer> producers = new ArrayList<Producer>();
		for(int i = 1; i <= 4; i++) producers.add(new Producer("Producer #" + i));
		
		// Creating a list of Consumer objects
		ArrayList<Consumer> consumers = new ArrayList<Consumer>();
		for(int i = 1; i <= 6; i++) consumers.add(new Consumer("Consumer #" + i));
		
		// Executing each thread
		ExecutorService executor = Executors.newCachedThreadPool();
		for(Producer p : producers) executor.execute(p);
		Thread.sleep(10);
		for(Consumer c : consumers)	executor.execute(c);
		executor.shutdown();
		while(!executor.isTerminated()) {}
		
		// Printing a summary of the threads
		System.out.println("\nSummary:");
		int prodSum = 0;
		int consSum = 0;
		for(Producer p : producers) {
			System.out.println(p.getName() + " produces " + p.getCount() + " events.");
			prodSum += p.getCount();
		}
		for(Consumer c : consumers) {
			System.out.println(c.getName() + " consumes " + c.getConsumed() + " events.");
			consSum += c.getConsumed();
		}
		System.out.println("Produced Events: " + prodSum);
		System.out.println("Consumed Events: " + consSum);
	}
}
