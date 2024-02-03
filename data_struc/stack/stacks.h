#define INT_MAX 1000000

struct stack{
    int size;
    int* arr;
    int top;
};
typedef struct stack stack;

stack initialise_stack(int size);
void input(int* ptr);
int isfull(stack* S);
int iskali(stack* S);
void push(stack* S,int x);
int pop(stack* S);
int stacktop(stack* S);
int stackbottom(stack* S);
int peek(stack* S,int s);
void display(stack* S);