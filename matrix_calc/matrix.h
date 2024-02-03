#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct matrix{//packages the information of the matrix, number of rows and columns.
    double** arr;//to be pointed to a 2D dynamic array
    int row;
    int cols;
};

typedef struct matrix matrix;
static matrix ERROR={NULL,-1,-1};//error matrix to be returned as sentinel
matrix create(int rows,int cols);
double power(double x,double y);
matrix power(double x,matrix M);
void input(matrix A);
void output(matrix A);
matrix add(matrix A,matrix B);
matrix dot(matrix A,matrix B);
matrix complexmatrix(double a,double b);
matrix vector2(double x,double y);
matrix transpose(matrix A);
