#include <iostream>
#include <cmath>

int n = 0;
int limit = 0;
int square[350];
int memo[100001];

void input(){
	std::ios_base::sync_with_stdio(false);
	std::cin >> n ;
	limit = std::sqrt(100001);
	for(int i = 0; i < limit; ++i){
		square[i] = i*i;
		if(square[i] > n){
			limit = i;
			break;
		}
	}
	std::fill_n(memo, 100001, 100000);
	memo[0] = 0;
}

void solve(int num){
    	auto& ret = memo[num];
	for(int i = 1; i < limit; ++i){
		if((num-square[i]) >= 0){
			ret = std::min(ret, memo[num-square[i]] + 1);
		}
		else{
			break;
		}
	}
	return ;
}

int main(){
	input();
	for(int i = 1; i <= n; ++i){
		solve(i);
	}
	std::cout << memo[n];
	return 0;
}
