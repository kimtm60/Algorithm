/*
 * debugging log
 * printf->watch
 */
//#define YWS_DEBUG

#if defined YWS_DEBUG
#define watch printf
#else
#define watch
#endif

/*
 * [problem solving]
 * date: 2017.02.14
 * author: wonsang you
 * url: https://www.acmicpc.net/problem/1992
 * blog: https://yws6909.github.io/
 */

#include <iostream>
#include <array>

namespace yws{
	/* variable */
	auto image = std::array<std::array<bool,64>,64>();
	int N;
	int dx[] = {0, 0, 1, 1};
	int dy[] = {0, 1, 0, 1};
	
	/* function */
	int input_func();
	void solve_func(int, int, int);
	int is_same(int, int, int);
}

int main(int argc, const char* argv[]){
	yws::solve_func(0, 0, yws::input_func());
	return 0;
}


int yws::input_func(){
	std::ios_base::sync_with_stdio(false);
	std::cin >> N;
	std::cin.get();
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			image[i][j] = std::cin.get() - '0';
		}
		std::cin.get();
	}
	return N;
}

void yws::solve_func(int SX, int SY, int N){
	int result = is_same(SX, SY, N);
	if(result){
		std::cout << result-1;
	}
	else{
		N/=2;
		std::cout << "(";
		for(int i = 0; i < 4; ++i){
			solve_func(SX+(N*dx[i]), SY+(N*dy[i]), N);
		}
		std::cout << ")";
	}
}

int yws::is_same(int SX, int SY, int N){
	int match = image[SX][SY];
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(match != image[SX+i][SY+j]){
				return 0;
			}
		}
	}
	return match+1;
}
