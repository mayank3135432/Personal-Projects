#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
typedef struct node node;
node *header=NULL;
node* create(int x){
    node* new;
    new=malloc(sizeof(node));
    new->data=x;
    new->link=NULL;

    return(new);
}
int traverse(){//Returns size of list (number of elements stored)
    node* ptr=header;
    int size=0;
    while(ptr->link!=NULL){
        ptr=ptr->link;
        size++;
    }
    return(size);
}
void start_insert(int x){
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
void end_insert(int x){//this function redundant now that I have insert() function
    if(header==NULL){
        start_insert(x);
    }
    else{
        node* new=create(x);
        node* ptr=header;
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        new->link=NULL;
        ptr->link=new;
    }
}
void insert(int x,int pos){
    if(pos==0 || header == NULL){
        start_insert(x);
    }
    else{
        node* new=create(x);
        node* ptr=header;
        int i;
        for(i=0;i<pos-1 && ptr->link!=NULL;i++)//if given pos is greater than size of list then insertion is done at the end
            ptr=ptr->link;
        new->link=ptr->link;
        ptr->link=new;
    }
}

/*void insert(int x,int pos){
    if(pos==0){
        start_insert(x);
    }
    else{
        at_insert(x,pos);
    }
}*/
void start_delete(){
    if(header==NULL){
        printf("empty list\n");
    }
    else{
        node *ptr;
        ptr=header;
        header=(ptr)->link;
        free(ptr);
    }
}
void end_delete(){
    if(header==NULL){
        printf("empty list\n");
    }
    else if(header->link==NULL){
        free(header);
        header=NULL;
    }
    else{
        int i;
            node* ptr=header;
            node* ptr1;
            ptr1=ptr->link;
            for(i=0;ptr1->link!=NULL;i++){
                ptr=ptr->link;
                ptr1=ptr->link;
            }
            ptr->link=ptr1->link;
            free(ptr1);
    }
}
void delete(int pos){
    if(pos==0 || header==NULL){
        start_delete();
    }
    else if(header->link==NULL){
        free(header);
        header=NULL;
    }
    else{
        int i;
        node* ptr=header;
        node* ptr1;
        ptr1=ptr->link;
        for(i=0;i<pos-1 && ptr1->link!=NULL;i++){
            ptr=ptr->link;
            ptr1=ptr->link;
        }
        ptr->link=ptr1->link;
        free(ptr1);
    }
}
void printlist(){
    if(header==NULL)
        printf("empty list\n");
    else{
        node* ptr=header;
        for (ptr = header ; ptr != NULL ; ptr = ptr -> link){
            printf("%d,",ptr->data);
        }
    }
}

int main(){
    /*
    insert(2,0);
    insert(4,1);
    insert(3,2);
    insert(13,22);
    end_delete();
    print();
    */
   int ch,i,x,pos;
   printf("________________________________MENU________________________________\n");
   printf("press 0 to insert element to end of list\npress 1 to delete element from end of list\n");
   printf("press 2 to insert element at the start of list\n press 3 to delete element from start of the list\n");
   printf("press 4 to insert element at given index\npress 5 to delete element at given index\n");
   printf("press 6 to print the list\n");
   label:
   printf("\nenter your choice ");
   scanf("%d",&ch);

   if(ch==0){
        printf("enter element you want to input ");
        scanf("%d",&x);
        end_insert(x);
   }
   else if(ch==1){
        end_delete();
   }
   else if(ch==2){
        printf("enter element you want to input ");
        scanf("%d",&x);
        insert(x,0);
   }
   else if(ch==3){
        delete(0);
   }
   else if(ch==4){
        printf("enter element you want to input ");
        scanf("%d",&x);
        printf("enter index ");
        scanf("%d",&pos);
        insert(x,pos);
   }
   else if(ch==5){
        printf("enter index ");
        scanf("%d",&pos);
        delete(pos);
   }
   else if(ch==6){
        printlist();
   }
   else if(ch==8){
        return 0;
   }
   else{
        printf("please enter valid input ");
   }
    goto label;
}