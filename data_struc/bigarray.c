#include<stdio.h>
#include"BIGARRAY.h"
int size(int A[]){
    int i=0;
    while(A[i]!=-1){
        i++;
    }
    return i;
}
int main(){
    int B[]={3,1,2,0,-1};
    printf("%d",size(sorted_A));

    return 0;
}