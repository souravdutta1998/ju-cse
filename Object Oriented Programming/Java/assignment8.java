//package java_assignments.assignment18;

import java.io.*;
import java.util.zip.*;

public class assignment8{

    static void gzipFile(String file, String gzip_file) throws IOException,FileNotFoundException{

        FileInputStream fis = new FileInputStream(file);
        FileOutputStream fos = new FileOutputStream(gzip_file);
        GZIPOutputStream gzipOS = new GZIPOutputStream(fos);
        byte[] buffer = new byte[1024];
        int len;
        System.out.println();
        System.out.println("File : '" + file + "' zipped into zip file: "+gzip_file);
        while((len=fis.read(buffer)) >0){
            gzipOS.write(buffer, 0, len);
        }
        gzipOS.close();
        fos.close();
        fis.close();

    }

    static void zipDirectory(String directory, String zip_file) throws IOException,FileNotFoundException{

        File dir=new File(directory);
        System.out.println();
        if(!dir.isDirectory()){
            System.out.println("Not a valid directory path!\n");
            return;
        }

        File files[] = dir.listFiles();
        FileOutputStream fos = new FileOutputStream(zip_file);
        ZipOutputStream zOS = new ZipOutputStream(fos);

        for(int i=0;i<files.length;i++){
            if (files[i].isFile()){
                System.out.println("File : '" + files[i] + "' zipped into zip file: "+zip_file);
                FileInputStream fis = new FileInputStream(files[i]);
                ZipEntry zipEntry = new ZipEntry(files[i].getPath());
                zOS.putNextEntry(zipEntry);

                byte[] bytes = new byte[1024];
                int length;
                while ((length = fis.read(bytes)) > 0) {
                    zOS.write(bytes, 0, length);
                }

                zOS.closeEntry();
                fis.close();
            }
        }
        zOS.close();
        fos.close();
    }

    public static void main(String args[])  throws IOException,FileNotFoundException{

        int choice=1;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String zip_file;
        while(choice!=0){
            System.out.print("\n#1 COMPRESS A SINGLE FILE\n#2 COMPRESS ALL FILES OF A SPECIFIED FOLDER\n\nEnter your chocie: ");
            choice=Integer.parseInt(br.readLine());
            switch(choice){
                case 1:
                    System.out.println("Enter path for source file: ");
                    String source_file=br.readLine();
                    System.out.println("Enter path for zip file: ");
                    zip_file=br.readLine();
                    gzipFile(source_file,zip_file);
                    break;
                case 2:
                    System.out.println("Enter path for source folder: ");
                    String source_folder=br.readLine();
                    System.out.println("Enter path for zip file: ");
                    zip_file=br.readLine();
                    zipDirectory(source_folder,zip_file);
                    break;
                default:
                    choice=0;
                    System.out.println("\nInvalid inout! Aborting...\n");
            }
        }
    }
}
