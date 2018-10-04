
public class Producer implements Runnable {
	
	private static int totalCount;
	private int count;
	private String name;
	public static boolean isFinished = false;
	
	public Producer(String name) {
		this.name = name;
	}	
	
	@Override
	public void run() {
		while(true) {
			try {
				synchronized(Main.lock) {
					// exiting the loop if the cap has been reached
					if(totalCount >= 1000) break;
					
					// checking if the queue is full and waiting for it to clear before continuing
					if(Main.queue.size() == 100) Main.lock.wait();
					
					// adding a random string to the queue, increasing the object-specific counter and the static counter
					Main.queue.add(Double.toString(Math.random()));
					count++;
					totalCount++;
					
					// Displaying progress every 100 produces
					if(count % 100 == 0) System.out.println(name + ": " + count + " events produced");
					
					// notifying any sleeping threads that the queue is no longer empty
					Main.lock.notifyAll();
				}
			}
			catch(InterruptedException e) {}
		}
		isFinished = true;
		return;
	}
	
	public String getName() { return this.name; }
	public int getCount() {return this.count; }
}
