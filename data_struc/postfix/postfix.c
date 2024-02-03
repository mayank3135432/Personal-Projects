#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ERROR -31235295 //sentinel
struct node{
    char data;
    struct node* link;
};
typedef struct node node;
node* header=NULL;
node* create(char x){
    node* new;
    new=malloc(sizeof(node));
    new->data=x;
    new->link=NULL;

    return(new);
}
int iskali(){
    return((header==NULL)?1:0);
}
void push(char x){
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
char pop(){
    if(iskali())
    return 0;
    else{
        char a=header->data;
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
char peek(int pos){//returns data at ith position in the list (index starts from zero)
    int i;
    node* ptr=header;
    for(i=0;i<=pos&&ptr!=NULL;i++){
        ptr=ptr->link;
    }
    if(ptr==NULL){
        return(0);
    }
    else
        return(ptr->data);

}

char stacktop(){//returns topmost item in stack
    if(header==NULL){
        printf("\nstack underflow\n");
        return(0);
    }
    return(header->data);
}
char stackbottom(){//returns bottom most elsement of stack
    node* ptr;
    for(ptr=header;ptr->link!=NULL;ptr=ptr->link);//this loop traverse till the end of the list
    return(ptr->data);
}
int prec(char x){
    if(x=='+'||x=='-')
    return 1;
    else if(x=='*'||x=='/')
    return 2;
    else
    return 0;
}
int isdig(char x){//[48,57]
    return((x>=48 && x<=57)?1:0);
}
int isoperator(char x){//42,43,45,47
    return((x==42||x==43||x==45||x==47)?1:0);//This functions works as intended
}

//23+32/4+7
char* inttopos(char* in){
    char* pos=(char*)malloc(strlen(in)*sizeof(char));
    int i=0;
    int j=0;
    while(in[i]!=0){
        if(isdig(in[i])){
            pos[j]=in[i];
            j++;
            /*
            for(i=i;isdig(in[i]);i++){
                pos[j]=in[i];
                j++;
            }
            i--;
            */
            //pos[j]=',';
        }
        else if(in[i]=='('){
            push(in[i]);
        }
        else if(in[i]==')'){
            while(stacktop()!='('){
                pos[j]=pop();
                j++;
            }
            pop();//remove the left bracket
        }
        else if(isoperator(in[i])){//is there error here ???
            while((!iskali() && prec(in[i])<=prec(stacktop()))){
                pos[j]=pop();
                j++;
            }
            push(in[i]);
        }
        // else{
        //     printf("invalid char");
        //     exit(1);
        // }
        i++;
    }
    //push??
    while(!iskali()){
        //you can put an ( condition here
        pos[j++]=pop();
    }
    pos[j]=0;
    return(pos);
}

int main(){
    char* inf;
    fgets(inf,100,stdin);
    char* pos=inttopos(inf);
    puts(pos);
    return 0;
}

//(12+32)*(214-42)/(23-2)
//2+3
//(1+3)*(2-4)/(3-2)
//(2-6)+(3+7)/(2-1)