/*
 * [problem solving]
 * created by youwonsang
 * 2017.02.04
 * no.10448 / 유레카 이론 (Eureka theory)
 * https://www.acmicpc.net/problem/10448
 */

#include <iostream>
#include <cmath>

/*
 입력을 d 라고 놓고 (3 <= d <= 1000)
 임의의 정수 a,b,c 에 대하여 각각의 삼각수는
	T[a] = a(a+1)/2
	T[b] = b(b+1)/2
	T[c] = c(c+1)/2
 
 T[a] + T[b] + T[c] = d 를 만족하는 a,b,c 가 존재해야한다.
 => a(a+1)/2 + b(b+1)/2 + c(c+1)/2 = d
 
 조합을 탐색할때 중복계산되는 부분이 있기때문에 일반화하여 이를 미리 계산해두는 것이 좋다.
 다행히도 입력이 크지않다. 전처리 범위의 상한을 계산하여 횟수를 줄이며,
 곱셈연산과 나눗셈연산은 cpu 로 처리할때 생각보다 많은 시간이 소요되므로
 곱셈과 나눗셈을 덧셈과 뺄셈으로 만드는것이 좋다.
 
 양변에 2를 곱해준다. 이유는 전처리시 곱셈연산을 줄이기위함.
 => a(a+1) + b(b+1) + c(c+1) = 2d
	P[a] = a(a+1) = T[a]*2
	P[b] = b(b+1) = T[b]*2
	P[c] = c(c+1) = T[c]*2
 
 이때 max(a,b,c) < sqrt(2d-4) 가 된다. (a=1, b=1, c=? 라고 가정했을때의 상한을 구함)
 d 의 최대값은 1000 이므로 max(a,b,c) < sqrt(1996) 약 45.xx 
 그러므로 임의의 x (1 <= x <= 45) 에 대해서 P[x] = f(x) = x(x+1) 을 미리 계산해둔다.
 
 f(x) - f(x-1)
 = x(x+1) - (x-1)x
 => 2x
 => x + x
 
 즉, f(x) = f(x-1) + x + x (운이 좋게도 모든 곱셈이 덧셈으로 바뀌었다.)
 x = 1 일때 f(1) = f(0) + 1 + 1 = 2 이므로 f(0) = 0 으로 초기화한다.
 
 이 유레카 이론에 사용되는 삼각수의 조합은 순서와 상관이 없기때문에
 a <= b <= c 를 유지하면서 brute-force 를 하면 찾는 비용을 최소화할 수 있다.
 P[a] + P[b] + P[c] = d 를 만족하는 a,b,c 를 찾으면 서칭을 중지한후 결과를 출력한다.
 */

using index_t = unsigned int;
// index 를 위해 사용하는 타입은 부호가 없는 정수

int P[45];
// P: preprocess

void solve(int input){
	
	input *= 2;
	int limit = std::sqrt(input) + 1;
	auto result = false;
	
	for(index_t a = 1; (a < limit) && (!result); ++a)
		for(index_t b = a; (b < limit) && (!result); ++b)
			for(index_t c = b; (c < limit) && (!result); ++c)
				if(input == P[a] + P[b] + P[c])
					result = true;
	
	printf("%d\n", result);
}

int num = 0;
int input = 0;

int main(int argc, const char* argv[]){
	
	scanf("%d", &num);
	
	P[0] = 0;
	for(int i = 1; i < 45; ++i)
		P[i] = P[i-1] + i + i;
	
	for(int i = 0; i < num; ++i){
		scanf("%d", &input);
		solve(input);
	}
	
	return 0;
}
