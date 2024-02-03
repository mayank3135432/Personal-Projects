#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct matrix{//packages the information of the matrix, number of rows and columns.
    double** arr;//to be pointed to a 2D dynamic array
    int row;
    int cols;
};

typedef struct matrix matrix;
matrix ERROR={NULL,-1,-1};//error matrix to be returned as sentinel
matrix create(int rows,int cols){//returns null matrix
    double** P=(double**)malloc((rows)*sizeof(double*));//pointers to a dynamic array of pointers to dynamic- 
    int i,j;                                            //-pointers having double data type
    for(i = 0; i < rows; i++){
        *(P+i)=(double*)malloc((cols)*sizeof(double));
        for(j = 0; j < cols; j++){
            P[i][j]=0;//set values to 0
        }
    }
    matrix M={P,rows,cols};

    return(M);
}
double power(double x,double y);
void input(matrix A){//to input values to a matrix
    int i,j;
    for(i=0;i<A.row;i++){
        for(j=0;j<A.cols;j++){
            printf("enter (%d,%d) ",i,j);
            scanf("%lf",&A.arr[i][j]);
        }
    }    
}
void output(matrix A){//prints matrix
    int i,j;
    for(i=0;i<A.row;i++){
        printf("[");
        for(j=0;j<A.cols;j++){
            printf("%lf, ",A.arr[i][j]);
        }
        printf("\b\b]");//gg back 2 steps and overwrite , with ]
        printf("\n");
    }    
}
matrix add(matrix A,matrix B){//returns A+B
    if(A.row != B.row || A.cols != B.cols){
        return(ERROR);//ERROR
    }
    matrix C=create(A.row,A.cols);//create new matrix C which will be A+B
    for(int i=0;i<A.row;i++){
        for(int j=0;j<A.cols;j++){
            C.arr[i][j]=A.arr[i][j]+B.arr[i][j];//C(i,j)=A(i,j)+B(i,j)
        }
    }
    return(C);
}
matrix dot(matrix A,matrix B){//returns AB
    if(A.cols != B.row){
        return(ERROR);//ERROR
    }
    matrix C=create(A.row,B.cols);//create new matrix C which will be A+B
    for(int i=0;i<A.row;i++){
        for(int j=0;j<B.cols;j++){
            //C.arr[i][j]=0;
            for(int k=0;k<A.cols;k++)//0<=k<colsize(A)
                C.arr[i][j]+=A.arr[i][k]*B.arr[k][j];//C(i,j)=Σ[A(i,k)*B(k,j)]
        }
    }
    return(C);
}
matrix transpose(matrix A){
    matrix B=create(A.cols,A.row);
    for(int i=0;i<A.row;i++){
        for(int j=0;j<A.cols;j++){
            B.arr[j][i]=A.arr[i][j];
        }
    }
    return(B);
}
matrix complexmatrix(double a,double b){
    matrix A=create(2,2);
    A.arr[0][0]=a;
    A.arr[0][1]=-b;
    A.arr[1][0]=b;
    A.arr[1][1]=a;
    //[a -b]
    //[b  a] is a matrix equivalent to the complex number a+ib
    return(A);
}
matrix vector2(double x,double y){
    matrix M=create(2,1);
    M.arr[0][0]=x;
    M.arr[1][0]=y;
    return(M);
}