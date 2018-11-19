
public class Whip extends CondimentDecorator{
	Beverage beverage;
	
	public Whip(Beverage b){
		this.beverage = b;
	}
	
	@Override
	public String getDescription() {
		// TODO Auto-generated method stub
		return beverage.getDescription() + ", 휘핑";
	}

	@Override
	public double cost() {
		// TODO Auto-generated method stub
		return .10 + beverage.cost();
	}
}
