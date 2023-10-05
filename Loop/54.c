#include<stdio.h>
#include<stdlib.h>
int max(int a, int b){return a>b?a:b;}
int min(int a, int b){return a<b?a:b;}
const int N = 1e6+5;

int main(){
    char a[N], b[N];
    scanf("%s %s", a, b);

    int n = strlen(a), m = strlen(b), cnt = 0;

    for(int i = 0; i + n <= m; i++){
        int flag = 1;
        for(int j = 0; j < n; j++){
            if(a[j] != b[i+j]){
                flag = 0;
                break;
            }
        }

        if(flag)    cnt ++;
    }

    printf("%d", cnt);

    return 0;
}