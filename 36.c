#include<stdio.h>

int main(){
    int y, m, d;
    int D[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    scanf("%d %d %d", &y, &m, &d);

    int isLeap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
    if(isLeap) D[2] = 29;
    if (m>12 || m<1 || d<0 || d>6){
        printf("invalid\n");
        return 0;
    }

    printf(" Su Mo Tu We Th Fr Sa\n");
    printf("=====================\n");
    int day=1;
    for(int i=0;i<d;i++)    printf("   ");
    for(int i=d;i<7;i++)    printf("%3d", day++);
    printf("\n");
    
    while(day<=D[m]){
        for(int i=0;i<7;i++){
            printf("%3d", day++);
            if(day > D[m])  break;
        }
        printf("\n");
    }
    printf("=====================\n");

    return 0;
}