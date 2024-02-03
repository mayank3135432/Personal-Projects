#include<stdio.h>
#include<stdlib.h>
int Q[100];
int rear=-1,front=0;
int size,x,k,ch;

int isfull(){
    return((rear==size)?1:0);
}
int iskali(){
    return((front>rear)?1:0);
}
void push(){
    if(isfull())
    printf("----------------------QUEUE OVERFLOW----------------------\n");
    else{
        rear++;
        printf("enter number you want to enqueue ");
        scanf("%d",&x);
        Q[rear]=x;
    }
}
int pop(){
    if(iskali()){
    printf("----------------------QUEUE UNDERFLOW----------------------\n");
    return 0;
    }
    else
    return(Q[front++]);
}

void display(){
    if(iskali())
    printf("{}\n");
    else{
        printf("{");
        for(k=front;k<=rear;k++)
        printf("%d, ",Q[k]);
        printf("\b\b}\n\n");
    }
}
int main(){
    printf("enter size of queue [MAX 100]: ");
    scanf("%d",&size);
    printf("Press 1 to enqueue\nPress 2 to dequeue\nPress 3 to display\nPress 4 to quit\n\n");
    label:
    printf("enter your choice ");
    scanf("%d",&ch);
    if(ch==1)
    push();
    else if(ch==2){
        //y=pop();
        if(!iskali())
        printf("dequeueing %d...\n",pop());
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