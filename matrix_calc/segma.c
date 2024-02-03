#include<stdio.h>
int main(){
    int A[5]={4,2,3,1,8};
    int *ptr = A;
    ptr[-1]=4;
    printf("%d\n",*(ptr-1));

    return 0;
}