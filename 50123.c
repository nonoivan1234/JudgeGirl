#include<stdio.h>

void print(int n, int arr[][n]){
    // printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            printf("%d ", arr[i][j]);
        }
        printf("%d", arr[i][n-1]);
        printf("\n");
    }
}

int main(){
    int n, K, X, Y;
    scanf("%d %d %d %d", &n, &K, &X, &Y);

    int arr[n][n];
    for(int i=0;i<n;i++)    for(int j=0;j<n;j++)    arr[i][j] = 0;

    int x = X, y = Y, k = K;
    arr[x][y] = k;
    while(k>1){
        x = (x+1)%n;
        y = (y-1+n)%n;
        if(arr[x][y] == 0)
            arr[x][y] = --k;
        else{
            x = (x-1+n)%n;
            y = (y+1)%n;
            while(arr[x][y]!=0 && k>1){
                x = (x-1+n)%n;
            }
            arr[x][y] = --k;
        }
    }

    x = X, y = Y, k = K;
    while(k<n*n){
        x = (x-1+n)%n;
        y = (y+1)%n;
        if(arr[x][y] == 0)
            arr[x][y] = ++k;
        else{
            x = (x+1)%n;
            y = (y-1+n)%n;
            while(arr[x][y]!=0 && k<n*n){
                x = (x+1)%n;
            }
            arr[x][y] = ++k;
        }
    }

    print(n, arr);
}