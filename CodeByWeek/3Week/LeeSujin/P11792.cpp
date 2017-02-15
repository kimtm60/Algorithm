#include<iostream>
using namespace std;

void hanoi_tower(int n, char from, char tmp, char to) {
	if (n == 1) //원판의 개수가 한 개인 경우 그냥 from에서 to로 바로 옮기면 된다.
		cout << from << " " << to << endl;
	else { //원판의 개수가 2개이상인 경우
		hanoi_tower(n - 1, from, to, tmp);
		cout << from << " " << to << endl;
		hanoi_tower(n - 1, tmp, from, to);
	}
}
//첫 번째 장대에서 세 번째 장대로 옮기기
int main() {
	int n; //원판의 개수
	int k = 1; 
	cin >> n;
	
	//n개의 원판을 이동하는 횟수: 2^n-1 
	//a1 = 1 ,a2=3, a3=7...
	for (int i = 0; i < n; i++)
		k *= 2; 
	cout << k - 1 << endl; //옮긴 횟수
	hanoi_tower(n, '1', '2', '3'); //원판의 갯수, 장대1, 장대2, 장대3

}