#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to)
{
    if(n==1) printf("%c %c\n", from, to);
    else{
        hanoi_tower(n-1, from, to, tmp);
        printf("%c %c\n", from, to);
        hanoi_tower(n-1, tmp, from, to);
    }
}

int main()
{
    int n, i, sum=1;
    scanf("%d",&n);
    for(i=0; i < n; i++)
        sum = sum*2;
    printf("%d\n",sum-1);
    hanoi_tower(n,'1','2','3');
    return 0;
}
