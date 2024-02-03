/*COMPLETED*/
#include<stdio.h>
#include<stdlib.h>
#define ERROR -31235295 //sentinel
struct node{
    int data;
    struct node* link;
};
typedef struct node node;
node* header=NULL;
node* create(int x){
    node* new;
    new=malloc(sizeof(node));
    new->data=x;
    new->link=NULL;

    return(new);
}
void push(int x){
    node* new=create(x);
    if(header==NULL){
        new->link=NULL;
        header=new;
    }
    else{
        new->link=header;
        header=new;
    }
}
int pop(){
    if(header==NULL)
    return ERROR;
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
int peek(int pos){//returns data at ith position in the list (index starts from zero)
    int i;
    node* ptr=header;
    for(i=0;i<=pos&&ptr!=NULL;i++){
        ptr=ptr->link;
    }
    if(ptr==NULL){
        return(ERROR);
    }
    else
        return(ptr->data);

}

int stacktop(){//returns topmost item in stack
    return(header->data);
}
int stackbottom(){//returns bottom most elsement of stack
    node* ptr;
    for(ptr=header;ptr->link!=NULL;ptr=ptr->link);//this loop traverse till the end of the list
    return(ptr->data);
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
                push(x); 
                break;
            }
            case 2: pop(); break;
            case 3: display(); break;
            case 4: {
                x=stacktop();
                printf("\n%d\n",x);
                break;
            }
            case 5: {
                x=stackbottom();
                printf("\n%d\n",x);
                break;
            }
            case 0: return(0);
            default: printf("\nWrong choice\n");
        }
    }
}

