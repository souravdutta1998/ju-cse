import java.io.*;
import java.util.*;
public class assignment3{
	public static void main(String args[]) {
		
		Scanner in = new Scanner(System.in);
		Parentheses obj = new Parentheses();  //declaration of object of class Parentheses
		boolean exit = false;
		do{
			System.out.println("-------------------------------------");
			System.out.println("1. Check parantheses balance");
			System.out.println("2. Exit!\n");
			System.out.print("Enter the choice number: ");
			int choice = in.nextInt();
			switch(choice){
				case 1:
					in.nextLine();
					System.out.println("Enter the string to be checked: ");
					String s = in.nextLine();
					if( obj.check(s)) 
						System.out.println("Parentheses are BALANCED.");
					else System.out.println("Parentheses are NOT BALANCED");
					break;
				case 2:
					System.out.println("Logged out!");
					exit = true;
					break;
			}
			
		}while(exit != true);  //loop continues until the boolean value of exit becomes true
		
	}
}
class Parentheses {  
	private Scanner in = new Scanner(System.in);
	boolean isPairMatch(Character character1, Character character2)  //function to check if the popped element matches with the current element
	{
		if (character1 == '(' && character2 == ')')
			return true;
		else if (character1 == '{' && character2 == '}')
			return true;
		else if (character1 == '[' && character2 == ']')
			return true;
		else
			return false;
	}
	public boolean check(String str) {  //boolean function to check whether the parentheses are balanced
		STACK<Character> stack = new STACK<Character>();
		int i=0;
		while(i< str.length()){
			if(str.charAt(i) == '{' || str.charAt(i) == '(' || str.charAt(i) == '[')
				stack.push(str.charAt(i));
			if(str.charAt(i) == '}' || str.charAt(i) == ')' || str.charAt(i) == ']'){
				if(stack.empty()) return false;
				else if(! isPairMatch(stack.pop() , str.charAt(i)) )
					return false;
			}
			i++;
		}
		if(stack.empty()) return true;
		else return false;
	}
}
class STACK<Character> extends Vector<Character> {  //implementation of stack 
	public STACK() {  //contructor to make the stack null
	}
	public Character peek(){  //return the top element
		int len = size();
		if(len ==0)
			throw new EmptyStackException();
		return elementAt(len -1);
	}
	public Character push(Character item){  //push the element to the stack
		addElement(item);
		return item;
	}
	public Character pop() {  //pop the element and return top from the stack
		Character ob;
		int len = size();
		ob = peek();
		removeElementAt(len -1);
		return ob;
	}
	
	public boolean empty(){  //check whether the stack is empty
		return size() == 0;
	}
}