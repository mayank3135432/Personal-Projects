#include<stdio.h>
#include<stdlib.h>
#define ERROR -31235295 //sentinel
struct node{
    int data;
    struct node* link;
};
typedef struct node node;
void main(){
    node* header;
    header=NULL;
    printf("%d",header->data);
}