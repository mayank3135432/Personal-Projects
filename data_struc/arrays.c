#include<stdio.h>
#include<stdlib.h>
struct array{
    int* arr;
    int size;
    int use;
};
typedef struct array array;
array make(int N){
    array A;
    A.size=N;
    A.use=0;
    A.arr=(int*)malloc(N*sizeof(int));
    return(A);
}
void input(array* A){
    //A.use=0;
    printf("how many elements you want [MAX %d] ",A->size);
    int i;
    scanf("%d",&A->use);
    for(i = 0;i < A->use;i++){
        printf("enter %d element ",i);
        scanf("%d",A->arr+i);
    }
    //printf("%d\t",A->use);
}
void output(array A){
    //printf("%d",A.use);
    printf("[");
    for(int i=0;i<A.use;i++){
        printf("%d,",A.arr[i]);
    }
    printf("\b]");
}
int main(){
    array A=make(10);
    input(&A);
    //printf("%d\n",A.size);
    //printf("%d",A.use);
    
    output(A);

    return 0;
}