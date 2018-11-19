package server;

public class BlackJackServer implements Server{

	private BlackJackServer(){
		
	}
	
	@Override
	public void sendMsgToClient(String msg) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void sendMsgToAllClient(String msg) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void receiveMsgFromClient(String msg) {
		// TODO Auto-generated method stub
		
	}
	
	
	public static BlackJackServer createInstance(){
		return new BlackJackServer();
	}
}
