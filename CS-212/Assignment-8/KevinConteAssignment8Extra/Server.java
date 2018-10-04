/*
 * Kevin A. Conte
 * 951620146
 * 
 * December 1, 2017
 * EXTRA - SERVER
 */

import java.io.*;
import java.net.*;
import java.util.*;

public class Server {

	public static void main(String[] args) {
		
		// Setting up server socket
		int port = args.length == 1 ? Integer.parseInt(args[0]) : 60010;
		ServerSocket server = null;
		try {
			server = new ServerSocket(port);
		}
		catch(IOException e) { System.exit(0); }
		
		// accepting new connection and starting new thread for that connection
		try {
			while(true) {
				Socket newConnection = server.accept();
				DataOutputStream sender = new DataOutputStream(newConnection.getOutputStream());
				ServerSocket newServer = new ServerSocket(0);
				sender.writeInt(newServer.getLocalPort());
				sender.flush();
				new Thread(new ClientThread(newServer)).start();
				sender.close();
				newConnection.close();
			}
		}
		catch(IOException e) { System.exit(0); }
	}
	
	// thread to handle client request
	static class ClientThread implements Runnable {
		
		private ServerSocket server;
		
		public ClientThread(ServerSocket server) {
			this.server = server;
		}
		
		@Override
		public void run() {
			try {
				// establishing connection on this thread
				Socket client = server.accept();
				DataOutputStream sender = new DataOutputStream(client.getOutputStream());
				DataInputStream receiver = new DataInputStream(client.getInputStream());
				ArrayList<Integer> primes = new ArrayList<Integer>();
				
				// receiving data from client and returning the primes in that data
				while(true) {
					primes.clear();
					
					int sizeOfInput = receiver.readInt();
					for(int i = 0; i < sizeOfInput; i++) {
						int number = receiver.readInt();
						if(isPrime(number)) primes.add(number);
					}
					
					sender.writeInt(primes.size());
					sender.flush();
					for(Integer prime : primes) {
						sender.writeInt(prime);
						sender.flush();
					}
					
					if(!receiver.readBoolean()) break;
				}
				
				// closing streams and connection
				sender.close();
				receiver.close();
				client.close();
				this.server.close();
			}
			catch(IOException e) { }
		}
	}
	
	// method to determing if an integer is prime
	private static boolean isPrime(int number) {
		if(number == 2) return true;
		if(number < 2 || number % 2 == 0) return false;
		for(int i = 3; i * i <= number; i += 2) {
			if(number % i == 0 ) return false;
		}
		return true;
	}

}
