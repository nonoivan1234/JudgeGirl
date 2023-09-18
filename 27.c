#include<stdio.h>

int main(){
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    int area = 2*(a*b + b*c + c*a) + 8*(d*(a-2*e) + d*(b-2*e) + d*(c-2*e));
    int volume = a*b*c - 2*d*(a-2*e)*(b-2*e) - 2*d*(b-2*e)*(c-2*e) - 2*d*(c-2*e)*(a-2*e);

    printf("%d\n%d\n", area, volume);
}