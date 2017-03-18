#include <stdio.h>

int table[502][502];
int cache[502][502];
int maximum = 0;


int solve(int x, int y)
{
	int& ret = cache[x][y];
	if (ret != 0){
		return ret;
	}
	
	
	int max = 0;
	int n;
	if (table[x][y] < table[x+1][y]){
		n = solve(x+1,y);
		if (max < n){
			max = n;
		}
	}
	if (table[x][y] < table[x][y+1]){
		n = solve(x,y+1);
		if (max < n){
			max = n;
		}
	}
	if (table[x][y] < table[x-1][y]){
		n = solve(x-1,y);
		if (max < n){
			max = n;
		}
	}
	if (table[x][y] < table[x][y-1]){
		n = solve(x,y-1);
		if (max < n){
			max = n;
		}
	}
	
	ret += max+1;		
	
	if (ret == 0){
		ret = 1;
	}
	
	if (maximum < ret){
		maximum = ret;
	}

	return ret;	
}

int main()
{
	int n;
	scanf("%d",&n);
	
	for (int i=0; i<=n+1 ; i++){
		for (int j=0;j<=n+1;j++){
			cache[i][j] = 0;
			
			int& ret = table[i][j];
			if (i==0 || j==0 || i == n+1 || j == n+1){
				ret = -1;
			}
			else{
				scanf("%d",&ret);	
			}
		}
	}
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			solve(i,j);
		}
	}
	
	
	printf("%d\n",maximum);
	
	return 0;
}
