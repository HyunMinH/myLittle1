
public class BitDrive {
	public static void main(String[] args){
		Bit bit = null;
		
		bit = new Bit(40);
		
		System.out.println(bit.bitModular(4));
		
		System.out.println(bit.isPowerBit());
		
		System.out.println(bit.offRightestBit());
	}
}
