#include<stdio.h>
#include<math.h>
const double eps = 1e-6;
const int mx = 1e5+5;

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    // solve cube equation x^3 + ax^2 + bx + c = 0
    // by Newton's method
    
    double x = mx;
    while(1){
        long double y = x*x*x + a*x*x + b*x + c;
        long double dy = 3*x*x + 2*a*x + b;
        long double nx = x - y/dy;
        if(nx-x < eps && nx-x > -eps) break;
        x = nx;
    }

    // solve other two roots by quadratic equation
    x = (int)(round(x+eps));
    a = a + x;
    b = b + a*x;

    double delta = a*a - 4*b;
    double x1, x2;
    if(b==0){
        x1 = 0;
        x2 = -a;
    }
    else{
        x1 = (-a + sqrt(delta+eps))/2;
        x2 = (-a - sqrt(delta+eps))/2;
    }

    // sort x, x1, x2 (x1 > x2 is trivial XD)
    double tmp;
    if(x1 < x2){
        tmp = x1;
        x1 = x2;
        x2 = tmp;
    }
    if(x < x1){
        tmp = x;
        x = x1;
        x1 = tmp;
    }
    if(x < x2){
        tmp = x;
        x = x2;
        x2 = tmp;
    }

    int ans1 = (int)round(-x+eps);
    int ans2 = (int)round(-x1+eps);
    int ans3 = (int)round(-x2+eps);

    printf("%d %d %d\n", ans1, ans2, ans3);
}