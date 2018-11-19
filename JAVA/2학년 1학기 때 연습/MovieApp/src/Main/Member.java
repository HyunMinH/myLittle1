package Main;

import java.util.Scanner;
import java.util.regex.Pattern;

public class Member implements Comparable<Member>{
	private String name;
	private String id;
	private String password;
	private String phone;
	private static final String regPhone = "(02|010)-\\d{3,4}-\\d{4}";
	Scanner scanner = new Scanner(System.in);
	
	
	public Member newMember(){
		Member member = new Member();

		member.setName();
		member.setID();
		member.setPassword();
		member.setPhoneNumber();
		
		return member;
	}
	
	
	public void setName(){
		System.out.println("이름이 무엇입니까?: ");
		this.name = scanner.nextLine();
	}
	
	public void setID(){
		System.out.print("id: ");
		this.id = scanner.nextLine();
	}
	
	
	public void setPassword(){
		System.out.print("password: ");
		this.password = scanner.nextLine();
	}
	
	
	public void setPhoneNumber(){
		while(true){
			System.out.print("phone: ");
			this.phone = scanner.nextLine();
			if(Pattern.matches(regPhone, this.phone)) break;
			else System.out.println("전화번호 형식이 틀렸습니다.");
			
			System.out.print("아무 숫자.(다시 입력), 2.(나가기): ");
			String selectNum = scanner.nextLine();
			if(Integer.parseInt(selectNum) == 2) break;
		}
	}
	

	public Member getMember(){
		return this;
	}
	
	
	@Override
	public int compareTo(Member o){
		return name.compareTo(o.name);
	}
}
