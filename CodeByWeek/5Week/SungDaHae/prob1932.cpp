#include <iostream>
#include <algorithm>

using namespace std;

int triangle[501][501];

int maxVal[501][501];

int calTri(int n,int m){
  if(n==1){
    return triangle[n][1];
  }else if(maxVal[n][m]!=-1){
    return maxVal[n][m];
  }else if(m==1){
    return maxVal[n][m] = calTri(n-1,m)+triangle[n][m];
  }else{
    return maxVal[n][m] = max(calTri(n-1,m-1),calTri(n-1,m))+triangle[n][m];
  }
}

int main(){
  int size;

  int maxNum = -1;

  cin >> size;

  for(int i=1;i<=size;i++){
    for(int j=1;j<=i;j++){
      cin >> triangle[i][j];
      maxVal[i][j]=-1;
    }
  }

  for(int i=1;i<=size;i++){
    maxNum = max(maxNum, calTri(size,i));
  }

  cout << maxNum <<endl;

}
