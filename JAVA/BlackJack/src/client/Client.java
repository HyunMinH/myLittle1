package client;

public interface Client {
	void sendMsgToServer(String msg);
	void receiveMsgFromServer(String msg);
}
