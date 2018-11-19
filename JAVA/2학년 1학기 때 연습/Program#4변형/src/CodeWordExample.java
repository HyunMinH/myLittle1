import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class CodeWordExample {
	public static Scanner keybord = new Scanner(System.in);
	
	public static void main(String[] args){
		Scanner fileIn = null;
		String fileName = new String();
		CodeWord[] codeword = new CodeWord[10];
		int idx, lastIdx, selectNum;
		boolean again = true;
		
		System.out.print("fileName: ");
		fileName = keybord.next();
		
		//open the file
		try{
			fileIn = new Scanner(new FileInputStream(fileName));
		}catch(FileNotFoundException e){
			System.out.println("file is not open");
			System.exit(1);
		}
		
	
		//Scan String from file
		idx = 0;
		while(fileIn.hasNext()){
			if(idx >= 10){
				System.out.println("file has many data. we use 10");
				break;
			}
			codeword[idx] = new CodeWord(fileIn.next());
			idx = idx+1;
		}
		
		if(idx == 0){
			System.out.println("file has no data");
			System.exit(2);
		}
		
		
		lastIdx = idx - 1;
		sort(codeword, lastIdx);
		
		
		//option select
		while(again){
			System.out.print("Non zero: ouput a new code, zero: ouput all and quit");
			selectNum = keybord.nextInt();
			
			if(selectNum == 0){
				outputStart(codeword, lastIdx);
				again = false;
			}else{
				outputChange(codeword, lastIdx, selectNum);
			}
		}
	}
	
	
	public static void outputChange(CodeWord[] codeword, int lastIdx, int changeNum){
		int i;
		for(i=0; i<=lastIdx; i++){
			System.out.println(codeword[i].caculateWord(changeNum));
		}
	}
	
	
	public static void outputStart(CodeWord[] codeword, int lastIdx){
		int i;
		for(i=0; i<=lastIdx; i++){
			System.out.println(codeword[i].getStart());
		}
	}
	
	public static void sort(CodeWord[] codeword, int lastIdx){
		int i, j;
		CodeWord tmp = null;
		String str1 = null, str2 = null;
		
		for(i=0; i<=lastIdx; i++){
			str1 = codeword[i].getStart();
			for(j=i+1; j<=lastIdx; j++){
				str2 = codeword[j].getStart();
				if(str1.compareTo(str2) > 0){
					tmp = codeword[i];
					codeword[i] = codeword[j];
					codeword[j] = tmp;
				}
			}
		}
	}
}
