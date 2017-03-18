#include <iostream>

int cache[1000][1000];
int n,m;
char num[1001];
int result;

void input()
{
	std::ios_base::sync_with_stdio(false);
	std::cin>>n>>m;
	
	for (int i=0;i<n;i++){
		std::cin >> num;
		for (int j=0;j<m;j++){
			cache[i][j] = (int)(num[j] - '0');
			
		}
	}
}

void solve()
{
	result = 0;
	
	for (int i=0;i<n;i++){
		
		for (int j=0;j<m;j++){
			
			if (i>0 && j>0){
				if (cache[i][j] != 0 && cache[i][j] <= cache[i-1][j] &&
				cache[i][j] <= cache[i][j-1] && cache[i][j] <= cache[i-1][j-1])
				{
					cache[i][j] += std::min(std::min(cache[i-1][j],cache[i][j-1]),cache[i-1][j-1]);
				}
			
				
			}
			if (result < cache[i][j]){
					result = cache[i][j];
			}
			
		}
	}
	
	
	
	std::cout << result*result<< std::endl;
}

int main()
{
	input();
	solve();

	return 0;
}
