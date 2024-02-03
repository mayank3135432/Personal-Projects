#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[100];
int top;
void push(char);
char pop();
void strev(char*);
int main(){
    printf("enter a string [MAX 30 CHARS] ");
    char name[30];
    gets(name);
    strev(&name[0]);
    printf("the reversed string is ");
    puts(name);

    return 0;
}
void push(char x){
    top++;
    stack[top]=x;
}
char pop(){
    return(stack[top--]);
}
void strev(char* p){
    int size,i;
    for(i=0;*(p+i)!=0;i++){
        push(p[i]);
    }
    size=i;
    i=0;
    while (top>-1){
        p[i]=pop();
        i++;
    }    
}