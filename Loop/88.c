#include<stdio.h>
#include<stdlib.h>
int max(int a, int b){return a>b?a:b;}
int min(int a, int b){return a<b?a:b;}

int main(){
    char a[4], b[4];
    scanf("%s %s", a, b);

    int Acnt = 0, Bcnt = 0;

    for(int i = 0; i < 4; i++)  if(a[i] == b[i]) Acnt ++;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i == j) continue;
            if(a[i] == b[j]) Bcnt ++;
        }
    }

    printf("%dA%dB", Acnt, Bcnt);
    return 0;
}