#include <stdio.h>
#include <string.h>
int main(){
	
	int test , n;
	int cnt;
	int room[100];
	scanf("%d",&test);
	
	while(test--) {
		scanf("%d",&n);
		
		// 처음에 모두 열어 둔다 
		for (int i=0; i<n;i++){
			room[i] = 1;
		}
		
		cnt = 0;
		
		for(int i=1;i<n;i++){
			for(int j=i ; j<n ;j+=(i+1)){
				
				if (room[j] == 1){
					room[j] = 0;
				}
				else{
					room[j] = 1;
				}
			}
		}
		
		for(int i=0;i<n;i++){
			if (room[i] == 1)
				cnt++;
		}
		printf("%d\n",cnt);
	}
	
	return 0;
}
