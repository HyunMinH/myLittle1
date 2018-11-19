
public class CodeWord {
	private String start;
	private int i;
	
	public CodeWord(String start){
		for(i=0; i<start.length(); i++){
			if(i%3== 0 ){
				if(isWhatCh(start.charAt(i)).equals("UpperCh") == false){
					start = null;
					return;
				}
			}else if(i%3 == 1){
				if(isWhatCh(start.charAt(i)).equals("LowCh") == false){
					start = null;
					return;
				}
			}else if(i % 3 == 2){
				if(isWhatCh(start.charAt(i)).equals("num") == false){
					start = null;
					return;
				}
			}
		}
		
		this.start = start;
	}
	
	
	
	public String getStart(){
		return this.start;
	}
	
	
	public static String isWhatCh(char ch){
		if(ch >= 'a' && ch <= 'z')
			return "LowCh";
		else if(ch >= 'A' && ch <= 'Z')
			return "UpperCh";
		else if(ch >= '0' && ch <= '9')
			return "num";
		else
			return null;
	}
	
	
	public String caculateWord(int num){
		String changed = new String();
		int i, mod = 0, set = 0, base = 0;
		
		for(i=0; i<start.length(); i++){
			if(isWhatCh(start.charAt(i)).equals( "LowCh")){
				mod = 26;
				set = 'a';
			}else if(isWhatCh(start.charAt(i)).equals("UpperCh")){
				mod = 26;
				set = 'A';
			}else if(isWhatCh(start.charAt(i)).equals("num")){
				mod = 10;
				set = '0';
			}
			
			base = start.charAt(i) - set + num;
			if(base >= 0){
				changed += (char)(base % mod + set);
			}else{
				changed += (char)((mod - ((-base)%mod))%mod + set);
			}
		}
		
		
		return changed;
	}
}
