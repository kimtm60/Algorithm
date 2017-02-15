#include<iostream>

using namespace std;

int quad[64][64]; //배열이름 array로 하면 오류남

void divide(int x, int y, int size) {
	char start = quad[x][y];
	bool AllSame = true;

	for (int a = x; a < x + size; a++) {
		for (int b = y; b < y + size; b++) {
			if (quad[a][b] != start) {
				AllSame = false;
				break;
			}
		}
		if (!AllSame)
			break;
	}
	if (AllSame) {
		cout << start;
	}
	else {
		int half = size / 2;
		cout << '(';
		divide(x, y, half);  //왼쪽위
		divide(x, y + half, half); //오른쪽위
		divide(x + half, y, half); //왼쪽아래
		divide(x + half, y + half, half); //오른 쪽 아래
		cout << ')';
	}


}

int main() {
	int N;
	cin >> N; //N의 범위는 64까지
	char num;  
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num; //0,1입력
			quad[i][j] = num;
		}
	}

	divide(0, 0, N); //array[0][0]부터
}