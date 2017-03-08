#include <iostream>
using namespace std;


int cutting(int n, int m){
	
	int tmp;
	if (n < m)
	{
		tmp = n;
		n = m;
		m = tmp;
	}
	
	if (n==1 && m==1)
		return 0;
	else if (n==2 && m==1)
		return 1;
	else if (n==2 && m==2)
		return 3;
	
	return (1 + cutting(n/2,m) + cutting(n-n/2,m));
	
}

int main(){
	
	int n,m;
	cin >> n >> m;
		
	cout << cutting(n,m) << endl;
	
	return 0;
}
