import java.util.NoSuchElementException;

public class Consumer implements Runnable {

	private int consumed;
	private String name;
	
	public Consumer(String name) {
		this.name = name;
	}
	
	@Override
	public void run() {
		while(true) {
			try {
				synchronized(Main.lock) {
					// checking if the queue is empty
					// if it is and the Producer is not finished producing, it waits for an object to be added
					// if it is and the prodcer is finished, exit the loop
					if(Main.queue.isEmpty() && !Producer.isFinished) Main.lock.wait();
					else if(Main.queue.isEmpty() && Producer.isFinished) break;
					
					// if there is an object to be removed, increase the object-specific counter and the static counter
					if(Main.queue.remove() != null) {
						consumed++;
						
						// Displaying progress every 100 consumes
						if(consumed % 100 == 0) System.out.println(name + ": " + consumed + " events consumed");
						
						// notifies any sleeping threads that the queue has had an object removed
						Main.lock.notifyAll();
					}
				}
			}
			catch(InterruptedException e) {}
			catch(NoSuchElementException e) {}
		}
		return;
	}
	
	public String getName() { return this.name; }
	public int getConsumed() { return this.consumed; }
}
