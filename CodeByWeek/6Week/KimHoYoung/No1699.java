
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class No1699{
	// 1699번 : 제곱수의 합
	// 큰 수의 제곱부터 비교하게 되면 12일 경우 반례  ex 12 = 3^2 + 1 + 1 + 1 => 4, 12 = 2^2 + 2^2 + 2^2 =>3
	// i는 1부터 n까지 비교 j는 1,2,4,8... 제곱들을 빼 준 인덱스의 값은 +1 해주면 최소 개수 충족
	public static void main(String args[]) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(input.readLine());
		int count[] = new int [100001];
		
		for(int i=1;i<=n;i++)
			for(int j=1;j*j<=i;j++){
				if(count[i] > count[i-j*j] + 1 || count[i] == 0)
					count[i] = count[i-j*j] + 1;
			}
		System.out.println(count[n]);
	}
}



