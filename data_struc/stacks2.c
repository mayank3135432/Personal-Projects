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
int main(){
    printf("enter size of stack [MAX 100]: ");
    scanf("%d",&size);
    printf("Press 1 to push\nPress 2 to pop\nPress 3 to display\nPress 4 to quit\n\n");
    label:
    printf("enter your choice ");
    scanf("%d",&ch);
    if(ch==1)
    push();
    else if(ch==2){
        //y=pop();
        if(!iskali())
        printf("popping %d...\n",pop());
        else
        pop();
    }
    else if(ch==3){
        display();
    }
    else if(ch==4)
    return 0;
    else
    printf("please enter 1,2,3 or 4\n");

    
    goto label;
}