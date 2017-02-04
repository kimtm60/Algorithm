package baekjoon.to2000;

import java.util.Scanner;

public class No1019 {
	
	/*
	 * 한 페이지 숫자의 0~9까지 숫자를 세는 로직은 어느 페이지나 같다.
	 * 그러므로 재귀호출을 이용
	 * 1.현재 페이지의 숫자를 카운팅
	 * 2.현재 페이지의 전 페이지로 이동해서 카운팅
	 * 3. 페이지가 0이 될 때까지 반복
	 */
	
	
	static long[] answers = new long[10]; 
	//인덱스 값이 0~9이고 해당 인덱스 위치에 들어있는 값이 그 인덱스가 몇번 나온지를 나타낸다
	
	static long flag = 0;//현재 몇페이지인지를 나타낸다.
	
	//재귀호출을 위한 재귀함수 구현
	public static long[] bookPage(long n) {
		flag = n;//현재 몇페이지인지 기억
		while(flag>0) {
			++answers[(int) (flag%10)];//페이지의 맨 뒷자리를 구해서 카운트
			flag /= 10; //맨뒷자리를 뺀 나머지 숫자를 구한다.
		}
		--n; //현재 페이지에서 이전 페이지로 이동
		if(n==0) return answers; //페이지가 0이면 그만 호출
		return bookPage(n); //페이지가 0이 아니면 다시 페이지의 숫자를 카운트(재귀호출)
	}	
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		long n = scan.nextInt();
		bookPage(n);
		for(long answer:answers) System.out.println(answer);
		
		scan.close();
	}

}
