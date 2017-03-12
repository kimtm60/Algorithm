import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class No6359 {

	public static void main(String[] args) throws IOException{
		// 6359�� : ������ ���
		// ���� ��ȹ�� �������� ������� ����
		// BufferedReader ��� �� IOException ����ó�� �ʼ�!
        BufferedReader input = new BufferedReader( new InputStreamReader( System.in ) );
		int test = Integer.parseInt( input.readLine() );
		int n [] = new int [test]; //���� ��
		for(int i=0; i<test;i++)
			n[i] = Integer.parseInt( input.readLine() );
		
		for(int i :n)
			System.out.println(escapeNum(i));
	}
	
	static int escapeNum(int n){
		int cnt = 0;
		
		boolean door [] = new boolean [n]; // false �ʱ�ȭ, ���� ������ true ������ false
		
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
