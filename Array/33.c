#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int a[n+2][n+2];
    for(int i=0;i<=n+1;i++) for(int j=0;j<=n+1;j++) a[i][j]=0;
    for(int i=1;i<=n;i++)    for(int j=1;j<=n;j++)    scanf("%d", &a[i][j]);

    int inter=0, Tjunc=0, turn=0, dead=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (a[i][j]){
                int cnt=0;
                if (a[i-1][j])  cnt++;
                if (a[i+1][j])  cnt++;
                if (a[i][j-1])  cnt++;
                if (a[i][j+1])  cnt++;

                if (cnt==4) inter++;
                else if (cnt==3)    Tjunc++;
                else if (cnt==2){
                    if (a[i-1][j] && a[i][j+1]) turn++;
                    else if (a[i-1][j] && a[i][j-1]) turn++;
                    else if (a[i+1][j] && a[i][j-1]) turn++;
                    else if (a[i+1][j] && a[i][j+1]) turn++;
                }
                else if (cnt==1)    dead++;
            }
        }
    }

    printf("%d\n%d\n%d\n%d\n", inter, Tjunc, turn, dead);
}