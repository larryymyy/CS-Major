import java.util.Scanner;

public class lab3 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		pQueue<Integer> queue = new pQueue<Integer>(10);
		queue.insert(5);
		queue.insert(15);
		queue.insert(10);
		queue.insert(20);

		queue.print();

		Integer data = (Integer)queue.extractMax();
		System.out.println(data);

		scanner.close();
		System.exit(0);
	}
}
