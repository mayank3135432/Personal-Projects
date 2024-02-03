#include<stdio.h>
#include<stdlib.h>
#include"BIGARRAY.h"
#define MAX 100
int binsearch(int A[],int l,int h,int key){
    if(l==h) return((A[l]==key)?l:ERROR);
    int m=(l+h)/2;
    if(A[m]==key) return(m);
    else if(A[m]<key){
        //printf("\n {l,m,h}={%d,%d,%d}",l,m,h);
        return(binsearch(A,m+1,h,key));
    }
    else if(A[m]>key){
        //printf("\n {l,m,h}={%d,%d,%d}",l,m,h);
        return(binsearch(A,l,m,key));
    }
}
int main(){
    int loc=binsearch(sorted_A,0,ARRAY_SIZE-1,6961);
    printf("at index %d\n",loc);
    
    return 0;
}
