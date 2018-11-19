package test;

public class TestEx3 {
	public static void runEx3(){
		int sum = 0;
		for(int i =0; i<=100; i++){
			if(i%3 == 0)	sum += i;
		}
		
		System.out.println(sum);
	}
}
