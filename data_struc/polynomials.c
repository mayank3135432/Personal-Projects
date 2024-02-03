#include<stdio.h>
#include<stdlib.h>
//#define MAX 100
double pov(double x,int n){
    double S=1;
    for(int i=0;i<n;i++){
        S=S*x;
    }
    return(S);
}
struct poly{
    double* arr;
    int max;
};
typedef struct poly poly;
poly create(int max){
    double* A=malloc((max+1)*sizeof(double));
    for(int i=0;i<(max+1);i++)
        A[i]=0;
    poly P={A,max};
    return(P);
}
double evaluate(poly P,double x){
    double S=0;
    for(int i=0;i<=P.max;i++){
        S=S+P.arr[i]*pov(x,i);
    }
    return S;
}
poly diff(poly P){
    poly DP=create(P.max-1);
    for(int i=0;i<=DP.max;i++){
        DP.arr[i]=(i+1)*P.arr[i+1];
    }
    return(DP);
}
poly add(poly P,poly Q){
    poly R;
    int m,n;
    if(P.max>=Q.max){
        R.max=P.max;
        R.arr=P.arr;
        for(int i=0;i<=Q.max;i++){
            R.arr[i]=P.arr[i]+Q.arr[i];
        }
    }
    else{
        R.max=Q.max;
        R.arr=Q.arr;
        for(int i=0;i<=P.max;i++){
            R.arr[i]=P.arr[i]+Q.arr[i];
        }
    }
    return(R);
}
poly dot(poly A,poly B){
    poly C=create(A.max+B.max);
    int i;
    // int k=(B.max>=A.max)?B.max:A.max;//k=max(A.max,B.max)
    // realloc(A.arr,sizeof(double)*k);
    // realloc(B.arr,sizeof(double)*k);
    // for(int i=A.max+1;i<=k;i++){

    // }
    if(A.max<B.max){
        A.arr=(double*)realloc(A.arr,(A.max+B.max)*sizeof(double));
        B.arr=(double*)realloc(B.arr,(A.max+B.max)*sizeof(double));
        for(i=A.max+1;i<=A.max+B.max;i++){
            A.arr[i]=0;
        }
        for(i=B.max+1;i<=A.max+B.max;i++){
            B.arr[i]=0;
        }
    }
    else{
        B.arr=(double*)realloc(B.arr,(A.max+B.max)*sizeof(double));
        A.arr=(double*)realloc(A.arr,(A.max+B.max)*sizeof(double));
        for(i=B.max+1;i<=A.max+B.max;i++){
            B.arr[i]=0;
        }
        for(i=A.max+1;i<=A.max+B.max;i++){
            A.arr[i]=0;
        }
    }
    for(int n=0;n<=B.max+A.max;n++){
        for(i=0;i<=n;i++){
            C.arr[n]=C.arr[n]+A.arr[i]*B.arr[n-i];
        }
    }

    return(C);
}
void display(poly P){
    for(int i=0;i<=P.max;i++){
        printf(" %lfx^%d +",P.arr[i],i);
    }
}
void print(poly P){
    printf("[");
    for(int i=0;i<=P.max;i++){
        printf("%lf,",P.arr[i]);
    }
    printf("\b]");
}
int main(){
    poly A=create(4);
    A.arr[0]=3;
    A.arr[1]=-2;
    A.arr[2]=7;
    A.arr[4]=5;

    poly B=create(6);
    B.arr[0]=5;
    B.arr[1]=2;
    B.arr[2]=-1;
    B.arr[3]=3;
    B.arr[4]=10;
    B.arr[5]=-7;
    B.arr[6]=4;

    print(dot(A,B));
    // double y=evaluate(ptr,3);
    // printf("\n%lf\n",y); i
}