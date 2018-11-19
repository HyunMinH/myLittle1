package test;

public class TestEx4 {
	public static void runEx4(){
		int num1, num2;
		
		while(true){
			num1 =(int) (Math.random()*6) + 1;
			num2 =(int) (Math.random()*6) + 1;
			System.out.println( "(" + num1 +"," + num2 + ")");
			if(num1+num2 == 5)	break;
		}
	}
}
