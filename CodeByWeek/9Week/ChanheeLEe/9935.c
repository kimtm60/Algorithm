#include <stdio.h>
#include <string.h>
#define MAX 1000001

char str1[MAX];
char bomb[37];
char str2[MAX];
int len_bomb, len_str1;


void solve(){
	
	int i,j=0;
	int k;
	int flag = 0;
	for (i=0; i<len_str1;i++)
	{
		
		str2[j] = str1[i];
		
		if (str2[j] == bomb[len_bomb-1]){
			
			for (k=0 ; k<len_bomb ;k++){
				if (str2[j-k] == bomb[len_bomb-k-1]){
					flag = 1;
				}
				else{
					flag = 0;
					break;
				}
			}
		}
		
		
		if (flag == 1)
		{
			j -= len_bomb;
			flag = 0;
		}
		
		j++;
		
	}
	str2[j] = '\0';
	
	if (j==0)
		printf("FRULA\n");
	else
		printf("%s\n",str2);
}

int main()
{
	scanf("%s",str1);
	scanf("%s",bomb);
	len_bomb = strlen(bomb);
	len_str1 = strlen(str1);	
	solve();
	
	
	return 0;
}
