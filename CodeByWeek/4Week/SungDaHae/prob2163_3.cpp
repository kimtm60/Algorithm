#include <iostream>

using namespace std;

int pieceResult[301][301];

int chocoPiece(int a, int b){
  if(a<b){
    return chocoPiece(b,a);
  }else if(pieceResult[a][b]!=-1){
    return pieceResult[a][b];
  }else if(a==2 && b!=2){
    return 1;
  }else if(a==1){
    return 0;
  }else if(a%2==0){
    return pieceResult[a][b] = (1+2*chocoPiece(a/2,b));
  }else{
    return pieceResult[a][b] = (1+ chocoPiece((a/2),b)+chocoPiece((a/2+1),b));
  }
}

int main(){
  int n, m;

  cin >> n;
  cin >> m;

  //memset(pieceResult, -1, sizeof(pieceResult));
  for(int i=0;i<301;i++){
    for(int j=0;j<301;j++){
      pieceResult[i][j]=-1;
    }
  }
  cout << chocoPiece(n,m) << endl;

  return 0;
}
