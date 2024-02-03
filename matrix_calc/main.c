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
        printf("\b\b]");//go back 2 steps and overwrite , with ]
        printf("\n\n\n");
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
matrix submatrix(matrix A,int x,int y){
    if(A.row!=A.cols || x>=A.row || y>=A.cols) return(ERROR);
    int i,j,p,q,n=A.row;
    matrix B=create(n-1,n-1);
    for(i=0,p=0 ; (i<n)||(p<n-1) ; i++,j++){
        for(j=0,q=0 ; (j<n)||(q<n-1) ; j++,q++){
            if(i==x){
                if(j==n-1) p--;
                else continue;
            }
            else if(j==y){
                q--;
            }
            else B.arr[p][q]=A.arr[i][j];
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
int main(){
    //matrix A=complexmatrix(0,1);
    //matrix B=dot(A,A);
    //output(B);
    matrix A=create(3,3);
    input(A);
    matrix B=submatrix(A,1,1);
    output(A);
    output(B);
    

    return 0;
}

