#include<stdio.h>

int main(){
    int s, f, t;
    scanf("%d %d %d", &s, &f, &t);

    // solve the equation below
    // a + b + c = s
    // 2a + 4b + 8c = f
    // a + b = t

    if ((8*s-f-4*t)%2!=0 || (f-8*s+6*t)%2!=0)   printf("0\n");
    else if ((8*s-f-4*t)<0 || (f-8*s+6*t)<0 || s-t<0)   printf("0\n");
    else{
        int a = (8*s-f-4*t)/2;
        int b = (f-8*s+6*t)/2;
        int c = s-t;
        printf("%d\n%d\n%d\n", a, b, c);
    }

}