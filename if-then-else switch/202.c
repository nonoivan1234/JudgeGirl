#include<stdio.h>
#include<stdlib.h>
int max(int a, int b){return a>b?a:b;}
int min(int a, int b){return a<b?a:b;}

int gcd(int a, int b){
    if(a%b==0) return b;
    return gcd(b, a%b);
}

void plus(int frac1Up, int frac1Down, int frac2Up, int frac2Down, int *fracUp, int *fracDown){
    *fracUp = frac1Up*frac2Down + frac2Up*frac1Down;
    *fracDown = frac1Down*frac2Down;

    int gcd1 = gcd(abs(*fracUp), *fracDown);
    *fracUp /= gcd1, *fracDown /= gcd1;
}

void minus(int frac1Up, int frac1Down, int frac2Up, int frac2Down, int *fracUp, int *fracDown){
    *fracUp = frac1Up*frac2Down - frac2Up*frac1Down;
    *fracDown = frac1Down*frac2Down;

    int gcd1 = gcd(abs(*fracUp), *fracDown);
    *fracUp /= gcd1, *fracDown /= gcd1;
}

void multiply(int frac1Up, int frac1Down, int frac2Up, int frac2Down, int *fracUp, int *fracDown){
    *fracUp = frac1Up*frac2Up;
    *fracDown = frac1Down*frac2Down;

    int gcd1 = gcd(abs(*fracUp), *fracDown);
    *fracUp /= gcd1, *fracDown /= gcd1;
}

void divide(int frac1Up, int frac1Down, int frac2Up, int frac2Down, int *fracUp, int *fracDown){
    *fracUp = frac1Up*frac2Down;
    *fracDown = frac1Down*frac2Up;

    if(*fracUp * *fracDown < 0){
        *fracUp = abs(*fracUp);
        *fracDown = abs(*fracDown);
        *fracUp *= -1;
    }

    int gcd1 = gcd(abs(*fracUp), *fracDown);
    *fracUp /= gcd1, *fracDown /= gcd1;
}

int main(){
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);

    int frac1Up = 0, frac1Down = c, frac2Up = 0, frac2Down = g;
    if(a < 0)   frac1Up = a*c - b;
    else    frac1Up = a*c + b;
    if(e < 0)   frac2Up = e*g - f;
    else    frac2Up = e*g + f;

    int gcd1 = gcd(abs(frac1Up), frac1Down);
    int gcd2 = gcd(abs(frac2Up), frac2Down);

    frac1Up /= gcd1, frac1Down /= gcd1;
    frac2Up /= gcd2, frac2Down /= gcd2;

    int fracUp, fracDown;

    if(d == 0)  plus(frac1Up, frac1Down, frac2Up, frac2Down, &fracUp, &fracDown);
    else if(d == 1) minus(frac1Up, frac1Down, frac2Up, frac2Down, &fracUp, &fracDown);
    else if(d == 2) multiply(frac1Up, frac1Down, frac2Up, frac2Down, &fracUp, &fracDown);
    else if(d == 3) divide(frac1Up, frac1Down, frac2Up, frac2Down, &fracUp, &fracDown);

    int h, i, j;
    h = fracUp / fracDown;
    i = abs(fracUp) % fracDown;
    j = fracDown;  

    printf("%d\n%d\n%d\n", h, i, j);
    return 0;
}