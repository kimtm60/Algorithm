import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class No6359 {

	public static void main(String[] args) throws IOException{
		// 6359번 : 만취한 상범
		// 동적 계획법 문제지만 사용하지 않음
		// BufferedReader 사용 시 IOException 예외처리 필수!
        BufferedReader input = new BufferedReader( new InputStreamReader( System.in ) );
		int test = Integer.parseInt( input.readLine() );
		int n [] = new int [test]; //방의 수
		for(int i=0; i<test;i++)
			n[i] = Integer.parseInt( input.readLine() );
		
		for(int i :n)
			System.out.println(escapeNum(i));
	}
	
	static int escapeNum(int n){
		int cnt = 0;
		
		boolean door [] = new boolean [n]; // false 초기화, 문이 열리면 true 닫히면 false
		
		for(int i=1;i<=n;i++)
			for(int j=1;i*j<=n;j++){
				if(i == 1){
					Arrays.fill(door, true);continue;
				}
				door[i*j-1] = !door[i*j-1];
			}
		
		for(int i=0;i<n;i++){
			if(door[i] == true)
				cnt++;
		}
		return cnt;
	}
}
