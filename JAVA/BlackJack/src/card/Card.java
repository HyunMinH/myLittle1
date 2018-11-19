package card;

public class Card {
	Shape shape;
	Number number;
	
	public Card(Shape s, Number n){
		this.shape = s;
		this.number = n;
	}

	public Shape getShape() {
		return shape;
	}

	public void setShape(Shape shape) {
		this.shape = shape;
	}

	public Number getNumber() {
		return number;
	}

	public void setNumber(Number number) {
		this.number = number;
	}
}
