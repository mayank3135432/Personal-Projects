#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[100];
int top=-1;
void push(char a){
    //top++;
    stack[++top]=a;
}
void pop(){
    top--;
}
int checkbal(char* q){
    int i;
    for(i=0;*(q+i)!=0;i++){
        if(*(q+i)=='(' || *(q+i)=='{' || *(q+i)=='[')
        push(*(q+i));
        else if(*(q+i)==')'){
            if(stack[top]=='(')
            pop();
            else
            return 0;
        }
        else if(*(q+i)=='}'){
            if(stack[top]=='{')
            pop();
            else
            return 0;
        }
        else if(*(q+i)==']'){
            if(stack[top]=='[')
            pop();
            else
            return 0;
        }
        else
        continue;
    }
    if(top!=-1)
    return 0;//if there are any brackets left in stack,then string is unbalanced
    else
    return 1;
}

int main(){
    char name[30];
    printf("enter a string [MAX 30 char] ");
    gets(name);
    if(checkbal(name)==0)
    printf("\n\nparenthesies are not balanced ");
    else
    printf("\n\nbrackets are balanced ");
    return 0;
}
