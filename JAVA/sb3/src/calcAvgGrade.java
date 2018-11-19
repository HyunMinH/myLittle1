import java.util.Scanner;

public class calcAvgGrade {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner keyboard = new Scanner(System.in);
		
		
		System.out.println("Name of exercise 1:");
		String exercise1=keyboard.nextLine();
		System.out.println("Score received for exercise 1:");
		int score1=keyboard.nextInt();
		System.out.println("Total points possible for exercise 1:");
		int possible1=keyboard.nextInt();
		
		System.out.println();
		keyboard.nextLine();
		
		System.out.println("Name of exercise 2:");
		String exercise2=keyboard.nextLine();
		System.out.println("Score received for exercise 2:");
		int score2=keyboard.nextInt();
		System.out.println("Total points possible for exercise 2:");
		int possible2=keyboard.nextInt();
		
		System.out.println();
		keyboard.nextLine();
		
		System.out.println("Name of exercise 3:");
		String exercise3=keyboard.nextLine();
		System.out.println("Score received for exercise 3:");
		int score3=keyboard.nextInt();
		System.out.println("Total points possible for exercise 3:");
		int possible3=keyboard.nextInt();
		
		System.out.println();
		
		int score = score1+score2+score3;
		int possible = possible1+possible2+possible3;
		
		System.out.println("==========================================================================");
		System.out.printf("%-20s%-20s%-20s\n","Exercise","Score","Total Possible");
		System.out.printf("%-20s%-20d%-20d\n",exercise1,score1,possible1);
		System.out.printf("%-20s%-20d%-20d\n",exercise2,score2,possible2);
		System.out.printf("%-20s%-20d%-20d\n",exercise3,score3,possible3);
		System.out.printf("%-20s%-20d%-20d\n","Total", score, possible);
		System.out.printf("Your total is %d out of %d, or %.2f%%.\n", score, possible, (double)score/(double)possible*100);

	}

}