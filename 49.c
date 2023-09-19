#include<stdio.h>
const int INF = 1e4+5;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int sum[m], mx[m], mn[m];
    for(int i = 0; i < m; i++){
        sum[i] = 0;
        mx[i] = -INF;
        mn[i] = INF;
    }

    int tmp;
    for(int i=0;i<n;i++){
        scanf("%d", &tmp);
        sum[tmp%m] += tmp;
        if(tmp > mx[tmp%m]) mx[tmp%m] = tmp;
        if(tmp < mn[tmp%m]) mn[tmp%m] = tmp;
    }

    for(int i = 0; i < m; i++){
        printf("%d %d %d\n", sum[i], mx[i], mn[i]);
    }
}