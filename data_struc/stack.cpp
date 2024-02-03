/*
FIRST C++ PROGRAM
Implementation Stack using Object Oriented Patterns
*/
//#include<stdio.h>
#include<iostream>
//#include<stdlib.h>
template <typename Type>
struct stack{
    int top;
    Type* arr;
    int len;
    stack(int size){//Constructor
        len=size;
        top=-1;
        //arr=(Type*)malloc(size*sizeof(Type));
        arr=new Type[size];
    }
    Type& operator[](int i){//overloading [] operator
    //OPERATOR OVERLOADING
        //S[i] will return S.arr[i] where S is a stack data type variable
        return arr[i];
    }
    /* void print(){
        printf("{");
        for(int i=0;i<=top;i++){
            printf("%d,",arr[i]);
        }printf("\b}\n");
    } */
    void print(){
        for(int i=top;i>=0;i--){
            std::cout<<arr[i]<<"\n";
            //printf("%d\n",arr[i]);
        }
    }
    bool isfull(){
        return(top==len-1);
    }
    bool iskali(){
        return(top==-1);
    }
    void push(Type x){
        if(isfull()) printf("STACK OVERFLOW\n");
        else arr[++top]=x;
    }
    Type pop(){
        if(iskali()){
            printf("STACK UNDERFLOW");
            return(0);
        }
        else return(arr[top--]);
    }
};
int main(){
    stack<char> S(5);
    /*
    Bool :- 0 -> False
            1 or any other number -> True
    */
    S.push(78);
    S.push(76);
    S.push(82);
    S.push(71);
    S.push(96);
    S.pop();
    S.pop();
    S.print();

    return 0;
}