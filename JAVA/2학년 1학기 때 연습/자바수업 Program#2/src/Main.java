//2번문제가 정렬하는 거였는데 Accoun객체 배열을 정렬해보자 여러가지기준으

import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;


public class Main {
	public static void main(String[] args){
		Scanner keybord = new Scanner(System.in);
		Scanner fileIn = null;
		String fileName;
		Account[] account = new Account[10];
		int idx, num = 0, lastIdx, i;
		String name = new String();
		double score = 0;
		String selectOp;
		
		//fileName input
		System.out.println("file이름을 입력하세요. ");
		fileName = keybord.next();
		
		
		//fileOpen
		try{
			fileIn = new Scanner(new FileInputStream(fileName));
		}catch(FileNotFoundException e){
			System.out.println("찾는 파일이 없습니다.");
			System.exit(1);
		}
		
		
		//파일로부터 Account정보를 얻어오
		idx = 0;
		while(true){
			if(idx > 9){
				System.out.println("10개의 Account만을 활용합니다.");
				break;
			}
			
			if(fileIn.hasNext()){
				name = fileIn.next();
			}else{
				break;
			}
			
			if(fileIn.hasNextInt()){
				num = fileIn.nextInt();
			}else{
				System.out.println("파일 내용이 잘못 되어있습니다.");
				System.exit(2);
			}
			
			if(fileIn.hasNextDouble()){
				score = fileIn.nextDouble();
			}else{
				System.out.println("파일 내용이 잘못 되어있습니다.");
				System.exit(2);
			}
			
			account[idx] = new Account(name, num, score);
			idx = idx+1;
		}
		
		
		if(idx == 0){
			System.out.println("파일 안에 내용물이 없습니다.");
			System.exit(2);
		}
		
		
		lastIdx = idx-1;
		
		
		while(true){
			System.out.println("option을 선택하세요(name: name으로 정렬, num: num으로 정렬, score: score으로 정렬): ");
			selectOp = keybord.next();
			
			if(selectOp.equals("name")){
				sortWithName(account, lastIdx);
			}else if(selectOp.equals("num")){
				sortWithNum(account, lastIdx);
			}else if(selectOp.equals("score")){
				sortWithScore(account, lastIdx);
			}else{
				System.out.println("프로그램을 종료합니다.");
				System.exit(3);
			}
			
			for(i=0; i<=lastIdx; i++){
				System.out.println(account[i].getNumber() + " " + account[i].getName()+ " " + account[i].getScore());
			}
		}
	}
	
	
	public static void sortWithName(Account[] account, int lastIdx){
		Account temp = null;
		int i, j;
		
		for(i=0; i<=lastIdx; i++){
			for(j=i+1; j<=lastIdx; j++){
				if(account[i].getName().compareTo(account[j].getName()) > 0){
					temp = account[i];
					account[i] = account[j];
					account[j] = temp;
				}
			}
		}
	}
	
	public static void sortWithNum(Account[] account, int lastIdx){
		Account temp = null;
		int i, j;
		
		for(i=0; i<=lastIdx; i++){
			for(j=i+1; j<=lastIdx; j++){
				if(account[i].getNumber() > account[j].getNumber()){
					temp = account[i];
					account[i] = account[j];
					account[j] = temp;
				}
			}
		}
	}
	
	
	public static void sortWithScore(Account[] account, int lastIdx){
		Account temp = null;
		int i, j;
		
		for(i=0; i<=lastIdx; i++){
			for(j=i+1; j<=lastIdx; j++){
				if(account[i].getScore() > account[j].getScore()){
					temp = account[i];
					account[i] = account[j];
					account[j] = temp;
				}
			}
		}
	}
}
