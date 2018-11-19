import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;


public class AccountExample {
	static Scanner keybord = new Scanner(System.in);
	
	public static void main(String[] args){
		String fileName = new String();
		Scanner fileIn = null;
		int idx;
		Account[] account = new Account[10];
		String name = new String();
		String selectOp = new String();
		double money, debt;
		boolean again;
		
		System.out.print("fileName: ");
		fileName = keybord.next();
		
		//fileOpen
		try{
			fileIn = new Scanner(new FileInputStream(fileName));
		}catch(FileNotFoundException e){
			System.out.println("no file");
			System.exit(1);
		}
		
		idx = -1;
		while(fileIn.hasNext()){
			if(idx == 9){
				System.out.println("data over. we take 10 item.");
				break;
			}
			
			name = fileIn.next();
			if(fileIn.hasNextDouble() == false){
				System.out.println("file is wrong");
				System.exit(2);
			}
			money = fileIn.nextDouble();
			if(fileIn.hasNextDouble() == false){
				System.out.println("file is wrong");
				System.exit(2);
			}
			debt = fileIn.nextDouble();
			
			idx += 1;
			account[idx] = new Account(name, money, debt);
		}
		fileIn.close();
		
		//file has no data;
		if(idx == -1){
			System.out.println("no data in file.");
			System.exit(2);
		}
		
		
		
		sortWithBalance(account, idx);
		
		again = true;
		while(again){
			System.out.println("d: deposit, w: withdraw, r: rent, b: sortwithBalance & print, n: sortWithName & print, debt: sortWithDebt & print");
			selectOp = keybord.next();
			
			switch(selectOp){
			case "d": deposit(account, idx); break;
				
			case "w": withdraw(account, idx); break;
				
			case "r": rent(account, idx); break;
				
			case "b": sortWithBalance(account, idx); printAccount(account, idx); break;
				
			case "n": sortWithName(account, idx); printAccount(account, idx); break;
				
			case "debt": sortWithDebt(account, idx); printAccount(account, idx); break;
			
			default: System.out.println("program을 종료합니다."); again = false; break;
			}
		}
	}
	
	
	static void printAccount(Account account[], int lastIdx){
		int i;
		
		for(i=0 ; i<=lastIdx; i++)
			System.out.println(account[i].getName() + " " + account[i].getBalance() + " " + account[i].getDebt());
	}

	
	static void rent(Account account[], int lastIdx){
		int i;
		String wantName = new String();
		double money;
		
		System.out.println("input name and money");
		wantName = keybord.next();
		money = keybord.nextDouble();
		
		for(i=0; i<=lastIdx; i++){
			if(account[i].getName().equals(wantName)){
				account[i].rent(money);
				return;
			}
		}
		
		System.out.println("no name");
	}
	
	
	static void deposit(Account account[], int lastIdx){
		int i;
		String wantName = new String();
		double money;
		
		System.out.println("input name and money");
		wantName = keybord.next();
		money = keybord.nextDouble();
		
		for(i=0; i<=lastIdx; i++){
			if(account[i].getName().equals(wantName)){
				account[i].deposit(money);
				return;
			}
		}
		
		System.out.println("no name");
	}
	
	
	
	static void withdraw(Account account[], int lastIdx){
		int i;
		String wantName = new String();
		double money;
		
		System.out.println("input name and money");
		wantName = keybord.next();
		money = keybord.nextDouble();
		
		for(i=0; i<=lastIdx; i++){
			if(account[i].getName().equals(wantName)){
				if(account[i].withdraw(money) == false){
					System.out.println("balance is smaller than money to withdraw");
				}
				return;
			}
		}
		
		System.out.println("no name");
	}
	
	
	
	static void sortWithBalance(Account account[], int lastIdx){
		int i, j;
		Account tmp = new Account();
		
		for(i=0; i<=lastIdx; i++){
			for(j=i+1; j<=lastIdx; j++){
				if(account[i].getBalance() > account[j].getBalance()){
					tmp = account[i];
					account[i] = account[j];
					account[j] = tmp;
				}
			}
		}
	}
	
	static void sortWithName(Account account[], int lastIdx){
		int i, j;
		Account tmp = new Account();
		
		for(i=0; i<=lastIdx; i++){
			for(j=i+1; j<=lastIdx; j++){
				if(account[i].getName().compareTo(account[j].getName()) > 0){
					tmp = account[i];
					account[i] = account[j];
					account[j] = tmp;
				}
			}
		}
	}
	
	static void sortWithDebt(Account account[], int lastIdx){
		int i, j;
		Account tmp = new Account();
		
		for(i=0; i<=lastIdx; i++){
			for(j=i+1; j<=lastIdx; j++){
				if(account[i].getDebt() > account[j].getDebt()){
					tmp = account[i];
					account[i] = account[j];
					account[j] = tmp;
				}
			}
		}
	}
}
