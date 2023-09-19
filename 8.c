#include<stdio.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int ok = 1;
    if ( (a+b<=c) || (a+c<=b) || (b+c<=a) )    ok = 0;
    if ( (a-b>=c) || (a-c>=b) || (b-c>=a) )    ok = 0;

    printf("%d", ok);
}