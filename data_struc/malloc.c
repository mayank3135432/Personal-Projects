#include<stdio.h>
#include<stdlib.h>
int main(){
    char* q=(char*)malloc(5*sizeof(char));
    q[0]='a';
    q[1]='b';
    q[2]='c';
    q[3]='d';
    q[4]='e';
    q=(char*)realloc(q,10*sizeof(char));
    q[6]='w';
    printf("%c",q[6]);

    free(q);
    return 0;
}