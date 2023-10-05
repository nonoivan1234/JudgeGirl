#include<stdio.h>

int main(){
    int x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

    // check if (0, 0) is in the polygon
    int ok = 1;
    int cross1 = x1*y2 - x2*y1;
    int cross2 = x2*y3 - x3*y2;
    int cross3 = x3*y4 - x4*y3;
    int cross4 = x4*y1 - x1*y4;

    if (cross1*cross2 < 0 || cross2*cross3 < 0 || cross3*cross4 < 0 || cross4*cross1 < 0){
        ok = 0;
    }
    
    printf("%d", ok);
    return 0;
}