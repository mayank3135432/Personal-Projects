#include<stdio.h>
#define N 9
int A[N]={7,6,10,5,9,2,1,15,7};
//problem at 2,7,5,6
/*QUICKSORT*/
int counter=0;
int partition(int lb,int ub);

void quicksort(int lb,int ub){
    if(lb>=ub) return;
    int piv=partition(lb,ub);
    quicksort(lb,piv-1);
    quicksort(piv+1,ub);//exclude piv
}

int partition(int lb,int ub){
    //if(counter<100) printf("-----%d-----(lb:%d,ub:%d)\n",counter++,lb,ub);//debug line
    int start=lb,end=ub;
    int piv=lb;
    int temp;
    while(1){
        while(A[start]<=A[piv] && start<ub) start++;
        while(A[end]>A[piv]) end--;
        if(start<end){
            temp=A[start];
            A[start]=A[end];
            A[end]=temp;//start<end
        }else{
            temp=A[piv];
            A[piv]=A[end];
            A[end]=temp;
            return end;
        }
    }
    /* temp=A[piv];
    A[piv]=A[end];
    A[end]=temp;
    return end; */
}
int main(){
    int i;
    quicksort(0,N-1);
    printf("{");
    for (i = 0; i < N; i++){
        printf("%d,", A[i]);
    }
    printf("\b}\n");

    return 0;
}