import java.util.Scanner;

public class CountBookNumber {

	public static void main(String[] args) {
		Scanner input = new Scanner (System.in);
		int count[] = new int [10];
		int end = input.nextInt();
		int temp =0;
		for(int i=0;i<count.length;i++)
			count[i]=0;
		
		for(int i = end;i>=1;i--){
			temp = i;
			while(temp>0){
				count[temp%10]++;
				temp=temp/10;
			}
		}
		for(int i=0;i<count.length;i++)
		System.out.print(count[i]+" ");
	}

}
