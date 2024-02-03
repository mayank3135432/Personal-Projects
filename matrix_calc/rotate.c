#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"matrix.h"
matrix rotate(matrix v,double th){
    matrix R=create(2,2);
    R.arr[0][0]=cos(th);
    R.arr[1][0]=sin(th);
    R.arr[0][1]=-R.arr[1][0];
    R.arr[1][1]=R.arr[0][0];
    
    return(dot(R,v));
}
int main(){
    double x,y,th;
    scanf("%lf %lf %lf",&x,&y,&th);
    matrix M=vector2(x,y);
    matrix A=rotate(M,th);
    output(A);

    return(0);    
}
