
public class Bit {
	int num;
	
	public Bit(int n){
		this.num = n;
	}

	public int bitModular(int mod){
		int result;
		
		result = this.num & (~mod);
		
		return result;
	}
	
	
	public boolean isPowerBit(){
		int mask, num, cnt = 0;
		
		for(int i = 0; i < 31; i++){
			mask = 1 << i;
			
			num = mask & this.num;
			
			if(num >= 1){
				if(cnt == 0)
					cnt++;
				else
					return false;
			}
		}
		
		return true;
	}
	
	public int offRightestBit(){
		int num = 0, offed, mask;
		
		for(int i = 0; i<31; i++){
			mask = 1 << i;
			
			num = mask & this.num;
			
			if(num >= 1)
				break;
		}
		
		offed = this.num - num;
		
		return offed;
	}
	
	
}
