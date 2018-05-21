import java.io.*;
import java.util.*;
public class assignment4{
	private Quote quote;
	public static void main(String args[]){
		a4 obj = new a4();
		try{
			obj.quote = new Quote("./Quote.txt");
			System.out.println(obj.quote.readRandom());
		}
		catch(Exception e) {
			System.out.println(e.toString() + ": try again");
		}
	}
}
class Quote{  //class to store and manipulate quote values
	private String name;  //to hold the filenname
	private int count;   //to hold count
	private Random random;  //to generate random numbers
	
	//constructor to initialize data members
	public Quote(String nm) throws IOException,FileNotFoundException {
		name = nm;
		BufferedReader br = new BufferedReader(new FileReader(nm));
		String line;
		random = new Random();
		count =0;
		while((line = br.readLine())!=null){
			if(line.isEmpty())
				count++;
		}
		br.close();
		random = new Random();
	}
	public String getName(){  //getter function for name
		return name;
	}
	public int getCount(){  //getter function for count
		return count;
	}
	public String read(int number) throws IOException, FileNotFoundException{  //function to read the line whose number is indicated from file
		BufferedReader br = new BufferedReader(new FileReader(name));
		String line = null;
		int i=1;
		while(((line = br.readLine())!=null && (i<number))){
			if(line.isEmpty()) i++;
		}
		if(line == null){
			br.close();
			return line;
		}
		String lines =line;
		while(((line = br.readLine()) != null) && (!line.isEmpty()))
			lines += "\n" + line;
		br.close();
		return lines;
	}
	//function to read a random line from file
	public String readRandom() throws IOException, FileNotFoundException {
		return read(random.nextInt(count));
	}
}