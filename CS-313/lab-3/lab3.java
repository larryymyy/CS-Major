import java.util.Scanner;

public class lab3 {
	public static void main(String[] args) {

		// Scanner to read input from stdin
		Scanner scanner = new Scanner(System.in);
	

		// Determine the size needed for the heap
		// Assuming that every line of input is an insert, this ensures that the heap has a large enough maximum size
		int size = Integer.parseInt(scanner.nextLine());
		pQueue<Integer> queue = new pQueue<Integer>(size);

		while(scanner.hasNextLine()) {
			// Split input into [command] [args]
			String[] line = scanner.nextLine().split("\\s+");

			// Switch statement for command
			switch(line[0]) {

				// Insert item into queue
				case "insert":
					queue.insert(Integer.parseInt(line[1]));
					break;

				// Print current queue
				case "print":
					queue.print();
					break;

				// Print whether the queue is empty
				case "isEmpty":
					if(queue.isEmpty())
						System.out.println("Empty");
					else
						System.out.println("Not Empty");
					break;

				// Print the item with the largest key in the queue
				case "maximum":
					System.out.println(queue.maximum());
					break;

				// Print the item with the largest key in the queue and remove it from the queue
				case "extractMax":
					System.out.println(queue.extractMax());
					break;

				// Build a new queue, via build max heap, with the provided array
				case "build":
					line[1] = line[1].replace("[", "");
					line[1] = line[1].replace("]", "");
					String[] items = line[1].split(",");
					Integer[] nums = new Integer[items.length];
					for(int i = 0; i < items.length; i++) {
						nums[i] = Integer.parseInt(items[i]);
					}
					queue.build(nums);
					break;
				default:
					break;
			}
		}

		// Close the scanner
		scanner.close();

		// Exit gracefully
		System.exit(0);
	}
}
