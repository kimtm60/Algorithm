#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int size;
  int num;
  int temp=0;
  int result;
  vector<int> inputNums;
  vector<int> resultArr;

  cin >> size;

  inputNums.push_back(-1001);

  for(int i=0;i<size;i++){
    cin >> num;
    //cout << "num" << num << endl;
    inputNums.push_back(num);
  }

  for(int i=1;i<=size;i++){
    if((temp+inputNums[i])<=0){
      if(temp == 0 ){
        resultArr.push_back(inputNums[i]);
        //cout<<"HELLO1 temp:" <<temp <<endl;
      }else{
        resultArr.push_back(temp);
        //cout<<"HELLO2 temp:" <<temp<<endl;
        temp = 0;
      }
    }else if((temp+inputNums[i])<temp){
      resultArr.push_back(temp);
      //cout<<"HELLO3 temp:"<<temp <<endl;
      temp+=inputNums[i];
    }else{
      //cout<<"HELLO4 temp:"<<temp <<endl;
      temp+=inputNums[i];
      if(i==size){
        //cout <<"HELLO5 temp: " <<temp <<endl;
        //cout <<"HELLO5 inputNums: " <<inputNums[i] <<endl;
        //cout <<"HELLO5 i: " <<i <<endl;
        resultArr.push_back(temp);
      }
    }
  }

  //cout << "resultArrSize: " << resultArr.size() <<endl;
  for(int i=0;i<resultArr.size();i++){
    cout << "result: " <<resultArr[i] <<endl;
  }

  result = *max_element(resultArr.begin(), resultArr.end());

  cout << result << endl;

  return 0;
}
