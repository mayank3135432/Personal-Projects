#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double** make(int rows,int cols){
    
    double** P=(double**)malloc((rows+1)*sizeof(double*));
    int i,j;
    for(i = 0; i <= rows; i++){
        *(P+i)=(double*)malloc((cols+1)*sizeof(double));
    }
    for (i = 0; i <= rows; i++) {
		for (j = 0; j <= cols; j++){
            if(i<rows && j<cols){
                printf("enter element (%d,%d) ",i,j);
			    scanf("%lf", &P[i][j]);
            }
            else
                P[i][j]=NAN;
        }
	}
    return(P);
}

int rowsize(double** P){
    int i=0,j=0,check;
    check=(P[i][j]!=P[i][j])?1:0;
    while(check==0){
        i++;
        check=(P[i][j]!=P[i][j])?1:0;
    }
    int r=i;
    return(r);
}
int colsize(double** P){
    int i=0,j=0,check;
    check=(P[i][j]!=P[i][j])?1:0;
    while(check==0){
        j++;
        check=(P[i][j]!=P[i][j])?1:0;
    }
    int r=j;
    return(r);
}

void output(double** P){
    int rows=rowsize(P);
    int cols=colsize(P);
    int i,j;
    for (i = 0; i < rows; i++) {
        printf("[");
		for (j = 0; j < cols; j++) {
			printf("%lf, ", P[i][j]);
		}
        printf("\b\b]");
		printf("\n");
	}
    printf("\n");
}

double** prod(double** A,double** B){
    int m=rowsize(A);
    int n=colsize(A);
    int p=rowsize(B);
    int q=colsize(B);
    if(n!=p){
        double** C=(double**)malloc(1);
        *C=(double*)malloc(1);
        C[0][0]=NAN;
        printf("multiplication is not possible\n");
        return(C);
    }
    double** C=(double**)malloc((m+1)*sizeof(double*));
    int i,j,k;
    for(i=0;/*i<m*/i<=m;i++)
        *(C+i)=(double*)malloc((q+1)*sizeof(double));
    for(i=0;i<=m;i++){
        for(j=0;j<=q;j++){
            C[i][j]=0;
            if(i<m && j<q){
                for(k=0;k<n;k++)
                    C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
            else
                C[i][j]=NAN;
        }
    }
    return(C);
}
double** add(double** A,double** B){
    int m=rowsize(A);
    int n=colsize(A);
    int p=rowsize(B);
    int q=colsize(B);
    if(n!=q || m!=p){
        double** C=(double**)malloc(1);
        *C=(double*)malloc(1);
        C[0][0]=NAN;
        printf("addition is not possible\n");
        return(C);
    }
    double** C=(double**)malloc((m+1)*sizeof(double*));
    int i,j;
    for(i=0;/*i<m*/i<=m;i++)
        *(C+i)=(double*)malloc((q+1)*sizeof(double));
    for(i=0;i<=m;i++){
        for(j=0;j<=q;j++){
            if(i<m && j<n){
                C[i][j] = A[i][j]+B[i][j];
            }
            else
                C[i][j]=NAN;
        }
    }
    return(C);
}
double** transpose(double** A){
    int m,n,i,j;
    m=rowsize(A);
    n=colsize(A);
    double** T=(double**)malloc(n*sizeof(double*));
    for(i=0;i<=m;i++){
        *(T+i)=(double*)malloc(m*sizeof(double));
    }
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i<m && j<n)
                T[j][i]=A[i][j];
            else
                T[j][i]=NAN;
        }
    }
    return(T);
}

double** submatrix(double** A,int x,int y){
    /*this function omits given row (x) and column (y) from given matrix(A)*/
    int i,j,p,q;
    if(rowsize(A)!=colsize(A)){
        double** C=(double**)malloc(1);
        *C=(double*)malloc(1);
        C[0][0]=NAN;
        return(C);
    }
    int n=rowsize(A);
    double** M =(double**)malloc(n*sizeof(double*));
    for(i=0;i<=n;i++){
        *(M+i)=(double*)malloc(n*sizeof(double));
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==n-1 || j==n-1)
                M[i][j]=NAN;
        }
    }
    for(i=0,p=0;p<n-1 || i<n;p++,i++){
        for(j=0,q=0;q<n-1 || j<n;q++,j++){
            if(i==x){
                if(j==n-1)
                    p--;
                else
                    continue;
            }
            else if(j==y){
                q--;
            }
            else
                M[p][q]=A[i][j];
        }
    }
    return(M);
}

double det(double** A){ /*stuff that does'nt work*/
    if(rowsize(A)!=colsize(A)){
        printf("ERROR: matrix is not square\n");
        return(NAN);
    }
    int n=rowsize(A);
    int i,j,g;
    double S=0;
    if(n==1){
        S=A[0][0];
        return(S);
    }
    else{
        for(g=0;g<n;g++){
            S=S+pow(-1,g)*A[0][g]*det(submatrix(A,0,g));
        }
        return(S);
    }
}

int main(){
    int i,j,choice;
    printf("in main\n");
    double** A;
    double** B;
    double** C;
    int rowsA,colsA;
    label:
    printf("enter number of rows of matrix A ");
    scanf("%d",&rowsA);
    printf("enter number of cols of matrix A ");
    scanf("%d",&colsA);
    A=make(rowsA,colsA);
    int rowsB,colsB;
    printf("enter number of rows of matrix B ");
    scanf("%d",&rowsB);
    printf("enter number of cols of matrix B ");
    scanf("%d",&colsB);
    B=make(rowsB,colsB);
    printf("matrix A is\n");
    output(A);
    printf("matrix B is\n");
    output(B);
    label1:
    printf("enter 1 to add A+B\nenter 2 to multiply AB\nenter 3 to multiply BA\n");
    printf("enter 4 to transpose A\nenter 5 to transpose B\n");
    /*printf("enter 6 for det(A)\nenter 7 for det(B)\n");*/
    printf("enter 0 to quit\nenter -1 to define new matrices\n");
    scanf("%d",&choice);
    if(choice==0)
        return 0;
    else if(choice==1){
        printf("A+B is\n");
        C=add(A,B);
    }
    else if(choice==2){
        printf("AB is\n");
        C=prod(A,B);
    }
    else if(choice==3){
        printf("BA is\n");
        C=prod(B,A);  
    }
    else if(choice==4){
        printf("A transpose is\n");
        C=transpose(A);
    }
    else if(choice==5){
        printf("B transpose is\n");
        C=transpose(B);
    }
    /*
    else if(choice==6){
        printf("determinant of A is  ");
        printf("%lf\n",det(A));
        goto label1;
    }
    else if(choice=7){
        printf("determinant of B is  ");
        printf("%lf\n",det(B));
        goto label1;
    }
    */
    else if(choice==-1)
        goto label;
    output(C);
goto label1;
    //printf("\n%d\n%d",sizeof(B),sizeof(B[0]));//does'nt work
    /*find another way to get size of matrix*/
}



