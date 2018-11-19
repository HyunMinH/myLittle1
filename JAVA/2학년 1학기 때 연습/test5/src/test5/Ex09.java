package test5;

import java.util.Scanner;

public class Ex09 implements Unit5Interface{
	
	Scanner scanner = new Scanner(System.in);
	
	@Override 
	public void run(){
		boolean run = true;
		int studentNum = 0;
		int[] scores = null;
		
		while(run){
			printOutLine();
			
			int selectNo = scanner.nextInt();
			
			if(selectNo == 1){
				scores = scanStNum();
			}else if (selectNo == 2){
				scores = scanScore(scores);
			}else if (selectNo == 3){
				printScore(scores);
			}else if (selectNo == 4){
				analize(scores);
			}else if (selectNo == 5){
				System.out.println("시스템 종료 ");
				break;
			}else {
				System.out.println("잘못입력하셨습니다. ");
			}
		}
	}
	
	public void analize(int[] scores){
		int max = 0;
		int  sum = 0;
		
		for(int score: scores){
			if(max < score){
				max = score;
			}
			sum += score;
		}
		
		System.out.println("최고 점수: " + max);
		System.out.println("평균 점수: "+  (double)sum/scores.length);
	}
	
	public void  printScore(int[] scores){
		int i = 0;
		
		for(int score: scores){
			System.out.println("scores[" + i  + "]: "+ score);
			i++;
		}
	}
	
	public int[] scanScore(int[] scores){
		int score;
		
		for(int i=0; i<scores.length; i++){
			System.out.println("scores[" + i  + "]> ");
			score = scanner.nextInt();
			scores[i] = score;
		}
		return scores;
	}
	
	public int[] scanStNum(){
		System.out.println("학생수> ");
		int studentNum = scanner.nextInt();
		int [] studentArray = new int[studentNum];
		return studentArray;
	}
	
	public void printOutLine(){
		System.out.println("-------------------------------------------------------------------------");
		System.out.println("1. 학생수 | 2. 점수입력 | 3. 점수스트 | 4. 분석 | 5. 종료 );");
		System.out.println("-------------------------------------------------------------------------");
	}
	
	
}
