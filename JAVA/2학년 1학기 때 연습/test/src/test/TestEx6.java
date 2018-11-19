package test;

public  class TestEx6 implements Unit4Interface {

	@Override
	public void run() {
		int line = 0;
		// TODO Auto-generated method stub
		for(int i = 1; i<=5; i++){
			line++;
			
			for(int j = 1; j<=line; j++){
				System.out.print("* ");
			}
			System.out.println("");
		}
	}

}
