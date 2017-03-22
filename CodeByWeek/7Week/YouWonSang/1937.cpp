#include <iostream>

int n;
int bamboo[502][502];
int memo[502][502];
int result = -1;

enum drct { left = 0, down, right, up };
int dx[4] = {  -1,  0,  1,  0 };
int dy[4] = {   0, -1,  0,  1 };

void input(){
	std::ios_base::sync_with_stdio(false);
	std::cin >> n;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			std::cin >> bamboo[i][j];
			memo[i][j] = 0;
		}
	}
}

int solve(int x, int y, int s){
	std::cout << x << " " << y << " " << s << std::endl;
	int& ret = memo[x][y];
	if(ret != 0)
		return ret;

	int& base = bamboo[x][y];
	for(int i = left; i <= up; ++i){
		int x2 = x + dx[i];
		int y2 = y + dy[i];
		if(base < bamboo[x2][y2]){
			ret = std::max(ret, solve(x2, y2, s+1));
		}
	}
	return ret;
}

int main(int argc, const char* argv[]){
	input();
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			result = std::max(result, solve(i,j,1));
		}
	}
	
	std::cout << result;
	return 0;
}
