#include <stdio.h>
#include <stdbool.h>
#define MAX 64

int N, input[MAX][MAX];
void quadTree(int x, int y, int size){
        int i, j;
        int cur = input[y][x];
        bool flag = true;
        for(i = y; (i<y + size)&& flag; i++)
            for(j = x; (j<x + size)&&flag; j++)
                if(cur !=input[i][j])flag = false;

        if(flag) printf("%d", cur);

        else{
            printf("(");
            quadTree(x, y, size / 2);
            quadTree(x + size / 2, y, size / 2);
            quadTree(x, y + size / 2, size /2);
            quadTree(x + size / 2, y + size / 2, size /2);
            printf(")");
        }


               }
int main()
{
    int i, j;
   scanf("%d",&N);
   for(i = 0; i < N; i++)
      for(j = 0; j < N; j++)
        scanf("%d", &input[i][j]);
   quadTree(0, 0, N);
}
