/*
pseudocode to caluclate sqrt(x) using newton's method

input a
let i=0, b=1
input n
while(i<n){
    y=b-(b*b-a)/2b
    b=y
    i++
}
*/
/*gives accurate sqrt for orders of magnitiude upto >10^25*/
#include<stdio.h>
#include<stdlib.h>

double sqr(double a){
    if(a<0){
        printf("ERROR not a real number ");
        exit(0);
    }
    int n=100;//n is the number of iterations newton's method is used
    int i;
    double y;//y will be the sqrt(a)
    double b=1;
    i=0;
    while(i<n){
        y=b-(b*b-a)/(2*b);//b-(f(b)/f'(b)) :f(x)=x*x-a
        b=y;
        i++;
    }
    return(y);
}
void main(){
    int i;
    double x;
    printf("%lf",sqr(-0));
}