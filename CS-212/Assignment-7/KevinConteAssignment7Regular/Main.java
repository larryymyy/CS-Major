/*
 * Kevin A. Conte
 * 951620146
 * 
 * Assignment 7 - Regular
 * Nov. 22, 2017
 */

import java.util.ArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.LinkedBlockingQueue;

public class Main {

	// Defining the queue with size 100 for use in the application
	public static LinkedBlockingQueue<String> queue = new LinkedBlockingQueue<String>(100);
	
	// main(), entry point to program
	public static void main(String[] args) throws InterruptedException {
		Producer producer = new Producer("\"Producer #1\"");
		
		ArrayList<Consumer> consumers = new ArrayList<Consumer>();
		for(int i = 1; i <= 4; i++) {
			consumers.add(new Consumer("\"Consumer #" + i + "\""));
		}
		
		new Thread(producer).start();
		Thread.sleep(10);
		for(Consumer c : consumers) new Thread(c).start();
		while(Thread.activeCount() != 1) { }

		System.out.println("\r\nSummary:");
		System.out.println(producer.getName() + " produces " + producer.getProduced() + " events.");
		for(Consumer c : consumers) System.out.println(c.getName() + " consumes " + c.getConsumed() + " events.");
	}
	
}
