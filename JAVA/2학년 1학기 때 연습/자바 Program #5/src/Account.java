
public class Account {
	private String name;
	private double balance;
	private double debt;
	
	public Account(String name, double balance, double debt){
		this.name = name;
		
		if(balance <=0)
			this.balance = 0;
		else
			this.balance = balance;
		
		if(debt <= 0)
			this.debt = 0;
		else
			this.debt = debt;
	}
	
	
	public Account(){
		
	}
	
	
	public void deposit(double money){
		this.balance += money;
	}
	
	
	public boolean withdraw(double money){
		if(this.balance - money <0){
			return false;
		}else{
			this.balance -= money;
			return true;
		}
	}
	
	public double getBalance(){
		return this.balance;
	}
	
	public String getName(){
		return this.name;
	}
	
	public double getDebt(){
		return this.debt;
	}
	
	
	public void rent(double money){
		if(this.balance != 0){
			if(money > balance){
				money -= this.balance;
				this.balance = 0;
			}else{
				this.balance -= money;
				money = 0;
			}
		}
		
		this.debt += money;
	}
}
