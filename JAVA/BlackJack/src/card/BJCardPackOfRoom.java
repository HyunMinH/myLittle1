package card;

import java.util.ArrayList;

public class BJCardPackOfRoom implements CardPackOfRoom{
	private static int NUMBER_OF_CARD = 52;
	private static int NUMBER_OF_NUMBER = Number.values().length;
	private static int NUMBER_OF_SHAPE = Shape.values().length;
	private ArrayList<Card> cardList;
	private int nextIdx;
	
	public BJCardPackOfRoom(){
		cardList = new ArrayList<Card>();
		makeCardList();
		mixCard();
	}

	private void makeCardList(){
		for(int i =0; i < NUMBER_OF_CARD; i++){
			Card card = new Card(Shape.values()[i/NUMBER_OF_SHAPE], Number.values()[i%NUMBER_OF_NUMBER]);
			cardList.add(card);
		}
	}
	
	@Override
	public Card getNextCard() {
		// TODO Auto-generated method stub
		return cardList.get(nextIdx++);
	}

	@Override
	public void mixCard() {
		// TODO Auto-generated method stub
		mixCardList();
		initCard();
	}
	
	private void mixCardList(){
		
	}

	private void initCard() {
		// TODO Auto-generated method stub
		nextIdx = 0;
	}

}
