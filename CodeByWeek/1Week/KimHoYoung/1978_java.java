
import java.util.Scanner;

public class FindPrimeNumber{
	public static void main (String args[]){
		Scanner input = new Scanner(System.in);
		
		int size = input.nextInt();
		int number [] = new int[size];
		int count = 0;
		boolean isPrime = false;
		
		for(int i=0;i<size;i++){
			number[i] = input.nextInt();
			isPrime = true;
			for(int j=2;j*j<=number[i];j++){
				if(number[i]%j == 0)
					isPrime = false;
			}
			if(isPrime && number[i] != 1)
				count++;
		}
		System.out.println(count);
	}
}