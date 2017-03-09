#include <iostream>
#include <math.h>
using namespace std;

int memo[100001];


bool isSquare(int n){
	int tmp = (int)sqrt((double)n);
	
	if (tmp*tmp == n)
		return true;
	else
		return false;
	
}

void solve(int n){
	
	int tmp,min;
	
	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 3;
	
	for (int i=4;i<=n;i++){
		
		if (isSquare(i)){
			
			memo[i] = 1;
		}
		
		else{
			
			if (i%2 == 0 && isSquare(i/2)){
				memo[i] = 2;
			}	
			else if (i%3 == 0 && isSquare(i/3)){
				memo[i] = 3;
			}
			else{
				
				min = 100000;
				
				for (int j=(int)sqrt((double)i);j>0;j--) {
					tmp = memo[j*j] + memo[i-j*j];
					if (min > tmp){
						min = tmp;
					}
				}
				
				memo[i] = min;
			}
		}
	}
	cout << memo[n] << endl;
}

int main(){
	
	
	int n;
	cin >> n;
	solve(n);
	
	
	return 0;
}
