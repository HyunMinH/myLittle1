import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class StringChangeV2 {
	public static void main(String[] args){
		final String src = "apple";
		final String dest = "orange";
		final String fileName = "memo.txt";
		
		FileInputStream fileIn = null;
		try {
			fileIn = new FileInputStream(fileName);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return;
		}
		
		Scanner in = new Scanner(fileIn);
		int cnt = 0;
		
		String newString = "";
		
		
		// read from file and change first and third apple
		while(in.hasNextLine()){
			String str = in.nextLine();
			
			int idx = str.indexOf(src);
			while(idx > -1){
				// if str has src
				
				cnt++;
				newString += str.substring(0, idx);
				
				if(cnt == 1 || cnt == 3){
					newString += dest;
				}else{
					newString += src;
				}
				
				str = str.substring(idx + src.length());
				idx = str.indexOf(src);
			}
			newString += str + "\n";
		}
		
		in.close();
		try {
			fileIn.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return;
		}
		
		
		// write new String
		BufferedWriter out = null;
		try {
			out = new BufferedWriter(new FileWriter(fileName));
			out.write(newString);
			out.close();
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
			System.exit(1);
		}
	}
}
