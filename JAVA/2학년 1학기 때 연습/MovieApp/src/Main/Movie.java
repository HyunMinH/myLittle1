package Main;

import java.util.Scanner;


public class Movie {
	private final int seatNum = 150;
	private int remainingSeat;
	private int[][] seats = new int[10][15];
	
	Scanner scanner = new Scanner(System.in);
	
	void showSeats(){
		for(int i=0; i<seats.length; i++){
			for(int x=0; x<seats[0].length; x++){
				if(seats[i][x] == 0){
					System.out.println("□ ");
				}else if(seats[i][x] == 1){
					System.out.println("■");
				}
			}
			System.out.println(" ");
		}
	}
	
	
	int reserve(){
		showSeats();
		System.out.println("어떤 좌석을 선택하시겠습니까?");
		System.out.println("열: ");
		int y = Integer.parseInt(scanner.nextLine());
		System.out.println("좌석: ");
		int x = Integer.parseInt(scanner.nextLine());
		
		if(y>seats.length || y<0){
			isFailCheakSeats();
		}else if(x>seats[0].length || x<0){
			isFailCheakSeats();
		}else if(seats[y][x] == 0){
			return 1;
		}else if(seats[y][x] == 1){
			System.out.println("이미 있는 자리입니다. " );
			isFailCheakSeats();
		}
		
		return 0;
	}
	
	
	void isFailCheakSeats(){
		System.out.println("1.다시 예약  2.나가기 ");
		int selectNo = scanner.nextInt();
		
		if(selectNo == 1){
			reserve();
		}else if(selectNo == 2){
			
		}else{
			System.out.println("잘못 입력하셨습니다. ");
			isFailCheakSeats();
		}
	}
	
}
