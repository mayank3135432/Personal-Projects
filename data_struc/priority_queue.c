#include<stdio.h>
#define MAX 100
struct item{
    int data;
    int priority;
};
typedef struct item item;
item queue[MAX];
//int front;
int rear=-1;
item make(int x,int p){
    item P;
    P.data=x;
    P.priority=p;
    return(P);
}
int isfull();
int iskali();
void enqueue();
int peek();
int dequeue();
void display();

int iskali(){
    return(rear==-1);
}
int isfull(){
    return(rear==MAX-1);
}
void enqueue(item x){
    if((isfull())){
        printf("\n________________________QUEUE OVERFLOW________________________\n");
        return;
    }
    rear++;
    queue[rear]=x;
}
int peek(){//returns index of highest priority element
    int i,ind=0;
    for(i=1;i<=rear;i++){
        if(queue[i].priority>queue[ind].priority)
            ind=i;
    }
    return ind;
}
int dequeue(){//remove highest priority element from queue
    if(iskali()){
        printf("\n________________________QUEUE OVERFLOW________________________\n");
        return 0;
    }
    int i,ind;
    ind=peek();
    for(i=ind;i<rear;i++){
        queue[i]=queue[i+1];
    }
    rear--;
    return ind;
}
void display(){
    int i;
    printf("\n{");
    for(i=0;i<=rear;i++){
        printf("%d,",queue[i].data);
    }
    printf("\b}\n");
}
int main(){
    enqueue(make(4,10));
    enqueue(make(1,6));
    enqueue(make(9,0));
    enqueue(make(3,1));
    enqueue(make(7,3));
    display();
    dequeue();
    display();

    return 0;
}








