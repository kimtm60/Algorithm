#include <iostream>

int n = 0;
int ret = 0;
int mat[500][500];
int memo[500][500];

void input(){
	std::ios_base::sync_with_stdio(false);
	std::cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j <= i; ++j)
			std::cin >> mat[i][j];
	memo[0][0] = mat[0][0];
	return ;
}

void solve(int depth){
	auto& prev_memo = memo[depth-1];
	auto& curr_mat = mat[depth];
	auto& curr_memo = memo[depth];
	
	curr_memo[0] = prev_memo[0] + curr_mat[0];
	for(int i = 1; i < depth; ++i){
		curr_memo[i] = std::max(prev_memo[i-1], prev_memo[i]) + curr_mat[i];
	}
	curr_memo[depth] = prev_memo[depth-1] + curr_mat[depth];
}


int main(){
	input();
	for(int i = 1; i < n; ++i)
		solve(i);
	for(int i = 0; i < n; ++i)
		ret = std::max(ret, memo[n-1][i]);
	std::cout << ret;
	return 0;
}
