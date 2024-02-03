#include<stdio.h>
#define INT_MAX 1000000
int foo(char* str){
	int i=0;
	while(str[i++]);
	return --i;
}
void input(int* ptr){
    while(1){
        scanf("%d",ptr);
        if(*ptr>INT_MAX || *ptr<-INT_MAX){
            printf("please enter valid input\n");
        }
        else
        return ;
    }
}

int main(){
	int x;
	input(&x);
	printf("%d",x);

	return 0;
}
