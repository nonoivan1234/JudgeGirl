#include<stdio.h>
#include<stdlib.h>
int min(int a, int b) {return a < b ? a : b;}
int max(int a, int b) {return a > b ? a : b;}

int main(){
    long long special[3], first[3], ans = 0;

    for(int i = 0; i < 3; i++)  scanf("%lld", &special[i]);
    for(int i = 0; i < 3; i++)  scanf("%lld", &first[i]);

    int num;
    while(scanf("%d", &num) != EOF){
        for(int i = 0; i < 3; i++){
            if(num == special[i]) {
                ans += 2000000;
                continue;
            }
        }

        int ok[6];
        for(int i = 0; i < 6; i++)  ok[i] = 0;

        for(int i = 0; i < 3; i++){
            if(num == first[i]) ok[0] = 1;
            if(num%10000000 == first[i]%10000000) ok[1] = 1;
            if(num%1000000 == first[i]%1000000) ok[2] = 1;
            if(num%100000 == first[i]%100000) ok[3] = 1;
            if(num%10000 == first[i]%10000) ok[4] = 1;
            if(num%1000 == first[i]%1000) ok[5] = 1;
        }

        if(ok[0])   ans += 200000;
        else if(ok[1])  ans += 40000;
        else if(ok[2])  ans += 10000;
        else if(ok[3])  ans += 4000;
        else if(ok[4])  ans += 1000;
        else if(ok[5])  ans += 200;
    }

    printf("%lld\n", ans);

    return 0;
}