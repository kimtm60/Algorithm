#include <stdio.h>
#include <string.h>

int n;
char pattern[101];

char sub_str1[101];
char sub_str2[101];
int len_str1,len_str2;

void analyse()
{
	int idx;
	for (int i=0;i<strlen(pattern);i++)
	{
		if (pattern[i] == '*'){
			idx = i;
			sub_str1[i] = '\0';
			break;
		}
		else{
			sub_str1[i] = pattern[i];
		}
	}
	int j=0;
	for (int i=idx+1;i<strlen(pattern);i++){
		sub_str2[j] = pattern[i];
		j++;
	}
	sub_str2[j] = '\0';
	
	len_str1 = strlen(sub_str1);
	len_str2 = strlen(sub_str2);
	
}


void decision()
{
	char str[101];
	
	scanf("%s",str);
	
	int len = strlen(str);
	
	if (len < len_str1 + len_str2){
		printf("NE\n");
		return;
	}
	
	for (int i=0;i<len_str1;i++){
		if (sub_str1[i] != str[i]){
			printf("NE\n");
			return;
		}
	}
	

	for (int i=0;i<len_str2;i++){
		if (sub_str2[i] != str[len-len_str2+i]){
			printf("NE\n");
			return;
		}
	}
	
	printf("DA\n");
}

int main()
{
	scanf("%d",&n);
	scanf("%s",pattern);
	
	analyse();
	
	while(n--)
	{
		decision();
	}
	
	return 0;
}

