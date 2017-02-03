package baekjoon.from10000;

import java.util.Scanner;

public class No10448 {
	/*
	 *  1. 삼각수를 모두 구한다.
	 *  2. 삼각수 새게를 다 더한다.
	 *  3. 입력받은 수와 비교한다.
	 *  4. 같으면 1, 다르면 0
	 *  5. 답 출력
	 */
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt(); //몇개의 테스트 케이스를 받을 건지
		int[] answer = new int[n]; // 3개의 삼각수로 표현되면 1, 아니면 0을 담는 답안지
		int[] Tnums = new int[46]; 
		//삼각수를 담기 위한 배열(자연수 k가 1000까지 입력되기에 45번쨰 삼각수까지 필요)
		
		for(int i=1;i<46;i++) Tnums[i] = i*(i+1)/2; // 삼각수를 구해서 담는 코드
		
		for(int i=0;i<n;i++) {//테스트케이스 숫자만큼 반복
			int k = scan.nextInt();//자연수 k 입력
			
			for(int a=1;a<46;a++) {   
				for(int b=1;b<46;b++) {
					for(int c=1;c<46;c++) {
						if(k==Tnums[a]+Tnums[b]+Tnums[c]) answer[i] = 1; 
						//k가 삼각수3개로 표현 가능 한지 판단
					}
				}
			}
		}
		
		for(int re:answer) System.out.println(re); //답출력
		scan.close();
	}
}
