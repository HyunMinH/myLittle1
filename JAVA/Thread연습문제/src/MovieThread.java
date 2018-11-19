
public class MovieThread extends Thread{

	@Override
	public void run() {
		// TODO Auto-generated method stub
		while(true){
			System.out.println("동영상을 재생합니다.");
			try{
				Thread.sleep(1);
			}catch(InterruptedException e){
				//break;
			}
		}
	}
	
}
