#include <iostream>
using namespace std;
int  num[100001], sum[100001], Contimaxsum = 0;


int main() {

	int size;
	cin >> size;

	for (int i = 0; i < size; i++) {
		cin >> num[i];
	}

	for (int i = 1; i <= size; i++) {
		if (sum[i - 1] + num[i] > num[i]) {
			sum[i] = sum[i - 1] + num[i];
		}
		else {
			sum[i] = num[i];
		}
	}
	Contimaxsum = sum[1];
	for (int i = 2; i <= size; i++) {
		if (Contimaxsum < sum[i])
			Contimaxsum = sum[i];
	}

	cout << Contimaxsum;
}
