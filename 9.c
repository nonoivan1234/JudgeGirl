#include<stdio.h>

int main(){
    int x;
    scanf("%d", &x);
    
    int score;
    if (x>0)    score = 0;
    else{
        score = -100;
        printf("%d\n", score);
        return 0;
    }

    if (x%3==0) score += 3;
    if (x%5==0) score += 5;

    if (x>=100 && x<=200)   score += 50;
    else   score -= 50;

    printf("%d\n", score);
}