package Unit6;

import java.util.Arrays;
import java.util.Scanner;

public class BankApplication {
	private static Account[] accountArray = new Account[100];
	private static Scanner scanner = new Scanner(System.in);
	private static int accountIndex = -1;
	
	public static void main(String[] args){
		boolean run = true;
		while(run){
			System.out.println("---------------------------------------------------------------");
			System.out.println("1.계좌생성 | 2.계좌목록 | 3.예금 | 4.출금 | 5.종료");
			System.out.println("---------------------------------------------------------------");
			System.out.print("선택> ");
			
			int selectNo = scanner.nextInt();
			scanner.nextLine();
			
			if(selectNo == 1){
				createAccount();
			} else if(selectNo == 2){
				if(accountIndex < 0){
					System.out.println("생성된 계좌가 없습니다.");
				}else{
					accountList();
				}
			} else if(selectNo == 3){
				deposit();
			} else if (selectNo == 4){
				withdraw();
			} else if(selectNo == 5){
				run = false;
			}
		}
	}
	
	
	private static void createAccount(){
		System.out.println("--------------");
		System.out.println("계좌 생성");
		System.out.println("--------------");
		
		if(accountIndex >=100){
			System.out.println("더 이상 계좌를 생성할 수 없습니다.");
			return;
		}
		
		String accountAno;
		String accountOwner;
		int  accountInitBalance;
		
		System.out.print("계좌번호: ");
		accountAno = scanner.nextLine();
		
		
		if(ifAlreadyAno(accountAno)>=0){
			System.out.println("이미 있는 계좌 번호입니다.");
			return;
		}
		
		System.out.print("계좌주: ");
		accountOwner = scanner.nextLine();
		System.out.print("초기입금액: ");
		accountInitBalance = scanner.nextInt();
		
		accountIndex++;
		accountArray[accountIndex] = new Account(accountAno, accountOwner, accountInitBalance);
		
		System.out.println("계좌가 생성되었습니다." );
	}
	
	private static void accountList(){
		for(int i = 0; i<=accountIndex; i++){
			Account account = accountArray[i];
			System.out.println(account.getAno() + "      " + account.getOwner() + "       " + account.getBalance());
		}
	}
	
	private static void deposit(){
		System.out.println("--------------");
		System.out.println("예금 ");
		System.out.println("--------------");
	
		
		System.out.print("계좌번호: ");
		String Ano = scanner.nextLine();
		
		int index = ifAlreadyAno(Ano);
		if(index < 0){
			System.out.println("찾는 계좌번호가 없습니다. ");
			return;
		} 
		
		System.out.print("예금액: ");
		int deposit = scanner.nextInt();
		int firstBalance = accountArray[index].getBalance();
		accountArray[index].setBalance(firstBalance + deposit);
		
		System.out.println("예금이 성공되었습니다. ");
	}
	
	private static void withdraw(){
		System.out.println("--------------");
		System.out.println("출금 ");
		System.out.println("--------------");
	
		
		System.out.print("계좌번호: ");
		String Ano = scanner.nextLine();
		
		int index = ifAlreadyAno(Ano);
		if(index < 0){
			System.out.println("찾는 계좌번호가 없습니다. ");
			return;
		} 
		
		System.out.print("출금액: ");
		int withdraw = scanner.nextInt();
		int firstBalance = accountArray[index].getBalance();
		accountArray[index].setBalance(firstBalance - withdraw);
		
		System.out.println("출금이 성공되었습니다. ");
	}
	
	private static int ifAlreadyAno(String Ano){
		for(int i=0; i<=accountIndex; i++){
			String alreadyAno = accountArray[i].getAno();
			if(Ano.equals(alreadyAno)){
				return i;
			}
		}
		return -1;
	}
	
}
