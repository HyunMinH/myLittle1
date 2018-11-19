public class Hello {
	public static void main(String[] args){
		int sum = 0;
		int playerNum = 10;
		
		for(int i = 0; i<playerNum+1; i++){
			sum += i;
		}
		
		System.out.println("합은: " + sum);
	}
}
