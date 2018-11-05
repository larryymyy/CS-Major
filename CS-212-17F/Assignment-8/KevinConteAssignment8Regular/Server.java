
/*
 * Kevin A. Conte
 * 951620146
 * 
 * December 1, 2017
 * REGULAR - SERVER
 */

import java.io.*;
import java.net.*;
import java.util.*;

public class Server {

	public static void main(String[] args) throws IOException {
		
		// Setting up the server, with the option of setting your own port
		int port = args.length == 1 ? Integer.parseInt(args[0]) : 60010;
		ServerSocket server = new ServerSocket(port);
		
		// Infinite loop that supports multiple client connections
		while(true) {
			// Accept a new client connection and start a new thread to serve that client
			Socket newConnection = server.accept();
			System.out.println("Client connected...");
			DataOutputStream sender = new DataOutputStream(newConnection.getOutputStream());
			ServerSocket newServer = new ServerSocket(0);
			sender.writeInt(newServer.getLocalPort());
			sender.flush();
			new Thread(new ClientThread(newServer)).start();
			sender.close();
			newConnection.close();
		}
	}
	
	// Thread code to handle client request
	static class ClientThread implements Runnable {
		
		private ServerSocket server;
		
		public ClientThread(ServerSocket server) {
			this.server = server;
		}
		
		@Override
		public void run() {
			try {
				// Setting up client connection on this thread and data streams
				Socket client = server.accept();
				DataOutputStream sender = new DataOutputStream(client.getOutputStream());
				DataInputStream receiver = new DataInputStream(client.getInputStream());
				ArrayList<Integer> primes = new ArrayList<Integer>();
				
				// reading data from client and determining which numbers are prime
				int sizeOfInput = receiver.readInt();
				for(int i = 0; i < sizeOfInput; i++) {
					int num = receiver.readInt();
					if(isPrime(num)) primes.add(num);
				}
				
				// sending primes back to client
				sender.writeInt(primes.size());
				sender.flush();
				for(Integer prime : primes) {
					sender.writeInt(prime);
					sender.flush();
				}
				
				// closing streams and client connection
				sender.close();
				receiver.close();
				client.close();
			} catch (IOException e) { e.printStackTrace(); }
			
		}
	}
	
	// Method to determine if an integer is prime
	private static boolean isPrime(int number) {
		if(number == 2) return true;
		if(number < 2 || number % 2 == 0) return false;
		for(int i = 3; i * i <= number; i += 2) {
			if(number % i == 0) return false;
		}
		return true;
	}
}
