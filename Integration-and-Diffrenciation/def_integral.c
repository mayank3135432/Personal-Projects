/*C program to find out definite integral of x^2 from a to b*/
#include<stdio.h>
#include<math.h>

#define e 2.718282
#define pi 3.141592653589793238
double factorial(int num) {
	int f = 1;
	int i;
	for (i = 1; i <= num; i++) {
		f = f * i;
	}
    double ff=(double)f;
	return(ff);
}
double pov(double x, int n) {
	int i;
	double p = 1.0000000;
	for (i = 0; i < n; i++) {
		p = p * x;
	}
	return(p);
}
/*Now let's begin defining exp, cos and sin using taylor expansions*/


double expo(double x) {
	int i,n=15;
    double ex = 0;
    if(x==0)
        return(1);
    else if(0<x && x<1){
	    for (i = 0; i <= n; i++)
		    ex = ex + pov(x,i) / factorial(i);
	    return(ex);
    }
    else if(1<=x){
        return(e*expo(x-1));
    }
    else if(x<0){
        return(1/expo(-x));
    }
}

double func(double x){
    double y; 
    y=cos(x);
    return(y);
}
double diff(double f(double),double a){
    double A,h;
    h=0.00001;
    A=(f(a+h)-f(a))/h;
    return(A);
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
int main(){
    double a,b,S,S_self;
    printf("enter lower limit a ");
    scanf("%lf",&a);
    printf("enter upper limit b ");
    scanf("%lf",&b);
    //S_self=integral(expo,a,b);
    //S=integral(exp,a,b);
    //printf("\ndefinite integral of f(x) from %lf to %lf is %lf\t%lf\t%lf",a,b,S_self,S,exp(b)-exp(-a));
    S=integral(func,a,b);
    printf("%lf",S);
    return(0);
}