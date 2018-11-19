
public class Account {
	private String name = new String();
	private int number = 0;
	private double score = 0;
	
	public Account(String name, int number, double score){
		this.name = name;
		this.number = number;
		this.score = score;
	}
	
	
	public String getName(){
		return this.name;
	}
	
	public int getNumber(){
		return this.number;
	}
	
	public double getScore(){
		return this.score;
	}
}

