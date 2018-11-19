package quiz1;

import java.util.Scanner;

public class Program1 {
	public static void main(String args[]){
		Scanner keybord = new Scanner(System.in);
		int number;
		
		System.out.println("숫자를 입력하세요");
		number = keybord.nextInt();
		
		if(number % 2 == 0)
			System.out.println(number + "는 짝수입니다.");
		else
			System.out.println(number + "는 홀수입니다.");
		
		
	}
}
