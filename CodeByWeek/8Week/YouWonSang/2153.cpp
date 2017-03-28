#include <iostream>
#include <cmath>

std::string word;
int sum;

void input(){
	std::ios_base::sync_with_stdio(false);
	std::cin >> word;
}

void solve(){
	for(auto&& ch : word){
		if('a' <= ch && ch <= 'z'){
			sum += (ch - 'a' + 1);
		}
		else if( 'A' <= ch && ch <= 'Z'){
			sum += (ch - 'A' + 27);
		}
	}
}

void isPrime(){
	bool is_prime = false;
	if(sum == 2 || sum == 1){
		is_prime = true;
	}
	else{
		bool gogo = true;
		for(int i = 2; i < sqrt(sum)+1; ++i)
			if(sum % i == 0 && gogo)
				gogo = false;
		if(gogo == true)
			is_prime = true;
	}
	if(is_prime)
		std::cout << "It is a prime word.";
	else
		std::cout << "It is not a prime word.";
}

int main(int argc, const char* argv[]){
	input();
	solve();
	isPrime();
	return 0;
}
