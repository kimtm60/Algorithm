/*
	* ��׶����� ������ ���� 
	* ������ȣ #3933 
*/

#include <stdio.h>
#include <math.h>
#define MOO 32769
int cache[MOO];

int solve(int n)
{
	
	if (cache[n])
		return cache[n];
		
	// for ���� ���ؼ� �̸� �� ���س��� 
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
	// cache �ʱ�ȭ 
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
