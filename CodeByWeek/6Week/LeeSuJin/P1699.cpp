#include <iostream>
using namespace std;

int number[100001] = { 0, }; //number[i]�� ���� �� ���� �ּ� ����

int min(int a, int b) {
	return (a < b) ? a : b;
}

int main() {
	int n; //�ڿ���
	cin >> n;
	for (int i = 0; i <= n; i++) 
		number[i] = i;

	for (int i = 2; i <= n; i++) { //2���� n ������ ������ ���� �ּҰ��� ���ϱ�
		for (int j = 2; j*j <= i; j++)
			number[i] = min(number[i], number[i - j*j] + 1);
	}
	cout << number[n] << endl; //������ ���� �ּҰ��� ���
	return 0;
}

