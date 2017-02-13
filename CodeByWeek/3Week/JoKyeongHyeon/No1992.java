package baekjoon.to2000;

import java.util.Scanner;

public class No1992 {
	/*
	 * 1. 전체가 0또는 1로만 이루어지는지 탐색
	 * 2. 전체가 동일하면 바로 값을 반환 
	 * 3. 다르면 영상을 분할
	 * 4. 분할된 영상마다 탐색
	 * 5. 반복
	 */
	static int[][] image = new int[64][64];

	public static void quadTree(int x, int y, int size) {

		int start = image[y][x];
		boolean flag = true;

		for(int i=y;i<y+size;i++) {
			for(int j=x;j<x+size;j++) {
				if(start != image[i][j]) {
					flag=false;

				}	
			}
		}
		if(flag == true) {
			System.out.print(start);
		} else {
			System.out.print("(");
			quadTree(x, y, size/2);
			quadTree(x+size/2, y, size/2);
			quadTree(x, y+size/2, size/2);
			quadTree(x+size/2, y+size/2, size/2);
			System.out.print(")");
		}

	}


	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = Integer.parseInt(scan.nextLine());
		for(int i=0;i<n;i++) {
			String line = scan.nextLine();
			String[] lineArray = line.split("");
			for(int j=0;j<n;j++) {
				image[i][j] = Integer.parseInt(lineArray[j]);
			}
		}
		quadTree(0,0,n);
	}
}
