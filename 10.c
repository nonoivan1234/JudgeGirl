#include<stdio.h>

int main(){
    int n, i;
    scanf("%d %d", &n, &i);

    long long ans=1;
    while(i){
        if(i&1) ans*=n;
        n*=n;
        i>>=1;
    }

    printf("%lld\n", ans);
}