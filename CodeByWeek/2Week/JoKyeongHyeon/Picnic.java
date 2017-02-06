package etc;

import java.util.Scanner;

public class Picnic {
	static int n;
	static int m;
	static int count = 0;
	static boolean[][] pairs = new boolean[10][10];
	static int[] taken = new int[10];
	static int flag = 0;
	static int result = 0;
	
	public static int pairing(int flag) {
		count = 0;
		System.out.println("시작");
		if(flag>n) return 1;
		for(int i=0;i<10;i++) {
			if(pairs[i][flag]==true&&taken[i]==0) {
				count++;
				taken[i] = 1;
			}
		}
		return (count=count==0?1:count)*pairing(++flag);
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		m = scan.nextInt();
		flag = 0;
		for(int i=0;i<m;i++) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			if(a>b) {
				int temp = a;
				a = b;
				b = temp;
			}
			pairs[b][a] = true;
		}
		System.out.println(pairing(flag));
		
		
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) 
				if(pairs[j][i]==true){
					System.out.println("["+j+"]"+"["+i+"]" + " : " +pairs[j][i]);
				}
		}
	}
}