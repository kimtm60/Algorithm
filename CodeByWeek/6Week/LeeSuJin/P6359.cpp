#include <iostream>
using namespace std;
int cell[101] = { 0, }; //���� ���� ��츦 0�̶�� �����Ѵ�.

int main() {
	int TC; //�׽�Ʈ���̽��� ����
	cin >> TC;

	for (int x = 1; x <= TC; x++) { //x�� �׽�Ʈ���̽� ��ȣ
		int n; //���� ���� (5<=n<=100)
		cin >> n;

		for (int i = 1; i <= n; i++) { //ù��° ���忡���� �����ִ� ���� ��� ������ϹǷ� 1
			cell[i] = 1;
		}
		for (int j = 2; j <= n; j++) { //�ι�° ������� ����
			for (int k = j; k <= n; k += j) { 
				if (cell[k] == 1)
					cell[k] = 0;

				else if (cell[k] == 0)
					cell[k] = 1;
			}
		}

		int count = 0; //�����ִ� cell�� ������ ���Ѵ�.
		for (int y = 1; y <= n; y++) {
			if (cell[y] == 1)
				count++;
		}
		cout << count << endl;

	}
}
