import java.util.ArrayList;

public class Main {
	static final int DATA_NUM = 100;
	static boolean[] numberExist = new boolean[DATA_NUM + 1];
	
	public static void main(String args[]){
		ArrayList<Integer> numberlist = null;
		
		numberlist = makeNum();
		
		makeExistArr(numberlist);
		
		isExistTwoNumberThatsSumIsV(100);
		
		printMidNum();
	}
	
	private static void printMidNum(){
		int sequence = 0;
		
		for(int i=0; i<DATA_NUM; i++){
			if(numberExist[i]){
				sequence++;
				
				if(sequence == 50)
					System.out.println(i);
			}
		}
	}
	
	private static void isExistTwoNumberThatsSumIsV(int v){
		for(int i=0; i<DATA_NUM/2; i++){
			int n1 = i, n2 = DATA_NUM - n1;
			
			if(numberExist[n1] && numberExist[n2])
				System.out.println(n1 + "  " + n2);
		}
	}
	
	
	private static void makeExistArr(ArrayList<Integer> list){
		for(int i=0; i<DATA_NUM+1; i++){
			numberExist[i] = false;
		}
		
		for(int i=0; i<DATA_NUM; i++){
			numberExist[list.get(i)] = true;
		}
	}
	
	private static ArrayList<Integer> makeNum(){
		ArrayList<Integer> list = new ArrayList<Integer>();
		
		for(int i = 0; i<DATA_NUM; i++)
			list.add((int) (Math.random() * DATA_NUM));
		
		return list;
	}
}
