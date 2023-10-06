#include<stdio.h>

int main(){
    int Year, DayOfJuaFir;
    scanf("%d %d", &Year, &DayOfJuaFir);

    int Days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31 ,30, 31, 30, 31};
    if(Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0)) Days[2] = 29;

    int prefix[13] = {0};
    for(int i = 1; i <= 12; i++)    prefix[i] = prefix[i-1] + Days[i-1];

    int q;
    scanf("%d", &q);
    while(q--){
        int m, d;
        scanf("%d %d", &m, &d);

        if(m < 1 || m > 12){
            printf("-1\n");
            continue;
        }
        if(d < 1 || d > Days[m]){
            printf("-2\n");
            continue;
        }

        int TotalDay = prefix[m] + d - 1;

        int Day = (TotalDay + DayOfJuaFir) % 7;
    
        printf("%d\n", Day);
    }
}