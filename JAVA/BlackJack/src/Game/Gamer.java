package Game;

import java.util.Observable;
import java.util.Observer;

import card.BJCardPackOfGamer;
import card.Card;
import card.CardPackOfGamer;
import client.Client;

public class Gamer implements Observer{
	Client client;
	private Room room;
	private CardPackOfGamer cardPack;
	int nextIdx;
	
	public Gamer(Room r){
		cardPack = new BJCardPackOfGamer();
		setRoom(r);
	}

	public Room getRoom(){
		return this.room;
	}
	
	public void setRoom (Room r){
		this.room = r;
		r.registerObserver(this);
	}
	
	public int getScore(){
		return cardPack.getScore();
	}
	
	public void receiveCard(Card card){
		cardPack.addCard(card);
	}

	@Override
	public void update(Observable o, Object arg) {
		// TODO Auto-generated method stub
		client.sendMsgToServer((String)arg);
	}
}
