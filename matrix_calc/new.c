#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct matrix{//packages the information of the matrix, number of rows and columns.
    double** arr;//to be pointed to a 2D dynamic array
    int rows;
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
    //free(P);

    return(M);
}
void input(matrix A){//to input values to a matrix
    int i,j;
    for(i=0;i<A.rows;i++){
        for(j=0;j<A.cols;j++){
            printf("A[%d][%d]=",i,j);
            scanf("%lf",&A.arr[i][j]);
        }
    }    
}
void output(matrix A){//prints matrix
    int i,j;
    for(i=0;i<A.rows;i++){
        printf("[");
        for(j=0;j<A.cols;j++){
            printf("%lf, ",A.arr[i][j]);
        }
        printf("\b\b]");//gg back 2 steps and overwrite , with ]
        printf("\n");
    }    
}
void freematrix(matrix A){
    for (int i=0;i<A.rows;i++){
        free(A.arr[i]);
    }
    free(A.arr);
}
matrix add(matrix A,matrix B){//returns A+B
    if(A.rows != B.rows || A.cols != B.cols){
        return(ERROR);//ERROR
    }
    matrix C=create(A.rows,A.cols);//create new matrix C which will be A+B
    for(int i=0;i<A.rows;i++){
        for(int j=0;j<A.cols;j++){
            C.arr[i][j]=A.arr[i][j]+B.arr[i][j];//C(i,j)=A(i,j)+B(i,j)
        }
    }
    return(C);
}
matrix dot(matrix A,matrix B){//returns AB
    if(A.cols != B.rows){
        return(ERROR);//ERROR
    }
    matrix C=create(A.rows,B.cols);//create new matrix C which will be A+B
    for(int i=0;i<A.rows;i++){
        for(int j=0;j<B.cols;j++){
            //C.arr[i][j]=0;
            for(int k=0;k<A.cols;k++)//0<=k<colsize(A)
                C.arr[i][j]+=A.arr[i][k]*B.arr[k][j];//C(i,j)=Σ[A(i,k)*B(k,j)]
        }
    }
    return(C);
}

matrix submatrix(matrix A,int hor,int ver){
    hor++;ver++;//bandaid solution
    matrix B = create(A.rows-1,A.cols-1);
    int i,j;
    int r=0;
    for(i=0;i<A.rows;i++){
        if(i==hor) r=1;
        int c=0;
        for(j=0;j<A.cols;j++){
            if(j==ver) c=1;
            B.arr[i-r][j-c]=A.arr[i][j];
        }
    }
    return(B);
}

int main(){
    //matrix A=complexmatrix(0,1);
    //matrix B=dot(A,A);
    //output(B);
    matrix A=create(4,4);
    A.arr[0][0]=3;
    A.arr[0][1]=7;
    A.arr[0][2]=1;
    A.arr[0][3]=5;
    A.arr[1][0]=4;
    A.arr[1][1]=3;
    A.arr[1][2]=2;
    A.arr[1][3]=1;
    A.arr[2][0]=4;
    A.arr[2][1]=5;
    A.arr[2][2]=5;
    A.arr[2][3]=0;
    A.arr[3][0]=0;
    A.arr[3][1]=7;
    A.arr[3][2]=3;
    A.arr[3][3]=1;
    output(A);
    matrix B;
    //B=submatrix(A,1,0);
    printf("\n\n");
    //output(B);
    
    printf("\n\n\n\n\n");
    int i,j;
    
    for(i=1;i<A.rows;i++){
        for(j=0;j<A.cols;j++){
            printf("%d,%d\n",i,j);
            B=submatrix(A,i,j);
            output(B);
            printf("\n\n");
            freematrix(B);
        }
    }
    

    return 0;
}