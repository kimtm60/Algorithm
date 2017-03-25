/*
	* 라그랑주의 네제곱 정리 
	* 문제번호 #3933 
*/

#include <stdio.h>
#include <math.h>
#define MOO 32769
int cache[MOO];

int solve(int n)
{
	
	if (cache[n])
		return cache[n];
		
	// for 문을 통해서 미리 값 구해놓기 
	int i,j,k,p;
	int tmp;
	
	int t = (int)sqrt(n);
	
	for (i=0;i<=t;i++)
	{
		for (j=i;j<=t;j++){
			
			for (k=j;k<=t;k++){
				
				for (p=k;p<=t;p++){
					
					
					tmp = i*i + j*j + k*k + p*p;
				
					if (tmp == n)
						cache[tmp] += 1;
										
				}
			}
		}
	}
	
	return cache[n];
}


int main()
{
	// cache 초기화 
	for (int i=0;i<MOO;i++){
		cache[i] = 0;
	}
	
	int num;
	
	while(1){
		
		scanf("%d",&num);
		
		if (num == 0)
		
			break;
			
		printf("%d\n",solve(num));
	
	}
		
	return 0;
}
