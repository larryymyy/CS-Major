
public class Producer implements Runnable {
	
	private String name;
	private int produced = 0;
	public static boolean isFinished = false;
	
	public Producer(String name) {
		this.name = name;
	}

	@Override
	public void run() {
		// producing 1000 events
		for(int i = 1; i <= 1000; i++) {
			try {
				
				// adding a random string to the queue and increasing the counter
				Main.queue.put(Double.toString(Math.random()));
				produced++;
				
				// Displaying progress every 100 producers
				if(i % 100 == 0) System.out.println(name + ": " + i + " events produced");
			}
			catch(InterruptedException e) { Thread.currentThread().interrupt(); }
		}
		isFinished = true;
	}
	
	public String getName() {
		return name;
	}
	
	public int getProduced() {
		return produced;
	}
}
