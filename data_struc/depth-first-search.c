#include<stdio.h>
#include<stdlib.h>
void DFS(int** G,int root,int size,int* visited){
    //static int* visited=(int*)malloc(size*sizeof(int));
    visited[root]=1;
    printf("%d,",root);
    int i;
    for(i=0;i<size;i++){
        if(G[root][i] && !visited[i]) DFS(G,i,size,visited);
    }
    return;
}
int main(){
    int i,j;
    int G[7][7]={{0,1,0,1,0,0,0},
                 {1,0,1,1,0,1,0},
                 {0,1,0,1,1,1,0},
                 {1,1,1,0,1,0,0},
                 {0,0,1,1,0,0,1},
                 {0,1,1,0,0,0,0},
                 {0,1,0,0,1,0,0},
                 };
                 
    int** P=(int**)malloc(7*sizeof(int*));for(i=0;i<7;i++){*(P+i)=(int*)malloc(7*sizeof(int));}
    for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            P[i][j]=G[i][j];
        }
    }
    /* int* ptempG=G[0];
    int** pG=&ptempG; */
    int arr[7]={0,0,0,0,0,0,0};
    DFS(P,0,7,arr);

    return 0;

    
}