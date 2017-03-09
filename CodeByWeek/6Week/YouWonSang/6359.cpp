#include <iostream>
#include <algorithm>

int t, n;

void input(){
	std::ios_base::sync_with_stdio(false);
	std::cin >> t;
}

void solve(){
	std::cin >> n;
	int isOpen[101];
	std::fill_n(isOpen, 101, 0);
	for(int i = 2; i <= n; ++i){
		for(int j = 1; j <= n/i; ++j){
			++isOpen[i*j];
		}
	}
	int ret = 0;
	for(int i = 1; i <= n; ++i){
		if(isOpen[i]%2){
			++ret;
		}
	}
	std::cout << n-ret << std::endl;
}

int main(){
	input();
	for(int i = 0; i < t; ++i)
		solve();
	return 0;
}
