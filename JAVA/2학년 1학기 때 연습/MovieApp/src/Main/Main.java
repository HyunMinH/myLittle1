package Main;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static Scanner scanner = new Scanner(System.in);
	static Member member;
	static Member[] alreadyMember = new Member[100];
	
	public static void main(String[] args){
		printMovieChart();
		
	}
	
	public static void printMovieChart(){
		System.out.println("-----Movie Chart-----" );
		System.out.println(" ");
		System.out.println("1 조작된 도시(예매율 30.7%)");
		System.out.println("2 공조(예매율 19.1%)");
		System.out.println("3 트리플 엑스 리턴즈(예매율 8.9%)");
		System.out.println("4 명탐정 코난: 에피소드 원-작아진 명탐정(예매율 5.8%)");
		System.out.println("5 컨택트(예매율 5.4%)");
	}
	
	public static void selectOption(){
		System.out.println("1(지금 예매), 2(영화정보), 3(개봉예정),  4(로그인), 5(내 정보)");
		int selectNum = scanner.nextInt();
		
		if(selectNum == 1){
			Reservation(member);
		}else if(selectNum == 2){
			
		}else if(selectNum == 3){
			
		}else if(selectNum == 4){
			
		}else if(selectNum == 5){
			
		}else{
			System.out.println("번호를 잘못 입력하셨습니다.");
			Main.selectOption();
		}
	}
	
	public Member login(){
		Member member = new Member();
		member.setID();
		member.setPassword();
		
		if(isMember(member)){
			return member;
		}else{
			return none;
		}
	}
	
	
	public boolean isMember(Member member){
		Arrays.sort(alreadyMember);
		if(Arrays.binarySearch(alreadyMember, member) < 0){
			return false;
		}else{
			return true;
		}
	}
}
