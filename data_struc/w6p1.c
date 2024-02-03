#include<stdio.h>
#include<stdlib.h>
int main(){
    int m,n,r,i,j,k;
    int*** A;
    printf("enter value of m ");
    scanf("%d",&m);
    printf("enter value of n ");
    scanf("%d",&n);
    printf("enter value of r ");
    scanf("%d",&r);
    A=(int***)malloc(m*sizeof(int**));
    for(i=0;i<m;i++){
        A[i]=(int**)malloc(n*sizeof(int*));
        for(j=0;j<n;j++){
            A[i][j]=(int*)malloc(r*sizeof(int));
        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            for(k=0;k<r;k++){
                printf("enter element (%d,%d,%d) ",i,j,k);
                scanf("%d",&A[i][j][k]);
            }
        }
    }

    for(k=0;k<r;k++){
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                printf("%d, ",A[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
}