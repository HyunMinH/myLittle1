
public class SteamMilk extends CondimentDecorator{
	Beverage beverage;
	
	public SteamMilk(Beverage b){
		this.beverage = b;
	}
	
	@Override
	public String getDescription() {
		// TODO Auto-generated method stub
		return beverage.getDescription() + ", 스팀 밀크";
	}

	@Override
	public double cost() {
		// TODO Auto-generated method stub
		return .10 + beverage.cost();
	}
}
