#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int odd[n], even[n], idx_odd = 0, idx_even = 0;
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        if(tmp % 2 == 0){
            even[idx_even] = tmp;
            idx_even++;
        }else{
            odd[idx_odd] = tmp;
            idx_odd++;
        }
    }

    if(idx_odd>0)   printf("%d", odd[0]);
    for(int i = 1; i < idx_odd; i++){
        printf(" %d", odd[i]);
    }
    printf("\n");

    if(idx_even>0)  printf("%d", even[0]);
    for(int i = 1; i < idx_even; i++){
        printf(" %d", even[i]);
    }
    printf("\n");
}