#include<stdio.h>
#define MAX 100
int A[MAX];
int size = 0;//number of elements in heap (default value zero)
int isheap(){
  for(int i=1;i<size;i++){
    if(A[i] > A[(i-1)/2]) return 0;
  }return 1;
}
void insert(int value){
  A[size]=value;
  int i = size;
  size++;
  int parent;
  while(i>0){
    parent = (i-1)/2;
    if(A[parent]<A[i]){
      int temp = A[parent];
      A[parent] = A[i];
      A[i] = temp;
    }else return;
    i = parent;
  }
}
void correct(int root){// helper function for delete()
  printf("root is %d :: ",root);
  if(A[2*root+1]>=A[root] || A[2*root+2]>=A[root]){
    int dox=(A[2*root+1]>=A[2*root+2])?(2*root+1):(2*root+2);
    int temp = A[root];
    A[root] = A[dox];
    A[dox] = temp;
    correct(dox);// recursion step
  }
}
void delete(){
  if(size==0){
    return;
  }
  size--;
  A[0]=A[size];
  correct(0);// call the helper function inorder to swap elements into order
}
void show(){
  if(size == 0){
    printf("[]\n");
    return ;
  }
  printf("[");
  for(int i=0;i<size;i++){
    printf("%d,",A[i]);
  }printf("\b]\n");
}
int main(){
  int i;
  for(int i=0;i<11;i++){
    insert(i);
    //printf("size: %d :: ",size);
    show();
  }
  delete();
  show();
  delete();
  show();
  delete();
  show();
  delete();
  //show();
  return 0;
}
