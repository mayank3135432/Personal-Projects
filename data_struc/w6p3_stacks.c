#include<stdio.h>
#include<stdlib.h>
int stack[100],top,size/*size of stack*/;
int q;

void push(void){
    if(top>=size-1)
        printf("*** STACK OVERFLOW ***\n");
    else{
        top++;
        printf("\nenter integer to store in stack ");
        scanf("%d",&q);
        stack[top]=q;
    }
}
void display(void){
    int i;
    if(top<0)
        printf("****stack is empty****\n");
    else{
        
        for(i=0;i<=top;i++)
            printf("%d ",stack[i]);
        
    }
}

void pop(){
    if(top<0)
        printf("STACK UNDERFLOW\n");
    else{
        printf("popping %d\n",stack[top]);
        top--;
    }
}

int main(){
    int i=0;
    top=-1;
    int ch;
    //size=5
    printf("enter size of stack (max is 100) ");
    scanf("%d",&size);
    printf("press 1 to input new element to stack\npress 2 to pop\npress 3 to display stack\npress 4 to display stack\n");
    while(1){
        printf("enter 1,2,3 or 4\n");
        scanf("%d",&ch);
        if(ch==1)
        push();
        else if(ch==2)
        pop();
        else if(ch==3)
        display();
        else if(ch==4)
        return 0;
        else
        printf("please enter 1,2,3 or 4\n");
    }
    /*while(i<7){
        push();
        i++;
    }
    display();
    pop();
    pop();
    display();
    */

   return 0;
}


