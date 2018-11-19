import java.io.InputStream;
import java.net.Socket;
import java.util.concurrent.ExecutorService;

public class ConnectionToClient {
	private static final int MAX_CLIENT = 10;
	private static int clientNumber = 0;
	
	private Socket connectionSocket;
	private ExecutorService executorService;
	
	private ConnectionToClient(Socket socket, ExecutorService e){
		this.connectionSocket = socket;
		this.executorService = e;
		clientNumber++;
	}
	
	private void receive()
	{
		Runnable runnable = new Runnable(){
			@Override
			public void run() {
				// TODO Auto-generated method stub
				try{
					while(true){
						byte[] clientInput = new byte[100];
						InputStream inputStream = connectionSocket.getInputStream();
						
						if(inputStream.read(clientInput) == -1){
							System.out.println("client's wrong input");
						}else{
							
						}
						
					}
				}catch(Exception e){
					
				}
			}
			
		};
		
		executorService.submit(runnable);
	}
	
	
	
	
	private void send(String data)
	{
		Runnable runnable = new Runnable(){
			@Override
			public void run() {
				// TODO Auto-generated method stub
				try{
					
				}catch(Exception e){
					
				}
			}
			
		};
		
		executorService.submit(runnable);
	}
	
	public static ConnectionToClient makeConnection(Socket socket, ExecutorService executorService){
		if(clientNumber < MAX_CLIENT){
			return makeClientWithSocket(socket, executorService);
		}else{
			return null;
		}
		
	}
	
	private static ConnectionToClient makeClientWithSocket(Socket socket, ExecutorService e){
		ConnectionToClient client = new ConnectionToClient(socket, e);
		client.receive();
		
		return client;
	}

	public Socket getConnectionSocket() {
		return connectionSocket;
	}

	public void setConnectionSocket(Socket connectionSocket) {
		this.connectionSocket = connectionSocket;
	}
	
	
}
