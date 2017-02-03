import java.util.Scanner;

public class CountEachNumber {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int multi = 1;
		int count[] = new int [10];
		int n = 0;
		
		for(int i=0;i<3;i++){
			multi *= input.nextInt();
		}
		while(multi > 0){
			n = multi%10;
			count[n]++;
			multi/=10;
		}
		for(int i=0;i<10;i++)
			System.out.println(count[i]);
	}

}
