package ex3;

public class SoundableExample {
	private static void printSound(Soundable soundable){
		System.out.println(soundable.sound());
	}
	
	public static void mainOfEx3(String[] args){
		printSound(new Cat());
		printSound(new Dog());
	}
}
