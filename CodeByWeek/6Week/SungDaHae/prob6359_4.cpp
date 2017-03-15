#include <iostream>

using namespace std;

int main(){
  int openDoorNums[101];
  int squareArr[10]={1,4,9,16,25,36,49,64,81,100};

  int caseNums;
  int temp=1;
  int squareIndex = 1;

  openDoorNums[0] = 0;
  openDoorNums[1] = 1;

  cin >> caseNums;

  for(int i=2; i<=100; i++){
      if(squareArr[squareIndex]==i){
        temp++;
        squareIndex++;
      }
      openDoorNums[i]=temp;
  }

  for(int i=0;i<caseNums;i++){
    cin >> temp;
    cout << openDoorNums[temp] << endl;
  }

  return 0;
}
