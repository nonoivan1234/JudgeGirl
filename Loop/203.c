#include<stdio.h>
#include<stdlib.h>
int min(int a, int b) {return a < b ? a : b;}
int max(int a, int b) {return a > b ? a : b;}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int main(){
    int X, Y, x[2], y[2], dx[2], dy[2], s;
    scanf("%d %d", &X, &Y);
    for(int i = 0; i < 2; i++)  scanf("%d %d", &x[i], &y[i]);
    for(int i = 0; i < 2; i++)  scanf("%d %d", &dx[i], &dy[i]);
    scanf("%d", &s);

    while(s--){
        for(int i = 0; i < 2; i++){
            x[i] += dx[i];
            y[i] += dy[i];
            if(x[i] == 1 || x[i] == X)  dx[i] *= -1;
            if(y[i] == 1 || y[i] == Y)  dy[i] *= -1;
        }

        if(x[0] == x[1] && y[0] == y[1]){
            swap(&dx[0], &dx[1]);
            swap(&dy[0], &dy[1]);
            swap(&x[0], &x[1]);
            swap(&y[0], &y[1]);
        }
    } 

    printf("%d\n%d\n", x[0], y[0]);
    printf("%d\n%d\n", x[1], y[1]);

    return 0;
}