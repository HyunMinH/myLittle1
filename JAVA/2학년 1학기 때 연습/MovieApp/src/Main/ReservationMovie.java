package Main;

import java.util.Scanner;


public class ReservationMovie {
	static Scanner scanner = new Scanner(System.in);
	static Movie city, gongzo, triple, conan, contact = new Movie();
	
	
	public static void Reservation(Member m){
		try{
			
		}catch(NullPointerException e){
			System.out.println("로그인을 먼저 하세요: ");
		}
	}
	
	
	public static void selectMovie(Member m){
		System.out.println("무슨 영화를 선택하시겠습니까?");
		printMovieChart();
		String selectNum = scanner.nextLine();
		
		if(Integer.parseInt(selectNum)>0 && Integer.parseInt(selectNum) <= 5){
			reserve(Integer.parseInt(selectNum));
		}else{
			isFailCheckMovieNum(m);
		}
	}
	
	
	public static void reserve(int selectNo){
		if(selectNo == 1){
			city.reserve();
		}else if(selectNo == 2){
			gongzo.reserve();
		}else if(selectNo == 3){
			triple.reserve();
		}else if(selectNo == 4){
			conan.reserve();
		}else if(selectNo == 5){
			contact.reserve();
		}
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
	
	
	static void isFailCheckMovieNum(Member m){
		System.out.println("잘못 선택하셨습니다. ");
		System.out.println("1.나가기  아무숫자: 재선");
		int selectNo = Integer.parseInt(scanner.nextLine());
		
		if(selectNo == 1){
			
		}else{
			selectMovie(m);
		}
	}
}
