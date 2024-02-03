#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,n;
    printf("how many elements do you need ?");
    scanf("%d",&n);
    int* A=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        printf("enter %dth number ",i+1);
        scanf("%d",A+i);        
    }
    for(i=0;i<n;i++){
        printf("%d\t",A[i]);
    }

    return 0;
}