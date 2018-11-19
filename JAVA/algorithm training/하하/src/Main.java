import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		Scanner kbd = new Scanner(System.in);
		
		int testCaseNum = kbd.nextInt();
		
		ArrayList<Integer> inputX = new ArrayList<Integer>();
		ArrayList<Integer> inputY = new ArrayList<Integer>();
		
		for(int i=0; i<testCaseNum; i++){
			inputX.add(kbd.nextInt());
			inputY.add(kbd.nextInt());
		}
		
		kbd.close();
		
		for(int i=0; i<inputX.size(); i++)
			System.out.println(calcNumberOfMovement(inputX.get(i), inputY.get(i), inputX.get(i), 0));
	}
	
	public static int calcNumberOfMovement(int x, int y, int cur, int preDistance){
		int moveNum, moveMin = 99999;
		
		if(cur >= y)	return 99999;
		else if(cur == y-1) return 1;
		
		for(int i = preDistance-1; i<=preDistance+1; i++){
			if(i > 0){
				moveNum = calcNumberOfMovement(x, y, cur+i, i);
			
				if(moveNum < moveMin)
					moveMin = moveNum;
			}
		}
		
		return moveMin+1;
	}
}
