
public class Entry {
	private final String firstName;
	private final String lastName;
	private final String phoneNumber;
	
	public Entry(String firstName, String lastName, String phoneNumber) {
		this.firstName = firstName;
		this.lastName = lastName;
		this.phoneNumber = phoneNumber;
	}
	
	public String getLastName() {
		return this.lastName;
	}
	
	public String getFirstName() {
		return this.firstName;
	}
	
	public String getEntry() {
		return this.phoneNumber + " " + this.lastName + ", " + this.firstName;
	}
}
