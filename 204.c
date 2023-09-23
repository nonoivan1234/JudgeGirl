#include<stdio.h>
const int N = 105;

int main(){
    int w, d;
    scanf("%d %d", &w, &d);

    int a[N][N];
    for(int i = 1; i <= d; i++)
        for(int j = 1; j <= w; j++)
            scanf("%d", &a[i][j]);
    
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};   // d, r, u, l
    int dd[4] = {3, 2, 1, 0};   // l, u, r, d

    for(int i=0;i<2*(w+d);i++){
        int x, y, dir;
        if(i<w) x=d+1, y=i+1, dir=2;
        else if(i < w+d)    x=d-i+w, y=w+1, dir=3;
        else if(i < 2*w+d)  x=0, y=2*w+d-i, dir=0;
        else    x=i-2*w-d+1, y=0, dir=1;

        int nx, ny;
        x += dx[dir], y += dy[dir];
        if(a[x][y]==1)    dir = dd[dir];

        while(x>0 && y>0 && x<=d && y<=w){
            nx = x + dx[dir], ny = y + dy[dir];
            if(a[nx][ny]==1)    dir = dd[dir];
            x = nx, y = ny;
        }

        int ans;
        if(x==d+1)  ans=y-1;
        else if(y==w+1) ans=d+w-x;
        else if(x==0)   ans=2*w+d-y;
        else    ans=2*w+d+x-1;

        printf("%d\n", ans);
    }
}