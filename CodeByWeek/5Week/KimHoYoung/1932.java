import java.util.Scanner;

public class Main {
	static int sum =0;
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int size = input.nextInt();
		int triangle [][] = new int[size][size];
		int sumTriangle [][] = new int [size][size];

		for(int i =0;i<triangle.length;i++)
			for(int j=0;j<i+1;j++)
				triangle[i][j] = input.nextInt();
		
		sumTriangle[0][0] = triangle[0][0];
		
		for(int i =0;i<triangle.length-1;i++)
			for(int j=0;j<i+1;j++){
				if(sumTriangle[i+1][j] < sumTriangle[i][j] + triangle[i+1][j])
					sumTriangle[i+1][j] = sumTriangle[i][j] + triangle[i+1][j];
				if(sumTriangle[i+1][j+1] < sumTriangle[i][j] + triangle[i+1][j+1])
					sumTriangle[i+1][j+1] = sumTriangle[i][j] + triangle[i+1][j+1];
			}
		
		int max = 0;
		for(int i=0;i<triangle.length;i++){
			if(sumTriangle[triangle.length-1][i] > max)
				max = sumTriangle[triangle.length-1][i];
		}
		System.out.println(max);
	}
	
}

