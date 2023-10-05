#include<stdio.h>

int main(){
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int a[h][w];
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            scanf("%d", &a[i][j]);
        }
    }

    int mx = 0, len = 2*k-1;
    for(int i=0;i+len<=h;i++){
        for(int j=0;j+len<=w;j++){
            // printf("%d %d\n", i, j);
            int sum = a[i+k-1][j] + a[i+k-1][j+len-1];

            for(int l=1;l<k;l++){
                sum += a[i+k-1+l][j+l] + a[i+k-1-l][j+l];
                // printf("%d %d %d %d\n", i+k-1+l, j+l, i+k-1-l, j+l);
            }

            for(int l=1;l<k-1;l++){
                sum += a[i+k-1+l][j+len-1-l] + a[i+k-1-l][j+len-1-l];
                // printf("%d %d %d %d\n", i+k-1+l, j+len-1-l, i+k-1-l, j+len-1-l);
            }
            if(sum > mx) mx = sum;
        }
    }

    printf("%d\n", mx);
}