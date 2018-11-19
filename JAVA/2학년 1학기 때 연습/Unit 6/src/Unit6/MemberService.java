package Unit6;

public class MemberService {
	
	public boolean login(String id, String password){
		if (id.equals("hong") == true){
			if (password.equals("12345") == true){
				return true;
			}
		}
		return false;
	}
	
	public void logout(String id){
		System.out.println(id + "님이 로그아웃 하였습니다.");
	}
}
