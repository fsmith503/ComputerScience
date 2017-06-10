
public class PhoneBookEntry {
	private String firstName;
	private String lastName;
	private String phoneNumber;
	
	public PhoneBookEntry(String FN, String LN, String PN){
		this.firstName = FN;
		this.lastName = LN;
		this.phoneNumber = PN;
	}
	public String get_name(){
		return (this.firstName + " " + this.lastName);
	}
	public String get_sorting_name(){
		return (this.lastName + this.firstName);
	}
	public String get_first_name(){
		return this.firstName;
	}
	public String get_last_name(){
		return this.lastName;
	}
	
	//make comparison method
	
	public String get_number(){
		return (this.phoneNumber + "");
	}
}


