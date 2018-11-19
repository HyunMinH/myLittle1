
public class ThreadDriver {
	public static void main(String[] args){
		Thread thread1 = new MovieThread();
		thread1.setDaemon(true);
		thread1.start();
		
		try{
			Thread.sleep(1000);
		}catch(InterruptedException e){
			
		}
		
		//thread1.interrupt();
		
		//Thread thread2 = new Thread(new MusicRunnable());
		//thread2.start();
	}
}
