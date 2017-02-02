package baekjoon.to5000;

import java.util.Scanner;

public class No2577 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		int b = scan.nextInt();
		int c = scan.nextInt();
		
		int result = a * b * c;
		String result_str = result+"";
		int result_len = result_str.length();
		int[] resultArray = new int[10];

		for(int i=0;i<result_len;i++) {
			++resultArray[result%10];
			result = result/10;
		}
		for(int i=0;i<resultArray.length;i++) {
			System.out.println(resultArray[i]);
		}
		scan.close();
	}
}
