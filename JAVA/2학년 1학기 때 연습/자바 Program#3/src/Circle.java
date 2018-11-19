
public class Circle {
	private String name = null;
	private double radius = 0;
	private int max;
	private int cur = 0;
	
	public Circle(String name, double radius, int max){
		this.name = name;
		
		if(radius <= 0)
			radius = 0;
		else
			this.radius = radius;
		
		if(max <= 0)
			max = 0;
		else
			this.max = max;
	}
	
	public void setMax(int max){
		if(max < 0)
			this.max = 0;
		else
			this.max = max;
	}
	
	public boolean setRadius(double radius){
		if(radius <= 0 )
			return false;
		else{
			this.radius = radius;
			return true;
		}
	}
	
	public String  getName(){
		return this.name;
	}
	
	public double getRadius(){
		return radius;
	}
	
	public int getMax(){
		return max;
	}
	
	public double getArea(){
		return radius*radius*3.14;
	}
	
	public boolean gogo(){
		if(cur == max)
			return false;
		else{
			cur = cur+1;
			return true;
		}
	}
}
