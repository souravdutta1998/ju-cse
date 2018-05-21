import java.util.Scanner;
import java.util.Date;
import java.util.*;
import java.io.*;
import java.text.SimpleDateFormat;

public class assignment1 extends STUDENT{
	static ArrayList <STUDENT> al = new ArrayList<>();
	public static void main(String args[]){
		STUDENT studentlist[] = new STUDENT[10];
		STUDENT s = new STUDENT();
		Runtime runtime = Runtime.getRuntime();
		String name1 , dept1 , date1 , roll1;
		boolean exit, flag;
		int choice, i=0, count=0, total =0 ;
		int marks1[] = new int[5];
		double cgpa;
		Scanner scan = new Scanner(System.in);
		
		String subjects[] = {"Comp. Arch.","Mathematics","Digital Logic","Graph Theory","English"};
		do{
			exit = false;
			System.out.println("--------------------------------------------------");
			System.out.println("1. Enter details of student");
			//System.out.println("2. Input marks of student");
			System.out.println("2. Display marksheet");
			System.out.println("3. Display total number of students");
			System.out.println("4. Display details of all students");
			System.out.println("5. Display list in sorted order");
			System.out.println("6. Delete a student entry");
			System.out.println("7. Exit!");
			System.out.println();
			System.out.print("Enter a choice number: ");
			choice = scan.nextInt();
			switch(choice){
			case 1:
				scan.nextLine();
				studentlist[i] = new STUDENT();
				System.out.print("Enter name: ");
				name1 = scan.nextLine();
				studentlist[i].setName(name1);
				System.out.print("Enter Course (BCSE / ETCE / MECH / ELEC): ");
				dept1 = scan.nextLine();
				if(dept1.equals("BCSE") || dept1.equals("ETCE") || dept1.equals("MECH") || dept1.equals("ELEC") ){
					studentlist[i].setDept(dept1);
					
					SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
					Date date = new Date();
					date1 = formatter.format(date);
					studentlist[i].setDate(date1);
					boolean valid  = true;
					total  = 0;
					for(int j=0;j<5;j++)
					{
						System.out.print("Enter marks of "+ subjects[j] +": ");
						marks1[j] = scan.nextInt();
						if(marks1[j] < 0 || marks1[j] >100) {System.out.println("Invalid marks!"); valid = false; break; }
						total += marks1[j];
					}
					cgpa = (double)total/50;
					if(valid == true) studentlist[i].setMarks(marks1);
					else break;
					studentlist[i].setGpa(cgpa);
					roll1 = s.getRoll(dept1);
					studentlist[i].setRoll(roll1);
					System.out.println("\nDetails of the student added successfully!");
					System.out.println();
					System.out.println("Admission Date: " + date1);
					System.out.println("Roll number alloted to student is: " + roll1);
					total = 0;
					al.add(studentlist[i]);
					i++;
				}
				else System.out.println("You have entered invalid course!");
				
				break;
		/*	case 2:
				scan.nextLine();
				System.out.print("Enter the alloted roll number of student: ");
				roll1 = scan.nextLine();
				count = s.totalStudents();
				
				flag = false;
				boolean valid = true;
				for(int k=0;k<count;k++) {
					if(roll1.equals(studentlist[k].returnRoll())){
						for(int j=0;j<5;j++)
						{
							System.out.print("Enter marks of "+ subjects[j] +": ");
							marks1[j] = scan.nextInt();
							if(marks1[j] < 0 || marks1[j] >100) {System.out.println("Invalid marks!"); valid = false; break; }
						}
						if(valid == true) studentlist[k].setMarks(marks1);
						flag = true;
						break;
					}
				}
				if(flag == false) System.out.println("Roll number not found!");
				break;*/
			case 2:
				scan.nextLine();
				System.out.print("Enter the alloted roll number of student: ");
				roll1 = scan.nextLine();
				count = al.size();
				
				flag = false;
				for(int k=0;k<count;k++) {
					if(roll1.equals(al.get(k).returnRoll()) ) {
						System.out.println("----------------------------------------------------");
						System.out.println("\t\t\tMARKSHEET");
						System.out.println("----------------------------------------------------");
						System.out.println("Name: " + al.get(k).getName());
						System.out.println("Roll No: " + al.get(k).returnRoll());
						System.out.println("Department: " + al.get(k).getDept());
						System.out.println("Admission Date: " + al.get(k).getDate());
						System.out.println("----------------------------------------------------");
						for(int h = 0;h<5;h++) {
							System.out.println(subjects[h] + " : " + al.get(k).getMarks()[h]);
						}
						System.out.println("----------------------------------------------------");
						System.out.print("CGPA: "  );
						if(al.get(k).getGpa() == 0) {
							System.out.println("Marks not entered");
						}
						else {
							System.out.println(al.get(k).getGpa());
						}
						System.out.println("----------------------------------------------------");
						flag = true;
						break;
					}
					
				}
				if(flag == false) System.out.println("Roll number not found!");
				break;
			case 3: 
				//s.totalStudentsInDept();
				count = al.size();
				System.out.println("\nTotal numbers of students admitted: "+ count);
				break;
			case 4: 
				for(int x = 0;x<al.size(); x++) {
					System.out.println("------------------------------------");
					System.out.println("Name: " + al.get(x).getName());
					System.out.println("Roll No: " + al.get(x).returnRoll());
					System.out.println("Department: " + al.get(x).getDept());
					System.out.println("Admission Date: " + al.get(x).getDate());
					System.out.print("CGPA: "  );
					if(al.get(x).getGpa() == 0) {
						System.out.println("Marks not entered");
					}
					else {
						System.out.println(al.get(x).getGpa());
					}
				}
				break;
			case 5:
				scan.nextLine();
				System.out.println("Displaying list in sorted order");
				String d;
				System.out.print("Enter Department (BCSE/ETCE/MECH/ELEC) (To view all students, enter ANY): ");
				d = scan.nextLine();
				Collections.sort(al, new SortComp());
				if(d.equals("ANY")) {
					for(int x = 0;x<al.size(); x++) {
						System.out.println("------------------------------------");
						System.out.println("Name: " + al.get(x).getName());
						System.out.println("Roll No: " + al.get(x).returnRoll());
						System.out.println("Department: " + al.get(x).getDept());
						System.out.println("Admission Date: " + al.get(x).getDate());
						System.out.print("CGPA: "  );
						if(al.get(x).getGpa() == 0) {
							System.out.println("Marks not entered");
						}
						else {
							System.out.println(al.get(x).getGpa());
						}
					}
					break;
				}
					for(int x =0; x< al.size();x++) {
						if(( al.get(x).getDept()).equals(d)) {
							System.out.println("------------------------------------");
							System.out.println("Name: " + al.get(x).getName());
							System.out.println("Roll No: " + al.get(x).returnRoll());
							System.out.println("Department: " + al.get(x).getDept());
							System.out.println("Admission Date: " + al.get(x).getDate());
							System.out.print("CGPA: "  );
							if(al.get(x).getGpa() == 0) {
								System.out.println("Marks not entered");
							}
							else {
								System.out.println(al.get(x).getGpa());
							}
						}
					}
				
				//else System.out.println("Invalid choice");
				break;
			case 6:
				scan.nextLine();
				System.out.print("Enter the alloted roll number of student: ");
				roll1 = scan.nextLine();
				count = al.size();
				System.out.print("\n\t Total Memory now :" + runtime.totalMemory() + "\n");
				flag = false;
				for(int k=0;k<count;k++) {
					if(roll1.equals(al.get(k).returnRoll()) ) {
						al.remove(k);
						System.out.println("\t Entry successfully deleted!");
						flag = true;
						System.out.println("\n\t Total Memory after deletion:" + (runtime.totalMemory()-runtime.freeMemory()));
						break;
					}
					
				}
				if(flag == false) System.out.println("Roll number not found!");
				break;
			case 7:
				System.out.println("Logged out!");
				exit = true;
				break;
			default:
				System.out.print("Invalid choice!");
				break;
			}
		}while(exit != true);
		
	}
	
	char grade_calc(int m) {
		if(m>=91 && m<=100)
			return 'S';
		else if(m>=81 && m<=90)
			return 'A';
		else if(m>=71 && m<=80)
			return 'B';
		else if(m>=61 && m<=70)
			return 'C';
		else if(m>=51 && m<=60)
			return 'D';
		else if(m>=41 && m<=50)
			return 'E';
		else 
			return 'F';
	}
}
class STUDENT extends DEPARTMENT {
	
	private String roll;
	private String name;
	//private String dept;
	private String date;
	private int marks[] = new int[5];
	private int count[] = new int[4];
	double gpa;
	STUDENT(){
		for(int i=0;i<count.length;i++)
			count[i] = 0;
		
		for(int i=0;i<marks.length;i++)
			marks[i] = 0;
		gpa = 0;
	}
	public void setGpa(double c){
		gpa = c;
	}
	
	public void setName(String x){
		name = x;
	}
	/*public void setDept(String c) {
		dept = c;
	}*/
	public String getRoll(String dept) { 
		int roll = setCount(dept);
		return String.format("%s%02d%03d",dept, 18, roll);
	}
	public void setDate(String c){
		date = c;
	}
	public void setRoll(String c){
		roll = c;
	}
	public void setMarks(int m[])
	{
		marks = m;
	}
	public double getGpa(){
		return gpa;
	}
	int setCount(String dep) {
		if(dep.equals("BCSE")) 
			return ++count[0];
		else if(dep.equals("ETCE")) 
			return ++count[1];
		else if(dep.equals("MECH")) 
			return ++count[2];
		else if(dep.equals("ELEC")) 
			return ++count[3];
		return 0;
	}
	public int totalStudents() {
		int sum =0;
		for(int i=0;i<count.length;i++)
			sum += count[i];
		return sum;
	}
	public void totalStudentsInDept(){
		System.out.println("Number of students in BCSE: "+count[0]);
		System.out.println("Number of students in ETCE: "+count[1]);
		System.out.println("Number of students in MECH: "+count[2]);
		System.out.println("Number of students in ELEC: "+count[3]);
	}
	public String getName() {
		return name;
	}
	public int[] getMarks() { 
		return marks;
	}
	public int[] getCount() {
		return count;
	}
	public String returnRoll() {
		return roll;
	}
	public String getDate() {
		return date;
	}
	public String getDept() {
		return dept;
	}
	char grade_calc(int m) {
		if(m>=91 && m<=100)
			return 'S';
		else if(m>=81 && m<=90)
			return 'A';
		else if(m>=71 && m<=80)
			return 'B';
		else if(m>=61 && m<=70)
			return 'C';
		else if(m>=51 && m<=60)
			return 'D';
		else if(m>=41 && m<=50)
			return 'E';
		else 
			return 'F';
	}
	void displayDetails() {
		System.out.println("");
		System.out.println("--------------------------------------------------");
		System.out.println("\t\t\tMARKSHEET");
		System.out.println("--------------------------------------------------");
		System.out.println("Name: " + name);
		System.out.println("Roll: "+ roll);
		System.out.println("Department: "+ dept);
		System.out.println("Admission Date: "+ date);
		System.out.println("--------------------------------------------------");
	}
}
class DEPARTMENT {
	public String dept;
	public void setDept(String c) {
		dept = c;
	}
}
class SortComp implements Comparator<STUDENT>
{
    // Used for sorting in ascending order of
    // roll number
    @Override
    public int compare(STUDENT a, STUDENT b)
    {
        return (int)Math.ceil(b.gpa - a.gpa);
    }
}