import java.util.Random;

public class Consumer implements Runnable {
	
	private int consumed = 0;
	private String name;
	
	public Consumer(String name) {
		this.name = name;
	}
	
	@Override
	public void run() {
		Random r = new Random();
		while(true) {
			try {
				// if the producer is not finished, wait [0,10) milliseconds
				if(!Producer.isFinished) Thread.sleep(r.nextInt(10));
				
				// if there is an element in the queue, increase the counter
				// otherwise exit the loop
				if(Main.queue.poll() != null) consumed++;
				else return;
				
				// Displaying progress every 100 consumes
				if(consumed % 100 == 0) System.out.println(name + ": " + consumed + " events consumed");
			}
			catch(InterruptedException e) { Thread.currentThread().interrupt(); }
		}
	}
	
	public int getConsumed() {
		return consumed;
	}
	
	public String getName() {
		return name;
	}
}
