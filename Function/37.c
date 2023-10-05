#include<stdio.h>

int value(int type, int width, int height, int length){

    int Type[6] = {79, 47, 29, 82, 26, 22};
    int price[6] = {30, 10, 4, 5, 3, 9};

    int ind = -1;
    for(int i=0;i<6;i++){
        if(Type[i] == type){
            ind = i;
            break;
        }
    }

    if(ind == -1) return -1;

    if(width <= 0 || height <= 0 || length <= 0) return -2;

    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }

    int g = gcd(gcd(width, height), length);

    int volume = g * g * g;
    return width * height * length * volume * price[ind];
}

int main(){
    int type, width, height, length;
    scanf("%d %d %d %d", &type, &width, &height, &length);

    int val = value(type, width, height, length);
    printf("%d\n", val);
}