#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node{
    struct node* left;
    char data;
    struct node* right;
};typedef struct node node;
node* stack[SIZE];
int top=-1;
/* 
void push(node* x){
    stack[++top]=x;
}
 */
