import java.io.*;
import java.util.*;

public class assignment5{
public static void main(String args[]){
	try{
		FileIndex fi = new FileIndex("./File.txt");
		fi.index();
		fi.sortbykey();
	}
	catch(Exception e){
		System.out.println(e);
	}
}
}
//class to store and manipulate FileIndex values
class FileIndex {
	private File file; //<member to hold file
	private HashMap<String, ArrayList<Integer>> hash; //<member to hold map from strings to lines
	//constructor to initialize data members and validate class invariants
	public FileIndex(String nm) throws Exception {
		file = new File(nm);
		hash = new HashMap<String, ArrayList<Integer>>();
	}
	//member function to index all strings in file by line
	public void index() throws IOException, FileNotFoundException {
		LineNumberReader lnr = new LineNumberReader(new FileReader(file));
		String line;
		StringTokenizer st;
		while((line = lnr.readLine()) != null) {
			st = new StringTokenizer(line, " ,.\t");
			while(st.hasMoreTokens()) {
				String str = st.nextToken().toLowerCase();
				ArrayList<Integer> list = hash.get(str);
				if(list != null)
					list.add(lnr.getLineNumber());
				else {
					list = new ArrayList<Integer>();
					list.add(lnr.getLineNumber());
					hash.put(str, list);
				}
			}
		}
	}
	//member function to report all indexed strings in file by line
	public void sortbykey(){
		ArrayList<String> sortedKeys = new ArrayList<String>(hash.keySet());
		Collections.sort(sortedKeys);
		
		for(String x: sortedKeys){
			ArrayList<Integer> list = hash.get(x);
			System.out.print(x + ":\t");
			for(int i : list)
				System.out.print(i + ", ");
			
			System.out.println();
		}
	}
}