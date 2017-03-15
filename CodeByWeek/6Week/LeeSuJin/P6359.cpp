#include <iostream>
using namespace std;
int cell[101] = { 0, }; //방이 닫힌 경우를 0이라고 설정한다.

int main() {
	int TC; //테스트케이스의 개수
	cin >> TC;

	for (int x = 1; x <= TC; x++) { //x는 테스트케이스 번호
		int n; //방의 개수 (5<=n<=100)
		cin >> n;

		for (int i = 1; i <= n; i++) { //첫번째 라운드에서는 닫혀있는 문을 모두 열어야하므로 1
			cell[i] = 1;
		}
		for (int j = 2; j <= n; j++) { //두번째 라운드부터 시작
			for (int k = j; k <= n; k += j) { 
				if (cell[k] == 1)
					cell[k] = 0;

				else if (cell[k] == 0)
					cell[k] = 1;
			}
		}

		int count = 0; //열려있는 cell의 개수를 구한다.
		for (int y = 1; y <= n; y++) {
			if (cell[y] == 1)
				count++;
		}
		cout << count << endl;

	}
}
