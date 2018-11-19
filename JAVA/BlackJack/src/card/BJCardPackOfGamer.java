package card;

import java.util.ArrayList;

public class BJCardPackOfGamer implements CardPackOfGamer{
	ArrayList<Card> cardList;
	
	public BJCardPackOfGamer(){
		cardList = new ArrayList<Card>();
	}
	
	@Override
	public int getScore() {
		// TODO Auto-generated method stub
		int sum = 0;
		
		for(Card card : cardList){
			sum += calcCardScore(card);
		}
		
		return sum;
	}
	
	private int calcCardScore(Card card){
		int score = 1;
		
		for(int i=0; i<Number.values().length; i++){
			if(card.getNumber() == Number.values()[i])
				break;
			score++;
		}
		
		return score;
	}

	@Override
	public void addCard(Card card) {
		// TODO Auto-generated method stub
		cardList.add(card);
	}

	@Override
	public void removeAllCards() {
		// TODO Auto-generated method stub
		cardList.removeAll(cardList);
	}

}
