package Game;

import java.util.ArrayList;
import java.util.Observable;
import java.util.Observer;

import card.BJCardPackOfRoom;
import card.CardPackOfRoom;

public class Room implements Subject{
	private ArrayList<Observer> observerList = new ArrayList<Observer>();
	private CardPackOfRoom cardPack;
	
	public Room(){
		cardPack = new BJCardPackOfRoom();
		standGame();
	}
	
	private void standGame(){
		while(true){
			//sleep(5);
			if(hasGamer() == false){
				break;
			}
			else{
				sendMsgAllObserver("게임이 곧 시작됩니다.");
				//sleep(5);
				startGame();
			}
		}
	}
	
	private void startGame(){
		
	}
	
	
	private boolean hasGamer(){
		if(observerList.size() == 0){
			return false;
		}
		else {
			return true;
		}
	}

	@Override
	public void registerObserver(Observer o) {
		// TODO Auto-generated method stub
		observerList.add(o);
	}

	@Override
	public void removeObserver(Observer o) {
		// TODO Auto-generated method stub
		observerList.remove(o);
	}

	
	@Override
	public void notifyObservers() {
		// TODO Auto-generated method stub
		String currentState = getCurrentState();
		sendMsgAllObserver(currentState);
	}
	
	private void sendMsgAllObserver(String msg){
		for(Observer o : observerList){
			o.update((Observable) o, msg);
		}
	}
	
	private String getCurrentState(){
		return "";
	}
	
}