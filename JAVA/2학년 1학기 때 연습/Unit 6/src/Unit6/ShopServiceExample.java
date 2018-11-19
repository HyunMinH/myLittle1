package Unit6;

public class ShopServiceExample {
	public static void haha(String[] args){
		ShopService obj1 = ShopService.Getter();
		ShopService obj2 = ShopService.Getter();
		
		if (obj1 == obj2){
			System.out.println("같은 ShopService 객체 입니다.");
		} else {
			System.out.println("다른 ShopService 객체 입니다.");
		}
	}
}
