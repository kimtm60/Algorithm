#include <iostream>
#include <cmath>

int n ;
int sq[32769];

void input(){
	for(int i = 0; i < 32769; ++i){
		sq[i] = i*i;
	}
}

void solve(){
	while(1){
		std::cin >> n;
		if(n == 0){
			return;
		}
		int count = 0;
		int upper = sqrt(n) + 1;
		for(int i = 0; i < upper; ++i)
			for(int j = i; j < upper; ++j)
				for(int x = j; x < upper; ++x)
					for(int y = x; y < upper; ++y)
						if(n == sq[i] + sq[j] + sq[x] + sq[y])
							++count;
		
		std::cout << count << std::endl;
	}
}

int main(int argc, const char* argv[]){
	input();
	solve();
	return 0;
}
