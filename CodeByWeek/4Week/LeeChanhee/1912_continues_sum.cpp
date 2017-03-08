#include <iostream>
using namespace std;


int main(){
	
	int n;
	
	int input_num;		// input 시키는 변수 
	int sum = 0;		// 부분 합을 계산 하는 변수 
	int min = 1000;		// 부분 합 들 중에 가장 최소 값을 저장하는 변수 
	int ret = -1001;		// 부분 합 들을 연산하여 가장 최대가 되는 값을 저장하는 변수 
	
	cin >> n;
	

	while(n--){
		
		cin >> input_num;		 
		sum += input_num;		// 부분 합 계산 
		
		if (ret < input_num){
			ret = input_num;
		}
		
		// 부분 합 중에서 최소 값을 갱신 
		if (min > sum){
			min = sum;
		}
		
		
		
		if (min < 0){
			if (sum == min ) {
				// pass
			}
			else {
				if (ret < sum - min) {
					ret = sum - min;
				} 
			}
		}
		
		if(ret < sum){
			ret = sum;
		}
		
	}
	
	cout << ret << endl;
	
	return 0;
}
