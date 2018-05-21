import java.util.Scanner;
import java.util.Date;
import java.text.SimpleDateFormat;
public class assignment2{
	public static void main(String args[]){
		ITEM itemlist[] = new ITEM[10];
		int i=0, j;
		String code1, name1, type;
		int rate1, quantity1;
		int choice;
		boolean exit;
		boolean flag;
		Scanner scan = new Scanner(System.in);
		do {
			exit = false;
			System.out.println("");
			System.out.println("--------------------------------------------------");
			System.out.println("1. Add an item");
			System.out.println("2. Change rate of item");
			System.out.println("3. Add quantity of existing item(Receive)");
			System.out.println("4. Remove quantity of existing item(Issue)");
			System.out.println("5. Enquire price and quantity of an item");
			System.out.println("6. How many items cost more than a given amount");
			System.out.println("7. Exit! \n");
			System.out.print("Enter a choice number: ");
			choice = scan.nextInt();
			scan.nextLine();
			switch(choice) {
			case 1:
				
				System.out.print("Are you a Stock entry operator(SEO) or shopkeeper(SK): ");
				type = scan.nextLine();
				if(type.equals("SK")) System.out.println("Shopkeeper cannot operate this function!");
				else if(type.equals("SEO")) {
					itemlist[i] = new ITEM();
					System.out.print("Enter name of the item: ");
					name1 =  scan.nextLine();
					System.out.print("Enter rate of the item: ");
					rate1 =  scan.nextInt();
					if(rate1 < 0 ) { System.out.println("You entered invalid rate."); break;}
					System.out.print("Enter quantity of the item: ");
					quantity1 =  scan.nextInt();
					if(quantity1<0) {System.out.println("You entered invalid quantity."); break; }
					itemlist[i].setName(name1);
					itemlist[i].setRate(rate1);
					itemlist[i].setQuantity(quantity1);
					
					code1 = itemlist[i].returnCode(name1, quantity1);
					itemlist[i].setCode(code1);
					System.out.println("\n Item ID has been successfully generated.");
					System.out.println("ID number for this product is: " + code1);
					i++;
				}
				else System.out.println("You entered an invalid type!");
				break;
			case 2:
				System.out.print("Are you a Stock entry operator(SEO) or shopkeeper(SK): ");
				type = scan.nextLine();
				if(type.equals("SK")) System.out.println("Shopkeeper cannot operate this function!");
				else if(type.equals("SEO")){
					flag = false;
					System.out.print("Enter Item code: ");
					code1 = scan.nextLine();
					for(j=0;j<i;j++) {
						if((itemlist[j].getCode()).equals(code1)) {
							System.out.print("Enter new rate of the item: ");
							rate1 = scan.nextInt();
							itemlist[j].setRate(rate1);
							flag = true;
							System.out.println("Rate changed successfully!");
							break;
						}
					}
					if(flag == false) System.out.println("Item not found.");
				}
				else System.out.println("You entered an invalid type!");
				break;
			case 3:
				System.out.print("Are you a Stock entry operator(SEO) or shopkeeper(SK): ");
				type = scan.nextLine();
				if(type.equals("SK") || type.equals("SEO")){
					flag = false;
					System.out.print("Enter Item code: ");
					code1 = scan.nextLine();
					for(j=0;j<i;j++) {
						if((itemlist[j].getCode()).equals(code1)) {
							if(itemlist[j].getQuantity() == 0) {
								System.out.println("\nNo available quantity for this item! ");
							}
							System.out.println("Enter quantity you want to add to available quantity: ");
							quantity1 = scan.nextInt();
							quantity1 += itemlist[j].getQuantity();
							
							itemlist[j].setQuantity(quantity1);
							System.out.println("Quantity of the item added successfully.");
							flag = true;
							break;
						}
					}
					if(flag == false) System.out.println("Item not found.");
				}
				else System.out.println("You entered an invalid type!");
				break;
			case 4:
				System.out.print("Are you a Stock entry operator(SEO) or shopkeeper(SK): ");
				type = scan.nextLine();
				if(type.equals("SK") || type.equals("SEO")){
					flag = false;
					System.out.print("Enter Item code: ");
					code1 = scan.nextLine();
					for(j=0;j<i;j++) {
						if((itemlist[j].getCode()).equals(code1)) {
							if(itemlist[j].getQuantity() == 0) {
								System.out.println("\nNo available quantity for this item! ");
							}
							else {
								System.out.println("\nThis item is available for issue.");
								System.out.print("Enter quantity you want to remove from available quantity: ");
								quantity1 = scan.nextInt();
								quantity1 = itemlist[j].getQuantity() - quantity1;
								if(quantity1 < 0 ) System.out.println("Sorry! Only "+ itemlist[j].getQuantity() +" quantity available. You cannot issue this item.");
								else {
									itemlist[j].setQuantity(quantity1);
									System.out.println("Quantity of the item removed successfully.");
								}
							}
							flag = true;
							break;
						}
					}
					if(flag == false) System.out.println("Item not found.");
				}
				else System.out.println("You entered an invalid type!");
				break;
			case 5:
				System.out.print("Are you a Stock entry operator(SEO) or shopkeeper(SK): ");
				type = scan.nextLine();
				if(type.equals("SK") || type.equals("SEO")){
					flag = false;
					System.out.print("Enter Item code: ");
					code1 = scan.nextLine();
					for(j=0;j<i;j++) {
						if((itemlist[j].getCode()).equals(code1)) {
							System.out.println("\nName of existing item: " + itemlist[j].getName());
							System.out.println("Rate of existing item: "+ itemlist[j].getRate());
							System.out.println("Quantity of existing item: " + itemlist[j].getQuantity());
							flag = true;
							break;
						}
					}
					if(flag == false) System.out.println("Item not found.");
				}
				else System.out.println("You entered an invalid type!");
				break;
				
			case 6:
				int count = 0;
				System.out.print("Enter the amount: ");
				rate1 = scan.nextInt();
				for( j=0;j<i;j++) {
					if(itemlist[j].getRate() >  rate1) {
						count++;
					}
				}
				System.out.println("\n"+count + " items costs more than Rs. "+ rate1);
				break;
			case 7:
				
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
class ITEM{  
	private String code;  //private data members
	private String name;
	private int rate;
	private int quantity;
	public ITEM() {  //constructor to set the default value as 0
		rate = 0;
		quantity = 0;
	}
	public void setCode(String x) {  //setter function to set code
		code = x;
	}
	public void setName(String x) {  //setter function to set name
		name = x;
	}
	public void setRate(int r) {  //setter function to set rate
		rate = r;
	}
	public void setQuantity(int q) {  //setter function to set quantity
		quantity = q;
	}
	public String getCode() { return code; }  //getter function to return code
	public String getName() { return name; }  //getter function to return name
	public int getRate() { return rate; }  //getter function to return rate
	public int getQuantity() { return quantity; }   //getter function to return quantity
	String returnCode(String name, int q){  //function to return code in specified format
		String c = name.toUpperCase();
		return String.format("%c%c%c%03d",c.charAt(0),c.charAt(1),c.charAt(2),q);
	}
}