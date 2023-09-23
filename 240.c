#include<stdio.h>

void SWAP(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int x[4], y[4];
        for(int i = 0; i < 4; i++)  scanf("%d %d", &x[i], &y[i]);

        if(x[0]+x[2]==x[1]+x[3] && y[0]+y[2]==y[1]+y[3])    ;
        else if(x[0]+x[1]==x[2]+x[3] && y[0]+y[1]==y[2]+y[3]){
            SWAP(&x[1], &x[2]); SWAP(&y[1], &y[2]);
        }
        else if(x[1]+x[2]==x[0]+x[3] && y[1]+y[2]==y[0]+y[3]){
            SWAP(&x[0], &x[1]); SWAP(&y[0], &y[1]);
        }
        else{
            printf("other\n");
            continue;
        }

        int v1x = x[1] - x[0], v1y = y[1] - y[0];
        int v2x = x[2] - x[1], v2y = y[2] - y[1];
        int v3x = x[3] - x[2], v3y = y[3] - y[2];
        int v4x = x[0] - x[3], v4y = y[0] - y[3];

        int l1 = v1x * v1x + v1y * v1y;
        int l2 = v2x * v2x + v2y * v2y;
        int l3 = v3x * v3x + v3y * v3y;
        int l4 = v4x * v4x + v4y * v4y;

        if(l1==l2 && l2==l3 && l3==l4){
            if(v1x * v2x + v1y * v2y == 0 && v2x * v3x + v2y * v3y == 0 && v3x * v4x + v3y * v4y == 0 && v4x * v1x + v4y * v1y == 0)
                printf("square\n");
            else
                printf("diamond\n");
        }
        else{
            if(v1x * v2x + v1y * v2y == 0 && v2x * v3x + v2y * v3y == 0 && v3x * v4x + v3y * v4y == 0 && v4x * v1x + v4y * v1y == 0)
                printf("rectangle\n");
            else
                printf("other\n");
        }
    }
}