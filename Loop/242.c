#include<stdio.h>
#include<stdlib.h>
int min(int a, int b) {return a < b ? a : b;}
int max(int a, int b) {return a > b ? a : b;}
#define N 65536
long long px[N], py[N], ind;

inline int inside(int x, int y){
    for(int i = 0; i < ind; i++){
        if(px[i] == x && py[i] == y) return 1;
    }

    return 0;
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        long long x[3], y[3], r[3];
        for(int i = 0; i < 3; i++){
            scanf("%lld %lld %lld", &x[i], &y[i], &r[i]);
        }

        ind = 0;
        int cnt = 0;

        for(int i = 0; i < 3; i++){
            for(long long tx = x[i] - r[i]; tx <= x[i] + r[i]; tx++){
                for(long long ty = y[i] - r[i]; ty <= y[i] + r[i]; ty++){
                    if(inside(tx, ty)) continue;

                    px[ind] = tx, py[ind] = ty, ind++;
                    int num = 0;

                    for(int k = 0; k < 3; k++)
                        if((tx - x[k]) * (tx - x[k]) + (ty - y[k]) * (ty - y[k]) <= r[k] * r[k]) 
                            num++;

                    if(num % 2) cnt++;
                }
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}