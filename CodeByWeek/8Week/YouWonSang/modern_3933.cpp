#include <iostream>
#include <functional>
#include <cmath>

#define EXP 2
#define MAX_DEGREE 15

constexpr auto pow(int base, int exp) -> int {
	if(exp == 0){ return 1; }
	return base * pow(base, exp-1);
}

auto main(int argc, const char* argv[]) -> int {
	
	constexpr int max = pow(EXP, MAX_DEGREE);
	int sq[max]; int cnt = 0;
	for(int i = 0; i < max; ++i) { sq[i] = i*i; }


	/* recursive lambda function */
	std::function<void(int,int,int)> recur =
	[&](auto s, auto l, auto r) ->void {
		if(l < 0) { return; }
		if(r == 0) { ++cnt; return; }
		
		for(int i = s; i >= 0; --i)
			if(r >= sq[i])
				recur(i, l-1, r-sq[i]);
	};
	
	int n = 0;
	while((std::cin >> n) && n) {
		cnt = 0;
		recur(sqrt(n)+1, 4, n);
		std::cout << cnt << std::endl;
	}
	
	return 0;
}
