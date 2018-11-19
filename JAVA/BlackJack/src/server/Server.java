package server;

public interface Server {
	void sendMsgToClient(String msg);
	void sendMsgToAllClient(String msg);
	void receiveMsgFromClient(String msg);
}
