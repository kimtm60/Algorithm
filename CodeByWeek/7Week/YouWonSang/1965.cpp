#include <iostream>
#include <map>
#include <array>

/*
 box[idx] = 인덱스에 대한 사이즈
 memo[idx] = 인덱스까지의 최대 박스 카운트
 */

auto box = std::array<int, 1001>();
auto memo = std::array<int, 1001>();

int n = 0;
int output = 1;

void input(){
	std::ios_base::sync_with_stdio(false);
	std::cin >> n;
	
	std::fill(box.begin(), box.end(), 0);
	std::fill(memo.begin(), memo.end(), 1);
	
	auto begin = box.begin();
	for(int i = 0; i < n; ++i && ++begin)
		std::cin >> *begin;
}

void solve(int idx){
	int size = box[idx];
	int count = memo[idx];
	for(int i = 0; i < idx; ++i){
		if(size > box[i]){
			count = std::max(count, memo[i]+1);
		}
	}
	memo[idx] = count;
	output = std::max(output, count);
}

int main(){
	input();
	for(int i = 1; i <= n; ++i){
		solve(i);
	}
	std::cout << output;
	return 0;
}
