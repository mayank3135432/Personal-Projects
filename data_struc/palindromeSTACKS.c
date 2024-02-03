#include<stdio.h>
#include<stdlib.h>
int stack[100];
int top=-1;
int size,x,k,ch;

int isfull(){
    return((top==size-1)?1:0);
}
int iskali(){
    return((top==-1)?1:0);
}
void push(){
    if(isfull()){
        printf("----------------------STACK OVERFLOW----------------------\n");
    }
    else{
    top++;
    scanf("%d",&x);
    stack[top]=x;
    }
}
void pushf(int a){
    if(isfull()){
        printf("----------------------STACK OVERFLOW----------------------\n");
    }
    else{
    top++;
    stack[top]=a;
    }
}
int pop(){
    if(iskali()){
        printf("----------------------STACK UNDERFLOW----------------------\n");
        return 0;
    }
    else
    return(stack[top--]);
}
void display(){
    if(iskali())
    printf("EMPTY STACK\n");
    else{
        printf("\n");
        for(k=top;k>-1;k--)
        printf("%d\n",stack[k]);

        printf("\n");
    }
}