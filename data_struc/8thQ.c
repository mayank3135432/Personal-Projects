#include<stdio.h>
void show(int[]);
int main(){
    int ary[4]={1,2,3,4};
    show(ary);
    printf("%d",ary[0]);

    return 0;
}
void show(int p[4]){
    int i=10;
    p=&i;
    printf("%d",p[0]);
}