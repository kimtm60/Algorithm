package baekjoon.to2000;

import java.util.Scanner;

public class No1978_2 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] nums = new int[n];
		int result = 0;
		for(int i=0;i<n;i++) {
			nums[i]= scan.nextInt();
			int count = 0;
			for(int j=1;j<=nums[i];j++) {
				if(nums[i]%j == 0) count++;
			}
			if(count==2) result++;
		}
		System.out.println(result);
		scan.close();
	}
}
