package 계솬기;

public class Calculate {
	
	public static double plus(double n1, double n2){
		return n1+n2;
	}
	
	public static double minus(double n1, double n2){
		return n1-n2;
	}
	
	public static double multiply(double n1, double n2){
		return n1*n2;
	}
	
	public static double divide(double n1, double n2){
		return n1/n2;
	}
	
	public static boolean isInteger(double n){
		int i;
		
		for(i=0; i<=n; i++);
		
		if(i == n)	return true;
		else	return false;
	}
	
	
	public static int modular(double n1, double n2){
		return (int)n1 % (int)n2;
	}
}
