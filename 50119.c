#include<stdio.h>

int main(){
    int x, a, b, c;
    int y, d, e, f;
    int N;
    scanf("%d %d %d %d", &x, &a, &b, &c);
    scanf("%d %d %d %d", &y, &d, &e, &f);
    scanf("%d", &N);

    while(N--){
        int cnt=1;
        while(x%3 == y%3){
            x = (a*x + b)%c;
            y = (d*y + e)%f;
            cnt++;
        }

        // 0:paper, 1:scissors, 2:stone
        if (x%3==0){
            if (y%3==1) printf("%d %d\n", 1, cnt);
            else if (y%3==2) printf("%d %d\n", 0, cnt);
        }
        else if (x%3==1){
            if (y%3==0) printf("%d %d\n", 0, cnt);
            else if (y%3==2) printf("%d %d\n", 1, cnt);
        }
        else if (x%3==2){
            if (y%3==0) printf("%d %d\n", 1, cnt);
            else if (y%3==1) printf("%d %d\n", 0, cnt);
        }

        x = (a*x + b)%c;
        y = (d*y + e)%f;
    }
}