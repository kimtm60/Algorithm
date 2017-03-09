#include <iostream>

/*
 지각을 두번이상
 결석을 세번 연속으로한 사람
 
 N <= 1000
 OUTPUT = RESULT % 1'000'000
 */

int n = 0;
int memo[1001][3][4];
/*
 첫번째 인덱스 = n번째 출석까지
 두번째 인덱스 = 지각 횟수 [3]은 2번이상
 세번째 인덱스 = 연속으로 결석한 횟수 3번이상이면 노개근
 */

void input(){
	std::ios_base::sync_with_stdio(false);
	std::cin >> n;
	memo[1][0][0] = 1;
	memo[1][1][0] = 1;
	memo[1][0][1] = 1;
	
}

/*
 recursion fomuler
 memo[nth][late][0] = memo[nth-1][late][*] + memo[nth-1][late-1][*]
 memo[nth][late][abs] = memo[nth-1][late][abs-1]
 */

void solve(int nth){
	
	for(int i = 1; i < 2; ++i){
		for(int j = 0; j < 3; ++j){
			 memo[nth][i][0] += memo[nth-1][i-1][j];
			if(memo[nth][i][0] >= 1'000'000){
				memo[nth][i][0] -= 1'000'000;
			}
		}
	}
	
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 3; ++j){
			memo[nth][i][0] += memo[nth-1][i][j];
			if(memo[nth][i][0] >= 1'000'000){
				memo[nth][i][0] -= 1'000'000;
			}
		}
	}
	
	// 연속으로 지각
	for(int i = 0; i < 2; ++i){
		for(int j = 1; j < 3; ++j){
			memo[nth][i][j] += memo[nth-1][i][j-1];
			if(memo[nth][i][j] >= 1'000'000){
				memo[nth][i][0] -= 1'000'000;
			}
		}
	}
}

int main(){
	input();
	for(int i = 2; i <= n; ++i){
		solve(i);
	}
	long long int ret = 0;
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 3; ++j){
			ret += memo[n][i][j];
			if(ret >= 1'000'000){
				ret -= 1'000'000;
			}
		}
	}
	std::cout << ret;
	return 0;
}
