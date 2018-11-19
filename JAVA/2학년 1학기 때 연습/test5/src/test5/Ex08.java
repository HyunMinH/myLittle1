package test5;

public class Ex08 implements Unit5Interface{

	@Override
	public void run() {
		// TODO Auto-generated method stub
		int[][] array = {
				{95, 86},
				{83, 92, 96},
				{78, 83, 93, 87, 88}
		};
		
		int sum = 0;
		double avg = 0.0;
		int cnt = 0;
		
		for(int[] idxi : array){
			for(int num: idxi){
				sum += num;
				cnt++;
			}
		}
		
		avg = (double)sum / cnt;
		
		System.out.println("sum: " + sum);
		System.out.println("avg: " + avg);
	}

}
