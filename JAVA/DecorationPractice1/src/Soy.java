
public class Soy extends CondimentDecorator{
	Beverage beverage;
	
	public Soy(Beverage b){
		this.beverage = b;
	}
	
	@Override
	public String getDescription() {
		// TODO Auto-generated method stub
		return beverage.getDescription() + ", 소유";
	}

	@Override
	public double cost() {
		// TODO Auto-generated method stub
		return .15 + beverage.cost();
	}
}
