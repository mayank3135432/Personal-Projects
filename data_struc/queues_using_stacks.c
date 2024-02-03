#include<stdio.h>
#include<stdlib.h>
#define max 5
/*17/03/12023
A wild zero is appearing at the beginning of "stack" by default
cause of it is still unknown
*/

/*18/03/12023-11:30 [UPDATE]
the error has been found.I did not intialise top variable which is why erroro happened
*/
int stack[max];
int top=-1;
int q;

void pushf(int a){
    top++;
    stack[top]=a;
}

void push(void){
    top++;
    printf("\nenter integer to store in stack ");
    scanf("%d",&q);
    stack[top]=q;
}

int pop(){
    //printf("popping %d\n",stack[top]);
    return(stack[top--]);
}

void push(){
    if(top>=max-1)
    printf("-------------------QUEUE OVERFLOW-------------------\n");
    else
    push();
}
int pop(){
    int x;
    int y;
    if(top==-1){
        printf("-------------------QUEUE UNDERFLOW-------------------\n");
        return(1);
    }
    else if(top==0)
    return(pop());
    else{
        
        x=pop();
        y=pop();
        pushf(x);
        return(y);
    }
}
void display(void){
    int i;
    if(top<0)
        printf("{}\n");
    else{
        printf("{");
        for(i=0;i<=top;i++)
            printf("%d, ",stack[i]);
        printf("\b\b}\n");
    }
}
int main(){
    display();
    int i=0;
    int ch;
    //size=5
    printf("press 1 to input new element to Queue\npress 2 to dequeue\npress 3 to display Queue\npress 4 to display stack\n");
    while(1){
        printf("enter 1,2,3 or 4\n");
        scanf("%d",&ch);
        if(ch==1)
        push();
        else if(ch==2)
        pop();
        else if(ch==3)
        display();
        else if(ch==4)
        return 0;
        else
        printf("\nplease enter 1,2,3 or 4\n");
    }
}