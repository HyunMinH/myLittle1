import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class CarExample {
	static Scanner keybord = new Scanner(System.in);
	
	public static void main(String[] args){
		Scanner fileIn = null;
		String fileName = new String();
		Circle[] circles = new Circle[10];
		int idx, max, lastIdx;
		double radius;
		String name = new String();
		String selectOp = new String();
		boolean again = true;
		
		
		System.out.print("input fileName: ");
		fileName = keybord.next();
		
		//fileOpen
		try{
			fileIn = new Scanner(new FileInputStream(fileName));
		}catch(FileNotFoundException e){
			System.out.println("no file");
			System.exit(1);
		}
		
		
		//fileInput
		idx = 0;
		while(fileIn.hasNext()){
			if(idx == 10){
				System.out.println("file has many Data. we get only 10 circle Datas");
				break;
			}
			
			name = fileIn.next();
			
			if(fileIn.hasNextDouble() == false){
				System.out.println("file is wrong");
				System.exit(2);
			}
			
			radius = fileIn.nextDouble();
			
			if(fileIn.hasNextInt() == false){
				System.out.println("file is wrong");
				System.exit(2);
			}
			
			max = fileIn.nextInt();
			
			circles[idx] = new Circle(name, radius, max);
			
			if(circles[idx].getRadius() == 0)
				System.out.println("radius can't 0 or below. set radius 0.");
			if(circles[idx].getMax() == 0)
				System.out.println("max can't 0 or below. set max 0");
			
			idx = idx+1;
		}
		fileIn.close();
		
		
		if(idx == 0){
			System.out.println("file has no right data");
			System.exit(3);
		}
		
		
		lastIdx = idx-1;
		
		sortWithRadius(circles, lastIdx);
		
		while(again){
			System.out.println("a: output in increasing area, c: change radius of a circle, r: one circle run, else: exit");
			
			selectOp = keybord.next();
			
			switch(selectOp){
			case "a": outputConsol(circles, lastIdx); break;
				
			case "c": changeRadiusOfOneCircle(circles, lastIdx); sortWithRadius(circles, lastIdx); break;
				
			case "r": runOneCircle(circles, lastIdx); break;
				
			default: again = false; break;
			}
		}
		
		
		keybord.close();
		fileIn.close();
	}
	
	public static void runOneCircle(Circle[] circles, int lastIdx){
		String wantName = new String();
		Circle wantCircle = null;
		
		System.out.println("input name:");
		wantName = keybord.next();
		
		wantCircle = findCircleWithName(circles, lastIdx, wantName);
		
		if(wantCircle.gogo() == false)
			System.out.println(wantCircle.getName() + "의 타이어가 터졌습니다.");
		else
			System.out.println(wantCircle.getName() + "가 달려갑니다.");
		
		
	}
	
	
	public static void changeRadiusOfOneCircle(Circle[] circles, int lastIdx){
		String wantName = new String();
		double radius = 0;
		Circle wantCircle = null;
		
		System.out.println("input name & radius:");
		wantName = keybord.next();
		radius = keybord.nextDouble();
		
		wantCircle = findCircleWithName(circles, lastIdx, wantName);
		if(wantCircle == null){
			System.out.println("찾는 이름의 원이 없습니다.");
			return;
		}
		
		wantCircle.setRadius(radius);
	}
	
	
	public static Circle findCircleWithName(Circle[] circles, int lastIdx, String name){
		int i;
		
		for(i=0; i<=lastIdx; i++){
			if(circles[i].getName().equals(name))
				return circles[i];
		}
		
		return null;
	}
	
	public static void outputConsol(Circle[] circles, int lastIdx){
		int i;
		
		for(i=0; i<=lastIdx; i++)
			System.out.println(circles[i].getName() + "  "+ circles[i].getArea());
	}
	
	
	public static void sortWithRadius(Circle[] circles, int lastIdx){
		int i, j;
		Circle tmp = null;
		
		for(i=0; i<=lastIdx; i++){
			for(j=i+1; j<=lastIdx; j++){
				if(circles[i].getArea() > circles[j].getArea()){
					tmp = circles[i];
					circles[i] = circles[j];
					circles[j] = tmp;
				}
			}
		}
	}
}
