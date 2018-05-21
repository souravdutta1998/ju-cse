import java.util.*;
import java.io.*;
import java.text.SimpleDateFormat;
public class assignment6{
	
	public static void main(String args[]){
		boolean exit = false;
		String name1, docname1, checkintime1;
		int age1, id1;
		String doctors[] = {"Dr. Sachin Verma", "Dr. Madhu Goswami", "Dr. Rishav Pandey", "Dr. Ankit Singh", "Dr. Rakesh Chakraborty"};
		int doclen = doctors.length;
		int i=0;
		PATIENT patientlist[] = new PATIENT[10];
		PATIENT p = new PATIENT();
		Scanner in = new Scanner (System.in);
		do{
			//System.out.println("");
			System.out.println("----------------------------------");
			System.out.println("1. Admit Patient");
			System.out.println("2. Discharge Patient");
			System.out.println("3. Examine the patient");
			System.out.println("4. View recorded observations");
			System.out.println("5. Exit!");
			System.out.print("\nEnter the choice number: ");
			int ch = in.nextInt();
			in.nextLine();
			switch(ch){
				case 1: //for admission
					System.out.println("ENTER PATIENT'S DETAILS");
					System.out.print("Enter Name: ");
					name1 = in.nextLine();
					System.out.print("Enter Age: ");
					age1 = in.nextInt();
					if(age1 <0 || age1>100) 
					{
						System.out.println("Invalid age!");
						break;
					}
					id1 = i+1;
					docname1 = doctors[i%doclen];
					checkintime1 = new Date().toString();
					
					patientlist[i] = new PATIENT( age1, name1, docname1, checkintime1);
					patientlist[i].setId(id1);
					System.out.println("\nSUCCESSFULLY ADMITTED!");
					System.out.println("PATIENT ID for the patient is: "+id1);
					System.out.println("Admission time: "+ checkintime1);
					i++;
					p.setCount(i);  //updating the count of patients
					break;
				case 2:  //discharge
					System.out.print("Enter patient ID: ");
					id1 = in.nextInt();
					boolean found =false;
					int count = p.getCount();
					int k;
					for(k=0;k<count;k++){
						if(id1 == patientlist[k].getId()){
							found = true;
							break;
						}
					}
					if(found == false){
						System.out.println("Patient id not found");
						break;
					}
					if(patientlist[k].getExamined() == false){
						System.out.println("The patient has not been examined. Please get examined by the appointed doctor first before getting discharged.");
						break;
					}
					if(patientlist[k].getDischarged() == false){
						patientlist[k].setDischarged();
						System.out.println("Name: "+ patientlist[k].getName());
						System.out.println("Doctor's Name: "+patientlist[k].getDocname());
						System.out.println("Admission Date and Time: "+ patientlist[k].getCheckindate());
						System.out.println("\n The patient has been successully discharged");
						String s =  new Date().toString();
						patientlist[k].setCheckout(s);
						System.out.println("Discharge Date and Time: "+s);
						
					}
					else {
						System.out.println("This patient has already been discharged on "+ patientlist[k].getCheckout());
					}
					break;
				case 3:  //examine patient 
					int num[] = new int[4];
					System.out.print("Enter patient ID: ");
					id1 = in.nextInt();
					found =false;
					count = p.getCount();
					
					for(k=0;k<count;k++){
						if(id1 == patientlist[k].getId()){
							found = true;
							break;
						}
					}
					if(found == false){
						System.out.println("Patient id not found");
						break;
					}
					if(patientlist[k].getDischarged() == false){
						String c = new String();
						if(patientlist[k].getExamined() == true){
							in.nextLine();
							System.out.print("This patient has already been examined. Do you want to examine again? (y/n) ");
							c = in.nextLine();
						}
						if(c.equals("n")) break;
						System.out.println("Hey! This is "+ patientlist[k].getDocname()+". I am now examining the patient\n");
						System.out.print("Enter height: ");
						num[0] = in.nextInt();
						System.out.print("Enter weight: ");
						num[1] = in.nextInt();
						System.out.print("Enter blood pressure: ");
						num[2] = in.nextInt();
						System.out.print("Enter Body temperature: ");
						num[3] = in.nextInt();
						
						patientlist[k].setData(num);
						patientlist[k].setExamined();
					}
					else {
						System.out.println("This patient has already been discharged on "+ patientlist[k].getCheckout());
					}
					break;
				case 4:  //view all details of the patient 
					System.out.print("Enter patient ID: ");
					id1 = in.nextInt();
					found =false;
					count = p.getCount();
					
					for(k=0;k<count;k++){
						if(id1 == patientlist[k].getId()){
							found = true;
							break;
						}
					}
					if(found == false){
						System.out.println("Patient id not found");
						break;
					}
					System.out.println("--------------PATIENT's DETAILS--------------");
					System.out.println("Name of the Patient: "+patientlist[k].getName());
					System.out.println("Patient ID: "+id1);
					System.out.println("Age: "+patientlist[k].getAge());
					System.out.println("Doctor's Name: "+patientlist[k].getDocname());
					System.out.println("Admission Date: "+patientlist[k].getCheckindate());
					if(patientlist[k].getDischarged() == false) 
						System.out.println("Discharge Date: not yet discharged");
					else 
						System.out.println("Discharge Date: "+ patientlist[k].getCheckout());
					if(patientlist[k].getExamined() == false)
						System.out.println("The patient has not been examined by the doctor yet.");
					else {
						System.out.println("Updated Height: " + patientlist[k].getData()[0]);
						System.out.println("Updated Weight: "+ patientlist[k].getData()[1]);
						System.out.println("Updated Blood pressure: "+ patientlist[k].getData()[2]);
						System.out.println("Updated Body temperature: "+ patientlist[k].getData()[3]);
					}
					
					break;
				case 5:  //exit
					System.out.println("Logged out!");
					exit = true;
					break;
				default:
					System.out.println("Invalid choice!");
					break;
				
			}
		}while(exit != true);
	}
}
class PATIENT{
	private String name;
	private String docname;
	private int id;
	private int age;
	private String checkintime;
	private String checkouttime;
	private boolean examined;
	private boolean discharged;
	private int count;
	private int data[] = new int[4];
	public PATIENT(){  //constructor to set the count to 0
		count =0;
	}
	public PATIENT( int a, String n, String doc, String chk){  //overloaded version of constructor for setting values to data members
		name = n;
		docname = doc;
		age = a;
		checkintime = chk;
		examined = false;
		discharged = false;
		for(int i=0;i<4;i++)
			data[i] = 0;
	}
	void setId(int i){  //setter function for id
		count++;
		id = i;
	}
	void setExamined(){  //setter function to set the examined as true
		examined = true;
	}
	void setData(int d[]){  //setter function to set the data
		data = d;
	}
	void setDischarged(){  //setter function to set the discharged as true
		discharged = true;
	}
	void setCheckout(String s){  //setter function to set the check out date and time
		checkouttime = s;
	}
	void setCount(int i){  //setter function to set the count of patients
		count =i;
	}
	public int[] getData(){ //getter function to return data
		return data;
	}
	public String getName(){  //getter function to return name
		return name;
	}
	public String getDocname(){  //getter function to return doctors name
		return docname;
	}
	public int getId(){  //getter function to return id
		return id;
	}
	public int getAge(){ //getter function to return age
		return age;
	}
	public String getCheckindate(){  //getter function to return checkin date and time
		return checkintime;
	}
	public boolean getExamined(){  //getter function to return examined status
		return examined;
	}
	public boolean getDischarged(){  //getter function to return discharged status
		return discharged;
	}
	public String getCheckout(){  //getter function to return discharge date and time
		return checkouttime;
	}
	public int getCount(){  //getter function to return count of patients
		return count;
	}
	
}