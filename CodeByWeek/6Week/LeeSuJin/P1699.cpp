#include <iostream>
using namespace std;

int number[100001] = { 0, }; //number[i]는 제곱 수 항의 최소 개수

int min(int a, int b) {
	return (a < b) ? a : b;
}

int main() {
	int n; //자연수
	cin >> n;
	for (int i = 0; i <= n; i++) 
		number[i] = i;

	for (int i = 2; i <= n; i++) { //2부터 n 까지의 제곱수 항의 최소개수 구하기
		for (int j = 2; j*j <= i; j++)
			number[i] = min(number[i], number[i - j*j] + 1);
	}
	cout << number[n] << endl; //제곱수 항의 최소개수 출력
	return 0;
}

