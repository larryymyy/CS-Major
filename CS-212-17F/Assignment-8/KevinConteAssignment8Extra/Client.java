/*
 * Kevin A. Conte
 * 951620146
 * 
 * December 1, 2017
 * EXTRA - CLIENT
 */

import java.io.*;
import java.net.*;
import java.util.*;

public class Client {

	private static boolean isRunning = false;
	private static boolean isAlive = true;
	
	private static Socket client;
	private static int port;
	private static DataInputStream receiver;
	private static DataOutputStream sender;
	private static ArrayList<Integer> inputs = new ArrayList<Integer>();
	private static ArrayList<Integer> outputs = new ArrayList<Integer>();
	
	public static void main(String[] args) throws IOException, InterruptedException {
		
		// opening connection to server and starting data streams
		port = args.length == 1 ? Integer.parseInt(args[0]) : 60010;
		client = new Socket("localhost", port);
		receiver = new DataInputStream(client.getInputStream());
		port = receiver.readInt();
		receiver.close();
		client.close();
		client = new Socket("localhost", port);
		receiver = new DataInputStream(client.getInputStream());
		sender = new DataOutputStream(client.getOutputStream());
		new Thread(new UserInput()).start();
		
		// sending to / receiving from server while alive 
		while(isAlive) {
			while(isRunning) {
				inputs.clear();
				outputs.clear();
				
				// Generating 5 random integers from 2 to 100
				Random r = new Random();
				for(int i = 0; i < 5; i++) inputs.add(r.nextInt(98) + 2);
				sender.writeInt(inputs.size());
				sender.flush();
				for(Integer i : inputs) {
					sender.writeInt(i);
					sender.flush();
				}
				System.out.println("Sent: " + Arrays.toString(inputs.toArray()));
				
				// receiving output data from server
				int sizeOfOutputs = receiver.readInt();
				for(int i = 0; i < sizeOfOutputs; i++) outputs.add(receiver.readInt());
				System.out.println("Received: " + Arrays.toString(outputs.toArray()) + "\r\n");
				
				Thread.sleep(1000);
				sender.writeBoolean(isAlive);
			}
		}
		
		// closing connection and data streams
		receiver.close();
		sender.close();
		client.close();
		System.exit(0);
	}

	// thread to receive user input
	static class UserInput implements Runnable {
		
		@Override
		public void run() {
			Scanner scn = new Scanner(System.in);
			String input = "";
			while(isAlive) {
				if(!isRunning) {
					System.out.print("Enter \"!\" to start/stop (\"#\" to exit): ");
				}
				input = scn.nextLine();
				if(input.equals("!")) {
					if(isRunning) isRunning = false;
					else isRunning = true;
				}
				else if(input.equals("#")) isAlive = false;
			}
		}
	}
}
