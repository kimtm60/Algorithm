#include <stdio.h>
#define MOD 1000000

int dayy[1001][3];

void solve(int n){
	
	unsigned int sum = 0;
	dayy[0][0] = 1;
	dayy[0][1] = 0;
	dayy[0][2] = 0;
	
	for (int i=1;i<=n;i++) {
		
		dayy[i][0] += (dayy[i-1][0] + dayy[i-1][1] + dayy[i-1][2])%MOD;
		dayy[i][1] += dayy[i-1][0]%MOD;
		dayy[i][2] += dayy[i-1][1]%MOD;
		
	}
	
	sum += (dayy[n][0] + dayy[n][1] + dayy[n][2])%MOD;
	
	
	for (int i=1;i<=n;i++) {
		
		for (int j=0;j<3;j++) {
			for (int k=0; k<3; k++) {
				
				sum += ((unsigned int)dayy[i-1][j] * dayy[n-i][k]) % MOD;
				sum %= MOD;
			}
		}
		
	}
	
	printf("%d\n",sum);
	
}

int main(){
	
	int n;
	scanf("%d",&n);
	
	solve(n);
	
	return 0;
}

