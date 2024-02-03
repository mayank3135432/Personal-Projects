/*
Find the min distance from source vertex (zero) to every other vertex in graph
Using Dijkstra Algorithm
*/
#include<stdio.h>
#define MAX 5
#define X 10000

int cost[SIZE][SIZE]={/*cost adjacency matrix of given graph*/
    {X,10,5,X,X},
    {X,X,X,1,X},
    {X,3,X,9,2},
    {X,X,X,X,X},
    {2,X,X,6,X}
};//Output dist array must be {0,8,5,9,7}


int queue[SIZE];//Priority Queue
int rear=-1;
//priority of queue[i] is dist[queue[i]]
int dist[SIZE];//initialise in to {X} in main function
int visited[SIZE]={0};//marks vertices as visited or not;
int allvisited(){
    int i;
    int and=1;
    for(i=0;i<SIZE;i++){
        and=and&&visited[i];
    }
    return and;
}
int isfull();
int iskali();
void enqueue();
int peek();
int dequeue();
void display();

int iskali(){
    return(rear==-1);
}
int isfull(){
    return(rear==SIZE-1);
}
void enqueue(int x){
    if((isfull())){
        printf("\n________________________QUEUE OVERFLOW________________________\n");
        return;
    }
    rear++;
    queue[rear]=x;
}
int peek(){//returns index of lowest distance element in queue
    int i,ind=0;
    for(i=1;i<=rear;i++){
        if(dist[queue[i]]<dist[queue[ind]])
            ind=i;
    }
    return ind;
}
int dequeue(){//remove lowest distance vertex from queue and return vertex
    if(iskali()){
        printf("\n________________________QUEUE UNDERFLOW________________________\n");
        return 0;
    }
    int i,ind;
    ind=peek();
    int vertex=queue[ind];
    for(i=ind;i<rear;i++){
        queue[i]=queue[i+1];
    }
    rear--;
    return vertex;
}
void display(){
    if(iskali()){
        printf("\n{}\n");
        return;
    }
    int i;
    printf("\n{");
    for(i=0;i<=rear;i++){
        printf("%d,",queue[i]);
    }
    printf("\b}\n");
}

void dijkstra(){
    visited[0]=1;dist[0]=0;//taking 0 as initial source
    int u=0;
    int i,j;
    int counter=0;

    while(counter<10){
        /*PRINT DEBUGGING*/
        printf("%dthround\nbefore for:-\n",counter);
        printf("%d\n{",u);
        for(j=0;j<SIZE;j++) printf("%d,",visited[j]);
        printf("\b}");
        printf("\n{");
        for(j=0;j<SIZE;j++) printf("%d,",dist[j]);
        printf("\b}");
        display();
        printf("\n\n\n");
        /*END PRINT DEBUGGING*/

        for(i=0;i<SIZE;i++){
            if(cost[u][i]!=X){
                if(dist[u]+cost[u][i]<dist[i])
                    dist[i]=dist[u]+cost[u][i];//update dist between u and i
                if(!visited[i]){
                    enqueue(i);//queue up the i vertex if it has not already been visited
                    visited[i]=1;
                }
            }
        }

        /*PRINT DEBUGGING*/
        printf("after for:-\n");
        printf("%d\n{",u);
        for(j=0;j<SIZE;j++) printf("%d,",visited[j]);
        printf("\b}");
        printf("\n{");
        for(j=0;j<SIZE;j++) printf("%d,",dist[j]);
        printf("\b}");
        display();
        printf("\n\n\n");
        /*END PRINT DEBUGGING*/


        //if(allvisited()) return;//terminate loop when all vertices are vistied
        u=dequeue();//update source
        counter++;
    }
}
int main(){
    int i,j;for(i=0;i<SIZE;i++) dist[i]=X;
    dijkstra();
    printf("_______________________________________________________________________");
    printf("\n\n{");//print the distance array
        for(j=0;j<SIZE;j++) printf("%d,",dist[j]);
        printf("\b}");
    return 0;
}