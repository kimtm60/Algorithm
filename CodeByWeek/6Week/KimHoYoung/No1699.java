
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class No1699{
	// 1699�� : �������� ��
	// ū ���� �������� ���ϰ� �Ǹ� 12�� ��� �ݷ�  ex 12 = 3^2 + 1 + 1 + 1 => 4, 12 = 2^2 + 2^2 + 2^2 =>3
	// i�� 1���� n���� �� j�� 1,2,4,8... �������� �� �� �ε����� ���� +1 ���ָ� �ּ� ���� ����
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



