#include<stdio.h>
int isoperator(char x){//42,43,45,47
    return((x==42||x==43||x==45||x==47)?1:0);
}
int main(){
    printf("%d",isoperator('2'));
    return 0;
}