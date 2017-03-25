#include <stdio.h>
#include <string.h>

char WORD[21];
int number;
int prime[1041];

int change(char a)
{
	if (a >= 'a')
	{
		return (int)(a-'a'+1);	
	}
	else
	{
		return (int)(a-'A'+ 27);	
	}
	
}

void makePrime()
{
	for (int i=1;i<1041;i++){
		prime[i] = 1;	// 1 이 소수다. 
	}
		
	for (int i=2;i<33;i++)
	{
		
		if (prime[i])
		{
			for (int j=i*i;j<=1040;j+=i){
				prime[j] = 0;
			}
		}
	}
}

void input()
{
	number = 0;
	scanf("%s",WORD);
	for (int i=0;i<strlen(WORD);i++)
	{
		number += change(WORD[i]);
	}
}

void isPrime()
{
	
	if (prime[number])
		printf("It is a prime word.\n");
	else
		printf("It is not a prime word.\n");
}

int main()
{
	input();
	makePrime();
	isPrime();
	
	
	
	return 0;
}
