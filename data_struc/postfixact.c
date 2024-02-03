#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top=-1;
int isfull(){
    return((top==MAX-1)?1:0);
}
int iskali(){
    return((top==-1)?1:0);
}
void push(char x){
    if(isfull()){
        printf("stack overflow");
        exit(1);
    }
    stack[++top]=x;
}
int pop(){
    if(iskali()){
        printf("stack underflow");
        exit(1);
    }
    return(stack[top--]);
}

