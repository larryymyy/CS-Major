
/*
 * Kevin A. Conte
 * 951620146
 * 
 * December 1, 2017
 * REGULAR - CLIENT
 */

import java.io.*;
import java.net.*;
import java.util.*;

public class Client {

	private static Socket client;
	private static int port;
	private static DataInputStream receiver;
	private static DataOutputStream sender;
	private static BufferedReader bfr;
	private static ArrayList<Integer> inputs;
	private static ArrayList<Integer> outputs;
	
	public static void main(String[] args) {
		
		// Setting the port that client will connect to
		port = args.length == 1 ? Integer.parseInt(args[0]) : 60010;
		
		try {
			// connecting to server and opening data streams
			client = new Socket("localhost", port);
			receiver = new DataInputStream(client.getInputStream());
			port = receiver.readInt();
			receiver.close();
			client.close();
			client = new Socket("localhost", port);
			receiver = new DataInputStream(client.getInputStream());
			sender = new DataOutputStream(client.getOutputStream());
			bfr = new BufferedReader(new InputStreamReader(System.in));
			inputs = new ArrayList<Integer>();
			outputs = new ArrayList<Integer>();
			
			// getting input from user, loop terminating with a "!" entered
			String input = "";
			while(!input.equals("!")) {
				System.out.print("Enter an integer (\"!\" to send): ");
				input = bfr.readLine();
				try { inputs.add(Integer.parseInt(input)); }
				catch(Exception e) {}
			}
			
			// sending list of integers to server to be processed
			sender.writeInt(inputs.size());
			sender.flush();
			for(Integer i : inputs) {
				sender.writeInt(i);
				sender.flush();
			}
			System.out.println("Sent: " + Arrays.toString(inputs.toArray()));
			
			// receiving data from server
			int sizeOfOutput = receiver.readInt();
			for(int i = 0; i < sizeOfOutput; i++) {
				outputs.add(receiver.readInt());
			}
			System.out.println("Received: "+ Arrays.toString(outputs.toArray()));
			
			// closing streams and connection to server
			receiver.close();
			sender.close();
			client.close();
		}
		catch (Exception e) { e.printStackTrace(); }
		System.exit(0);
	}

}
