#include<stdio.h>
#include<stdlib.h>

void quicksortold(int,int);
int partition_old(int,int);
int size();

int A[10]={4,2,7,1,3,-1};

int main(){
    int N=size();
    int i;
    quicksortold(0,N-1);

    for(i=0;i<N;i++){
        printf("%d ,",A[i]);
    }
    printf("\b\b");
    return 0;
}

int size(){
    int i;
    for(i=0;A[i]!=-1;i++);
    return(i);
}

int partition_old(int left, int right) {
    int pivot = A[right];
    int i = left - 1;
    int temp;

    for (int j = left; j < right; j++) {
        if (A[j] <= pivot) {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    temp = A[i + 1];
    A[i + 1] = A[right];
    A[right] = temp;

    return i + 1;
}

void quicksortold(int left,int right){
    if(left>=right)
        return;
    int piv;
    piv=partition_old(left,right);
    quicksortold(left,piv-1);
    quicksortold(piv,right);
}