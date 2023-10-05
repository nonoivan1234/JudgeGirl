#include<stdio.h>

int main(){
    int s, f, t;
    scanf("%d %d %d", &s, &f, &t);
    int a, b, c;
    // 由題目可知
    // a + b + c = s
    // a * 2 + b * 4 + c * 8 = f
    // a + b = t

    // 由上述三式可得
    c = s-t;
    b = f/2+3*t-4*s;
    a = s-b-c;

    printf("%d\n%d\n%d\n", a, b, c);
}