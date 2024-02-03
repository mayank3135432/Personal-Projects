#include<stdio.h>
int size=0;
void inc(){
  size--;
}
int main(){
  printf("%d\n",size);
  inc();
  printf("%d\n",size);

  return 0;
}
