/*C program to find out definite integral of a function */
#include<stdio.h>
#include<math.h>
#define e 2.718282
#define pi 3.141592653589793238

double func(double x){
    double y; 
    y=/*keep any function*/log(x);
    return(y);
}

double integral(double function(double),double a,double b){
    double S,delta,x;
    int i;
    delta=0.00001;
    S=0;
    int n=0;
    for(i=0;i<=(int)((b-a)/delta);i++)
        S=S+function(a+i*delta)*delta;
    return(S);
}

double diff(double f(double),double a){
    double A,h;
    h=0.00001;
    A=(f(a+h)-f(a))/h;
    return(A);
}

int main(){
    double a,b,S;
    printf("enter lower limit a ");
    scanf("%lf",&a);
    printf("enter upper limit b ");
    scanf("%lf",&b);
    S=integral(func,a,b);
    printf("%lf",S);
    return(0);
}