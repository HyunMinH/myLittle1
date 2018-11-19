package test;

public class TestEx5 implements Unit4Interface{

	@Override
	public void run() {
		// TODO Auto-generated method stub
		for(int i =1; i<=10; i++){
			for(int j =1; j<=10; j++){
				if(4*i + 5*j == 60)
					System.out.println("(" + i + "," + j + ")" );
			}
		}
	}

}
