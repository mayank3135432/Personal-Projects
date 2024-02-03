#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 1000000
struct stack{
    int size;
    int* arr;
    int top;
};
typedef struct stack stack;


stack initialise_stack(int size){
    stack S={size,(int*)malloc(size*sizeof(int)),-1};
    return(S);
}

void input(int* ptr){
    while(1){
        scanf("%d",ptr);
        if(*ptr>INT_MAX || *ptr<-INT_MAX){
            printf("please enter valid input\n");
        }
        else
        return ;
    }
}
int isfull(stack* S){
    return((S->top==S->size-1)?1:0);
}
int iskali(stack* S){
    return((S->top==-1)?1:0);
}
void push(stack* S,int x){
    if(isfull(S)){
        printf("STACK OVERFLOW");
        return;
    }
    else{
        S->top=S->top+1;
        S->arr[S->top]=x;
    }
}
int pop(stack* S){
    if(iskali(S)){
        printf("STACK UNDERFLOW");
        return(INT_MAX);
    }
    else{
        S->top--;
        return(S->arr[S->top+1]);
    }
}
int stacktop(stack* S){
    return(iskali(S)?INT_MAX:(S->arr[S->top]));
}
int stackbottom(stack* S){
    return(iskali(S)?INT_MAX:(S->arr[0]));
}
int peek(stack* S,int s){
    if(s>=0 && s<=S->top){
        return(S->arr[s]);
    }
    else{
        printf("no data");
        return(INT_MAX);
    }
}
void display(stack* S){
    printf("{ ");
    for(int i=0;i<=S->top;i++){
        printf("%d,",S->arr[i]);
    }
    printf("\b }");
}

