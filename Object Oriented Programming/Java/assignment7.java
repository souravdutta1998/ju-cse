

import java.io.File;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Filenamecomparator implements Comparator<File>{
  @Override
  public int compare(File a,File b){
      return a.getName().compareTo(b.getName());
  }  
}

class Filesizecomparator implements Comparator<File>{
    @Override
    public int compare(File a,File b){
        int x,y;
        long aSize= a.length();
        long bSize= b.length();
        if(aSize==bSize){return 0;}
        else{
            if(aSize>bSize){x=2;y=1;}
            else{y=2;x=1;}
            return Integer.compare(x,y);
        }
    }
}

class Filedatecomparator implements Comparator<File>{
    @Override
    public int compare(File a,File b){
      int x,y;
      long adate= a.lastModified();
      long bdate= b.lastModified();
      if(adate==bdate){return 0;}
        else{
            if(adate>bdate){x=2;y=1;}
            else{y=2;x=1;}
            return Integer.compare(x,y);
        }
  } 
}

public class assignment7 {
    public static void main(String[] args) {
        String dirname;
        String chr;
        int ch;
        Scanner sc= new Scanner(System.in);
        dirname=sc.next();
        File f1=new File(dirname);
        File[] files = f1.listFiles();
        if(f1.isDirectory()){
            System.out.println("directory of "+dirname);
            String s[] = f1.list();
            for(int i=0;i<s.length;i++){
                File f = new File(dirname+"/"+s[i]);
                if(f.isDirectory()){
                    System.out.println(s[i]+" is a directory");
                    System.out.println("directory size : "+ f.length()+" bytes");
                    System.out.println("directory last modified: "+f.lastModified());
                }
                else{
                    System.out.println(s[i] + "is a file");
                    System.out.println("file size : "+ f.length()+" bytes");
                    System.out.println("file last modified: "+f.lastModified());
                }
            }
            while(true){
         System.out.println("press 1 to exit");
         chr=sc.next();
         switch(chr){
             case "1":System.exit(0);
                      break;
             case "-s":Arrays.sort(files, new Filesizecomparator());
                       System.out.println("sizewise sorted list :");
                       for(File f : files){
                           System.out.println("Filename = "+f.getName() + "Filesize = "+f.length());
                       }
                       break;
             case "-d":Arrays.sort(files, new Filedatecomparator());
                       System.out.println("datewise sorted list :");
                       for(File f : files){
                           System.out.println("Filename = "+f.getName() + "Date modified = "+f.lastModified());
                       }
                       break;
             default  :Arrays.sort(files, new Filenamecomparator());
                       System.out.println("namewise sorted list :");
                       for(File f : files){
                           System.out.println("Filename = "+f.getName());
                       }
         }
        }
        }
        else{
            System.out.println(dirname+" is not a directory");
        }
        
    }
    
}
