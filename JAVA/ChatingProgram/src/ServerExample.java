import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Iterator;
import java.util.List;
import java.util.Vector;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ServerExample {
	public static final int PORT_NUMBER = 5001;
	
	private static final int MAX_SERVER_NUM = 1;
	private static int SERVER_NUM = 0;
	
	private ExecutorService executorService;
	private ServerSocket serverSocket;
	private List<ConnectionToClient> connections = new Vector<ConnectionToClient>();
	
	private ServerExample()
	{
		
	}
	
	public void startServer()
	{
		this.makeExecutorService();
		this.makeAndBindServerSocket();
		this.acceptClient();
	}
	
	public String stopServer()
	{
		this.closeAllClientSocket();
		this.closeServerSocket();
		this.exitExecutorService();
		return this.stopMessage();
	}
	
	private void makeExecutorService()
	{
		this.executorService = Executors.newFixedThreadPool(
			Runtime.getRuntime().availableProcessors()	
		);
	}
	
	private void makeAndBindServerSocket()
	{
		this.makeServerSocket();
		this.bindServerSocket();
	}
	
	private void makeServerSocket()
	{
		try {
			serverSocket = new ServerSocket();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private void bindServerSocket()
	{
		try{
			serverSocket.bind(new InetSocketAddress("localhost", PORT_NUMBER));
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	
	private void acceptClient()
	{
		this.handlingTask(this.makeAcceptTask());
	}
	
	private Runnable makeAcceptTask()
	{
		Runnable runnable = new Runnable(){
			@Override
			public void run() {
				while(true){
					try{
						Socket socket = serverSocket.accept();
						ConnectionToClient client = ConnectionToClient.makeConnection(socket, executorService);
						connections.add(client);
					}catch(Exception e){
						e.printStackTrace();
						break;
					}
				}
				
			}
		};
		
		return runnable;
	}
	
	private void handlingTask(Runnable task)
	{
		this.executorService.submit(task);
	}
	
	private void closeAllClientSocket()
	{
		Iterator<ConnectionToClient> iterator = connections.iterator();
		
		while(iterator.hasNext()){
			ConnectionToClient client = iterator.next();
			
			try {
				client.getConnectionSocket().close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			iterator.remove();
		}
	}
	
	private void closeServerSocket()
	{
		if(serverSocket != null && !serverSocket.isClosed()){
			try {
				serverSocket.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
	private void exitExecutorService()
	{
		if(executorService != null && !executorService.isShutdown()){
			executorService.shutdown();
		}
	}
	
	private String stopMessage()
	{
		return "server is stopped.";
	}
	
	public static ServerExample makeServerExample()
	{
		if(SERVER_NUM < MAX_SERVER_NUM){
			SERVER_NUM++;
			ServerExample server = new ServerExample();
			return server;
		}else{
			return null;
		}
	}
}
