package Unit6;

public class AccountExample {
	public static void hoho(String[] args){
		Account account = new Account();
		Account account2 = new Account();
		
		account.setBalance(10000);
		System.out.println("현재 잔고: " + account.getBalance());
		
		account.setBalance(-100);
		System.out.println("현재 잔고: " + account.getBalance());
		
		account.setBalance(20000000);
		System.out.println("현재 잔고: " + account.getBalance());
		
		account.setBalance(30000);
		System.out.println("현재 잔고: " + account.getBalance());
		
		account2.setBalance(250);
		System.out.println("현재 잔고: " + account2.getBalance());
		System.out.println("현재 잔고: " + account.getBalance());
	}
}
