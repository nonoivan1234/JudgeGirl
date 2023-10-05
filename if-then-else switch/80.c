#include<stdio.h>

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int x1, y1, x2, y2, x3, y3;
        scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

        int a = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
        int b = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);
        int c = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);

        if (a==b || b==c || c==a) printf("isosceles\n");
        else if (a+b==c || b+c==a || c+a==b) printf("right\n");
        else if (a+b<c || b+c<a || c+a<b) printf("obtuse\n");
        else printf("acute\n");
    }
}