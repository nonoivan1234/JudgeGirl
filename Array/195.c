#include<stdio.h>

int check(int a[][3]){
    int flag=-1;
    for(int i=0;i<3;i++){
        if (a[i][0]==a[i][1] && a[i][1]==a[i][2] && a[i][0]!=-1)
            flag=a[i][0];
        if (a[0][i]==a[1][i] && a[1][i]==a[2][i] && a[0][i]!=-1)
            flag=a[0][i];
    }
    if (a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[0][0]!=-1)
        flag=a[0][0];
    if (a[0][2]==a[1][1] && a[1][1]==a[2][0] && a[0][2]!=-1)
        flag=a[0][2];
    
    return flag;
}

void print(int a[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if (a[i][j]==-1)    printf(" ");
            else if (a[i][j]==0)    printf("O");
            else if (a[i][j]==1)    printf("X");
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d", &n);
    int a[3][3];
    for(int i=0;i<3;i++)    for(int j=0;j<3;j++)    a[i][j]=-1;
    
    int now = 0;

    int x, y;
    for(int i=0;i<n;i++){
        scanf("%d %d", &x, &y);
        if (x>2 || y>2 || x<0 || y<0 || a[x][y]!=-1){
            continue;
        }

        a[x][y] = now;
        // print(a);
        if (check(a)==0){
            printf("Black wins.\n");
            return 0;
        }
        else if (check(a)==1){
            printf("White wins.\n");
            return 0;
        }
        now ^= 1;
    }

    printf("There is a draw.\n");
}