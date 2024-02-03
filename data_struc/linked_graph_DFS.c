#include<stdio.h>
#include<stdlib.h>
/*using list represntation of graphs*/
struct node{
    int data;
    struct node* link;
};typedef struct node node;

node make(int x){
    node N;
    N.data=x;
    N.link=NULL;
    return(N);
}

int main(){
    node* G=(node*)malloc(7*sizeof(node));
    for(int i=0;i<7;i++){
        G[i]=make(i);
    }
    *G[0].link=(make(1));
}