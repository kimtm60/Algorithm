#include <stdio.h>

int val[1000];
int cache[1000];

// �迭���� �ִ밪���ؼ� �����ϴ� �Լ� 
int max_(int n){
	
	int max = 0;
	for (int i=0;i<n;i++)
	{
		if (max < cache[i])
			max = cache[i];
	}
	return max;
}

int main()
{
	int n;
	
	scanf("%d",&n);
	
	for (int i=0;i<n;i++)
	{
		scanf("%d",&val[i]);
	}
	
	cache[0] = 1;
	
	
	/*
		���� 
		cache 1 2 2 3 4
		value 1 5 2 3 7
		
		cache 1 2 2 3 4 3 4 5
		value 1 6 2 5 7 3 5 6
		
	*/
	
	
	for (int i=1;i<n;i++)
	{
		int max = 0;
		for (int j=i-1; j>=0; j--)
		{
			if (val[j] < val[i])
			{
				if (max < cache[j]){
					max = cache[j];
				}
			}
		}
		cache[i] = max + 1;
	}
	
	printf("%d\n",max_(n));
	
	return 0;
}
