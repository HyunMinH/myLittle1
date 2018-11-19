package Unit6;

public class ShopService {
	private static ShopService shopService = new ShopService();
	
	private ShopService(){
		
	}
	
	public static ShopService Getter(){
		return shopService;
	}
}
