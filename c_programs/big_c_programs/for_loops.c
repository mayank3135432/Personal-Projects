#include<stdio.h>
void main(){
    int i,j;
    for(i=0,j=0;i<3 || j<2;i++,j++){
        printf("%d %d\n",i,j);
    }
}