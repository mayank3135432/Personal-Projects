#include<stdio.h>
#include<stdlib.h>
#define ERROR -31235295 //sentinel
struct node{
    int data;
    struct node* link;
};
typedef struct node node;

node* create(int x){
    node* new;
    new=malloc(sizeof(node));
    new->data=x;
    new->link=NULL;

    return(new);
}

node* header;

void enqueue(int x){
    node* new=create(x);
    if(header==NULL){
        //new->link=NULL;
        header=new;
    }
    else if(header->link==NULL){
        header->link=new;
    }
    else{
        node* ptr;
        for(ptr=header;ptr->link!=NULL;ptr->link);
        ptr->link=new;
    }
}
int pop(){
    if(header==NULL)
    return ERROR;//empty
    else{
        int a=header->data;
        header=header->link;
        return(a);
    }
}
void display(){
    node* ptr;
    printf("{ ");
    for(ptr=header;ptr!=NULL;ptr=ptr->link){
        printf("%d ,",ptr->data);
    }
    printf("\b}\n");
}

int main(){
    int ch,x;
    printf("________________________________MENU________________________________\n");
    printf("press 1 to push()\npress 2 to pop()\npress 3 to display\npress 4 to stacktop\npress 5 to stackbottom\npress 0 to exit\n");
    while(1){
        printf("enter your choice ");
        scanf("%d",&ch);
        switch(ch){
            case 1: { 
                printf("enter element you want to push ");
                scanf("%d",&x);
                enqueue(x); 
                break;
            }
            case 2: {
                x=pop();
                if(x==ERROR)
                    printf("\nempty\n");
                else
                    printf("\nremoved %d\n",x);
                break;
            }
            case 3: display(); break;
            case 0: return(0);
            default: printf("\nWrong choice\n");
        }
    }
}
