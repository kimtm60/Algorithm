#include <iostream>
using namespace std;

int max(int x, int y){
	
	if (x > y)
		return x;
	else
		return y;
}

int main(){
	
	int sizeOfTRI;
	
	// 500 X 500 판을 만든다. 
	int matrix[500][500];
	
	cin >> sizeOfTRI;
	
	for (int i=0; i<sizeOfTRI ; i++){
		
		for (int j=0; j<=i; j++){
			
			cin >> matrix[i][j];	
	
			if (i>0){
				
				if (j==0){
					matrix[i][j] += matrix[i-1][j];	
				}
				else{
					matrix[i][j] += max(matrix[i-1][j-1], matrix[i-1][j]);
				}
			}
			
		}
		
	}
	
	
	int maximum = 0;
	for (int i=0; i<sizeOfTRI; i++){
		
		if (maximum < matrix[sizeOfTRI-1][i])
			maximum = matrix[sizeOfTRI-1][i];
		
	}		
	
	cout << maximum << endl;
	
	
	return 0;
}
