#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

typedef struct{
	
	int data;
	int x;
	int y;
	
}node;
int n;

int table[502][502];
int cache[502][502];
std::vector<node> list;



bool comp(node a, node b){
	
	return (a.data < b.data);
	
}


void init()
{
	for (int i=0; i<=n+1 ; i++){
		for (int j=0;j<=n+1;j++){
			table[i][j] = 1;
			int& ret = cache[i][j];
			if (i==0 || j==0 || i == n+1 || j == n+1){
				ret = -1;
			}
			else{
				scanf("%d",&ret);
				node node1;
				node1.data = ret;
				node1.x = i;
				node1.y = j;
				
				list.push_back(node1);
				
			}
		}
	}
	
	
	sort(list.begin(),list.end(),comp);
		
}

void solve(){
	
	int max_1 = 0;
	int ret,x,y;
	while(!list.empty())
	{
		ret = list.back().data;
		x = list.back().x;
		y = list.back().y;
		list.pop_back();
		
		int max = 0;
		if (cache[x][y] < cache[x+1][y]){
			if (max < table[x+1][y]){
				max = table[x+1][y];
			}
		}
		if (cache[x][y] < cache[x][y+1]){
			if (max < table[x][y+1]){
				max = table[x][y+1];
			}
		}
		if (cache[x][y] < cache[x-1][y]){
			if (max < table[x-1][y]){
				max = table[x-1][y];
			}
		}
		if (cache[x][y] < cache[x][y-1]){
			if (max < table[x][y-1]){
				max = table[x][y-1];
			}
		}
		
		table[x][y] += max;		
		
		if (max_1 < table[x][y]){
			max_1 = table[x][y];
		}
	}
	
	
	printf("%d\n",max_1);
}


int main()
{
	scanf("%d",&n);
	init();
	solve();
	return 0;
}
