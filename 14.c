#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++)  scanf("%d", &arr[i]);

    printf("%d", arr[n-1]);
    for(int i=n-2; i>=0; i--)   printf(" %d", arr[i]);
    printf("\n");
}