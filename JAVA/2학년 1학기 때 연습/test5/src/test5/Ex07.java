package test5;

public class Ex07 implements Unit5Interface {

	@Override
	public void run() {
		// TODO Auto-generated method stub
		int max = 0;
		int[] array = {1,5,3,8,2};
		
		for(int num: array){
			if(max < num){
				max = num;
			}
		}
		
		System.out.println("max: " + max);;
	}
	
}
