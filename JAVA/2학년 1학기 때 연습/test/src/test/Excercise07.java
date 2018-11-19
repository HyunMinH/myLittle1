package test;

import java.io.IOException;
import java.util.Scanner;

public class Excercise07 implements Unit4Interface{
	int balance = 0;
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		boolean run = true;
		Scanner scanner = new Scanner(System.in);
		String inputString;
		
		while(run){
			System.out.println("-----------------------------");
			System.out.println("1. 예금 | 2. 출금 | 3. 잔고 | 4.종료 ");
			System.out.println("-----------------------------");
			System.out.print("선택> ");
			
			inputString = scanner.nextLine();
			
			if(inputString.equals("1")){
				System.out.println("예금액> ");
				inputString = scanner.nextLine();
				changeMoney("input", inputString);
				
			}else if(inputString.equals("2")){
				System.out.println("출금액> ");
				inputString = scanner.nextLine();
				changeMoney("output", inputString);
				
			}else if(inputString.equals("3")){
				System.out.println("잔고> ");
				System.out.println(balance);
				
			}else if(inputString.equals("4")){
				System.out.println("프로그램 종료");
				run = false;
				
			}else{
				System.out.println("1. 예금 | 2. 출금 | 3. 잔고 | 4.종료 ");
			}
			
		}
	}
	
	public void changeMoney(String s, String Money){
		if(s.equals("input")){
			balance += Integer.parseInt(Money);
		}else if(s.equals("output")){
			if(balance - Integer.parseInt(Money) <0){
				System.out.println("출금액이 잔고액보다 많습니다.");
			}else{
				balance -= Integer.parseInt(Money);
			}
		}
	}

}
