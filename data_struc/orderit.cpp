#include<stdio.h>
#include<stdlib.h>
struct array{
    int* arr;
    int len;
    array(int size){
        len=size;
        arr=(int*)malloc(size*sizeof(int));
    }
    /*
    int& operator[](int index) {
        if (index < 0 || index >= len) {
            std::cerr << "Index out of bounds!" << std::endl;
            exit(EXIT_FAILURE);
        }
        return arr[index];
    }
    */
    int& operator[](int i){
        return arr[i];
    }
    void print(){
        printf("{");
        for(int i=0;i<len;i++){
            printf("%d,",arr[i]);
        }printf("\b}\n");
    }
};typedef struct array array;
int main(){
    int a=5;
    array A = array(a);
    for(int i=0;i<A.len;i++){
        A[i]=i*2;
    }
    A.print();
}

