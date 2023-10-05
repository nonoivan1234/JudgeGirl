#include<stdio.h>
#include<stdlib.h>
int max(int a, int b){return a>b?a:b;}
int min(int a, int b){return a<b?a:b;}

int main(){
    int n;
    scanf("%d", &n);

    int mod0 = 0, mod1 = 0, mod2 = 0;

    int tmp;
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);
        if(tmp % 3 == 0) mod0 ++;
        else if(tmp % 3 == 1) mod1 ++;
        else mod2 ++;
    }

    printf("%d %d %d", mod0, mod1, mod2);

    return 0;
}