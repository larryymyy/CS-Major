import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws IOException {
		// Reading data in from file into memory
		System.out.println("\nLoading data from \"phonebook_test.txt\".");
		ArrayList<Entry> entries = loadData();
		System.out.println("Done.");
		System.out.println(String.format("There are %,d entries in the phone book.", entries.size()));
		
		ArrayList<Entry> mergeSorted = copyList(entries);
		ArrayList<Entry> selectionSorted = copyList(entries);
		
		// Searching data for user-specified string and writing to external file
		// NOTE: if an empty string ("") is entered, the application will return all entries
		Scanner scan = new Scanner(System.in);
		System.out.print("Please enter a string to search for: ");
		String search = scan.nextLine();
		System.out.println("\nSearching...");
		searchData(entries, search);
		scan.close();
		
		System.out.println("\nSorting data...");
		
		long time;
		
		// Sorting data via Selection Sort
		time = System.currentTimeMillis();
		selectionSorted = selectionSort(selectionSorted);
		time = System.currentTimeMillis() - time;
		System.out.println(String.format("Selection Sort: %,.3f sec", (double)time / 1000));
		
		// Sorting data via Merge Sort
		time = System.currentTimeMillis();
		mergeSorted = mergeSort(mergeSorted);
		time = System.currentTimeMillis() - time;
		System.out.println(String.format("Merge Sort: %,.3f sec", (double)time / 1000));

		// Checking if the two sorted lists are, indeed, sorted
		if(isAlphabetical(selectionSorted)) System.out.println("Selection Sorted Alphabetical: TRUE");
		else System.out.println("Selection Sorted Alphabetical: FALSE");
		
		if(isAlphabetical(mergeSorted)) System.out.println("Merge Sorted Alphabetical: TRUE");
		else System.out.println("Merge Sorted Alphabetical: FALSE");
		
		System.exit(0);
	}
	
	// Method to read data from file into memory
	private static ArrayList<Entry> loadData() throws IOException {
		ArrayList<Entry> entries = new ArrayList<Entry>();
		BufferedReader bfr = new BufferedReader(new FileReader("phonebook_test.txt"));
		String line = bfr.readLine();
		while(line != null) {
			line = line.replace(",", "");
			String[] pieces = line.split(" ");
			entries.add(new Entry(pieces[2], pieces[1], pieces[0]));
			line = bfr.readLine();
		}
		bfr.close();
		return entries;
	}
	
	// Method to search data for a specified string
	private static void searchData(ArrayList<Entry> entries, String search) throws IOException {
		PrintWriter pw = new PrintWriter("Output.txt");
		int count = 0;
		for(Entry entry : entries) {
			if(entry.getFirstName().contains(search) || entry.getLastName().contains(search)) {
				pw.println(entry.getEntry());
				count++;
			}
		}
		System.out.println(String.format("There are %,d entries that contain that string.", count));
		System.out.println("You can find these in 'Output.txt'.");
		pw.flush();
		pw.close();
		return;
	}
	
	// Method to sort data via Selection Sort Logic
	// Logic curtosy of https://en.wikipedia.org/wiki/Selection_sort/
	private static ArrayList<Entry> selectionSort(ArrayList<Entry> entries){
		ArrayList<Entry> newList = entries;
		for(int i = 0; i < newList.size() - 1; i++) {
			int min = i;
			for(int j = i + 1; j < newList.size(); j++) {
				if(newList.get(j).getLastName().compareTo(newList.get(min).getLastName()) <= 0) {
					min = j;
				}
			}
			Entry temp = newList.get(i);
			newList.set(i, newList.get(min));
			newList.set(min, temp);
		}
		return newList;
	}
	
	// Method to sort data via Merge Sort Logic
	// Logic curtosy of https://en.wikipedia.org/wiki/Merge_sort/
	private static ArrayList<Entry> mergeSort(ArrayList<Entry> input) {
		int n = input.size();
		int aSize = n / 2;
		int bSize = n - (n / 2);
		if(n <= 1) return input;
		ArrayList<Entry> a = new ArrayList<Entry>();
		ArrayList<Entry> b = new ArrayList<Entry>();
		for(int i = 0; i < aSize; i++) a.add(input.get(i));
		for(int i = 0; i < bSize; i++) b.add(input.get(i + aSize));
		return merge(mergeSort(a), mergeSort(b));
	}
	
	private static ArrayList<Entry> merge(ArrayList<Entry> a, ArrayList<Entry> b){
		ArrayList<Entry> c = new ArrayList<Entry>();
		int size = a.size() + b.size();
		int i = 0, j = 0;
		for(int k = 0; k < size; k++) {
			if (i >= a.size()) c.add(b.get(j++));
			else if (j >= b.size()) c.add(a.get(i++));
			else if (a.get(i).getLastName().compareTo(b.get(j).getLastName()) <= 0) c.add(a.get(i++));
			else c.add(b.get(j++));
		}
		return c;
	}
	
	// Method to determine if a list of Entry objects is in alphabetical order by last name
	private static boolean isAlphabetical(ArrayList<Entry> input) {
		for(int i = 0; i < input.size() - 1; i++) {
			if(input.get(i).getLastName().compareTo(input.get(i + 1).getLastName()) > 0) return false;
		}
		return true;
	}
	
	// Used to copy one list to another
	private static ArrayList<Entry> copyList(ArrayList<Entry> input){
		ArrayList<Entry> newList = new ArrayList<Entry>();
		for(Entry e : input) newList.add(e);
		return newList;
	}
}