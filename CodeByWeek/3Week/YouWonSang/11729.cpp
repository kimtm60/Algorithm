/*
 * debugging log
 * printf->watch
 */
#define YWS_DEBUG

#if defined YWS_DEBUG
#define watch printf
#else
#define watch
#endif

/*
 * [problem solving]
 * date: 2017.02.14
 * author: wonsang you
 * url: https://www.acmicpc.net/problem/11729
 * blog: https://yws6909.github.io/
 */

#include <iostream>

namespace yws{
	/* variable */
	int K, A, B;
	
	/* function */
	void input_func();
	int counting_func(int);
	void solve_func(int, int, int);
	void output_func();
}

int main(int argc, const char* argv[]){
	yws::input_func();
	std::cout << yws::counting_func(yws::K) << "\n";
	yws::solve_func(yws::K, 1, 3);
	
	return 0;
}


void yws::input_func(){
	std::ios_base::sync_with_stdio(false);
	std::cin >> K;
	A = 2;
	B = 3;
}

int yws::counting_func(int n){
	if(n == 1){
		return 1;
	}
	int ret = 0;
	ret += counting_func(n-1)*2 + 1;
	return ret;
}

void yws::solve_func(int n, int s, int d){
	if(n == 0)
		return;
	int temp = 6 - (s + d);
	solve_func(n-1, s, temp);
	std::cout << s << " " << d << "\n";
	solve_func(n-1, temp, d);
}
