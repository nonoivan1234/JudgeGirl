#include<stdio.h>
#include<stdlib.h>
int min(int a, int b) {return a < b ? a : b;}
int max(int a, int b) {return a > b ? a : b;}
const int INF = 1000000000;

int cmp(int a[], int b[]){
    if(a[0] != b[0])  return a[0] < b[0];
    else  return a[1] < b[1];
}

int main(){

    int n;
    scanf("%d", &n);
    int parking[n][4];  // 0: x, 1: y, 2: num, 3: current
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &parking[i][j]);
        }  
        parking[i][3] = 0;
    } 

    int m;
    scanf("%d", &m);
    int bike[m][2];  // 0: x, 1: y
    for(int i = 0; i < m; i++)  scanf("%d %d", &bike[i][0], &bike[i][1]);


    for(int i = 0; i < m; i++){
        int ind = -1, curX = INF, curY = INF;
        int min_dis = INF;

        for(int j = 0; j < n; j++){
            if(parking[j][3] == parking[j][2])  continue;

            int dis = abs(parking[j][0] - bike[i][0]) + abs(parking[j][1] - bike[i][1]);
            if(dis < min_dis){
                min_dis = dis;
                ind = j;
                curX = parking[j][0], curY = parking[j][1];
            }
            else if(dis == min_dis){
                if(parking[j][0] < curX){
                    ind = j;
                    curX = parking[j][0], curY = parking[j][1];
                }
                else if(parking[j][0] == curX && parking[j][1] < curY){
                    ind = j;
                    curX = parking[j][0], curY = parking[j][1];
                }
            }
        }

        parking[ind][3]++;
    }

    for(int i = 0; i < n; i++){
        printf("%d\n", parking[i][3]);
    }

    return 0;
}