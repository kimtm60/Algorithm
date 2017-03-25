#include <stdio.h>
#include <math.h>
#define MAX 1000000

char prime[MAX];

void makePrime()
{
	for (int i=2;i<MAX;i++){
		prime[i] = 1;	// 1 이 소수다. 
	}
	
	int n = (int)sqrt(MAX);
	for (int i=2;i<=n;i++)
	{
		if (prime[i])
		{
			for (int j=i*i;j<MAX;j+=i){
				prime[j] = 0;
			}
		}
	}
}
void solve(int n)
{
	
	
	for (int i=3;i<=n/2+1;i++)
	{
		if (prime[i] == 1)
		{
			if (prime[n-i] == 1){
				printf("%d = %d + %d\n",n,i,n-i);
				return;
			}
		}
	}
	
	printf("Goldbach's conjecture is wrong.\n");
}
int main()
{
	int n;
	makePrime();
	while(1)
	{
		scanf("%d",&n);
		if (n == 0)
			break;
		solve(n);
	}
	return 0;
}
