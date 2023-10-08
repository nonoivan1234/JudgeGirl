#include<stdio.h>
#include<stdlib.h>
int min(int a, int b) {return a < b ? a : b;}
int max(int a, int b) {return a > b ? a : b;}

int MIN(int a, int b, int c, int d){
    int min = a;
    if(b < min) min = b;
    if(c < min) min = c;
    if(d < min) min = d;

    return min;
}

int main(){
    int M, N, x[2], y[2], e[2], n[2], f[2];
    scanf("%d %d", &M, &N);
    for(int i = 0; i < 2; i++){
        scanf("%d %d %d %d %d", &x[i], &y[i], &e[i], &n[i], &f[i]);
    }

    int CopyN[2], CopyE[2];
    for(int i = 0; i < 2; i++){
        CopyN[i] = n[i];
        CopyE[i] = e[i];
    }

    int t = 1;
    while(f[0] > 0 || f[1] > 0){
        // Robot 1 move
        if(f[0] > 0 && n[0] > 0){
            y[0] += 1;
            if(y[0] == N)   y[0] = 0;

            n[0] -= 1;
            f[0] -= 1;
        }
        else if(f[0] > 0 && e[0] > 0){
            x[0] += 1;
            if(x[0] == M)   x[0] = 0;
            
            e[0] -= 1;
            f[0] -= 1;
        }
        if(n[0]==0 && e[0]==0 && f[0] > 0){
            n[0] = CopyN[0];
            e[0] = CopyE[0];
        }

        // Robot 2 move
        if(f[1] > 0 && e[1] > 0){
            x[1] += 1;
            if(x[1] == M)   x[1] = 0;
            
            e[1] -= 1;
            f[1] -= 1;
        }
        else if(f[1] > 0 && n[1] > 0){
            y[1] += 1;
            if(y[1] == N)   y[1] = 0;

            n[1] -= 1;
            f[1] -= 1;
        }
        if(n[1]==0 && e[1]==0 && f[1] > 0){
            n[1] = CopyN[1];
            e[1] = CopyE[1];
        }

        // Check if explode
        if(x[0] == x[1] && y[0] == y[1]){
            printf("robots explode at time %d\n", t);

            return 0;
        }

        t++;
    }

    printf("robots will not explode\n");
    return 0;
}