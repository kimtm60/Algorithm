#include <iostream>

using namespace std;

int minNumOfCase[100001];

int main(){
  int input;

  cin >> input;

  minNumOfCase[0]=0;
  minNumOfCase[1]=1;
  minNumOfCase[2]=2;
  minNumOfCase[3]=3;

  for(int i=4;i<=input;i++){
    minNumOfCase[i] = i;
    for(int j=2;j*j<=i;j++){
      if(minNumOfCase[i] > (minNumOfCase[(i-j*j)]+1))
          minNumOfCase[i] = (minNumOfCase[(i-j*j)]+1);
    }
  }

  cout << minNumOfCase[input] << endl;

  return 0;
}
