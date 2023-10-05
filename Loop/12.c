#include<stdio.h>
#include<stdlib.h>
int max(int a, int b){return a>b?a:b;}
int min(int a, int b){return a<b?a:b;}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i < n; i++)  printf("%d\n", i);
    for(int i = n; i > 0; i--)  printf("%d\n", i);

    return 0;
}