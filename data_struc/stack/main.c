#include<stdlib.h>
#include<stdio.h>

#include"stacks.h"

int main(){
    int ch,x,k,siz;
    printf("________________________STACKS________________________\n");
    while(1){
        printf("enter size of stack ");
        input(&siz);
        if(siz<=0){
            printf("please don't write nonsense\n");
        }
        else break;
    }
    printf("\nenter 1 to push\nenter 2 to pop\nenter 3 to display\nenter 4 to stacktop\nenter 5 to peek\nenter 9 to quit");
    
    stack S=initialise_stack(siz);
    stack* pS=&S;
    while(1){
        printf("\nenter your choice ");
        input(&ch);
        if(ch==1){
            if(isfull(pS)){
                printf("STACK OVERFLOW");
            }
            else{
                printf("\nenter number to push ");
                input(&x);
                push(pS,x);
            }
        }
        else if(ch==2){
            k=pop(pS);
            if(k!=INT_MAX)
                printf("popping %d \n",k);
        }
        else if(ch==3){
            display(pS);
        }
        else if(ch==4){
            int k=stacktop(pS);
            if(k != INT_MAX)
            printf("topmost is %d\n",stacktop(pS));
            else
            printf("STACK UNDERFLOW");
        }
        else if(ch==5){
            printf("enter position ");
            input(&x);
            k=peek(pS,x);
            if(k != INT_MAX)
                printf("%dth element is %d",x,k);
        }
        else if(ch==9)
        return 0;

        else{
            printf("please enter valid input\n");
        }
    }
}