#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BIGARRAY.h"
//int A[]={64,27,34,12,36,17,31,62,74,33,27,10,96,31,70,32,46,29,-1};

// int A[10]={15,5,24,8,1,3,16,10,20,-1};

int size(){
    int i;
    for (i = 0; A[i] != -1; i++);
    return (i);
}

void bsort(){ // swap elements into order
    int i, j, N, temp;
    int issorted = 1; // this is a modification to make b sort adaptive
    N = size();
    for (i = 0; i < N; i++){
        for (j = i + 1; j < N; j++){
            if (A[i] > A[j]){                // if A[i] is larger than A[j],
                temp = A[i]; // swap the two as A[j] deserves to be to the left of A[i]
                A[i] = A[j];
                A[j] = temp;
                issorted = 0; // if array is not already sorted, issorted will be 0
            }
        }
        if (issorted == 1)
            ; // If issorted stays 1, it means at no instance have we encountered A[i]>A[j].
              // this means that the array is already sorted and we can quit.
    }
}
void selsort(){ // O(n^2)
    int i, j, min, temp;
    int N = size();
    for (i = 0; i < N; i++){ // traverses array and exchanges ith element with smallest element occuring after i
        min = i;
        for (j = i + 1; j < N; j++){
            if (A[min] > A[j])
                min = j; // find the index of smallest element to the right of i;
        }
        if (min != i){ // swap A[i] and A[min]
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}
void FAILEDinsort(){
    int j, k, temp;
    int SIZE = size();
    for (j = 1; j < SIZE; j++){
        for (k = j - 1; k > -1; k--){
            if (A[j] < A[k])
                continue;
            else
                break;
        }
    }
    temp = A[j];
    A[j] = A[k];
    A[k] = temp;
}
void insort(){ // insertion sort:shift elements into order
    int i, j, temp;
    int SIZE = size(); //{4,2,7,1,3,-1}
    for (i = 1; i < SIZE; i++){                // build's up a sorted array from the left to right
        temp = A[i]; // store ith value at temp
        for (j = i - 1; j >= 0; j--){
            if (A[j] > temp)     // if temp is lesser than jth element
                A[j + 1] = A[j]; // shift A[j] one unit to the right
            else
                break;
        }
        A[j + 1] = temp; // put temp in it's correct position
    }
    // insertion sort has worst case O(n^2) [n-1 + n(n-1)/2 passes]
    //                    best case O(n) [n-1 passes]
    // insertion sort is adaptive(can see if array is sorted) and stable(preserves order of identical keys)
}

int partition_old(int left, int right){
    int pivot = A[right];
    int i = left - 1;
    int temp;

    for (int j = left; j < right; j++){
        if (A[j] <= pivot){//>= for desc <= for asc
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    temp = A[i + 1];
    A[i + 1] = A[right];
    A[right] = temp;

    return (i + 1);
}

void quicksortold(int left, int right){
    if (left >= right)
        return;
    int piv;
    piv = partition_old(left, right);
    quicksortold(left, piv - 1);
    quicksortold(piv, right);
}

/*QUICKSORT
quicksort is divide-and-conquer algorithm that divides an array into 2 by
selecting a pivot element and keeping it in it's supposed place.
It's best and avg case time complexity is O(n*log(n))
It's worst case is when the array is already sorted/anti-sorted
    worst case time complexity in O(n^2)
It is not stable
might be adaptive ??
It's space complexity(excluding function call stack) is O(1)
*/
//int counter=0; variable for debugging
int partition(int lb,int ub);

void quicksort(int lb,int ub){
    if(lb>=ub) return;
    int piv=partition(lb,ub);
    quicksort(lb,piv-1);
    quicksort(piv+1,ub);
    //run quicksort again an A[lb:piv-1] and A[piv+1:ub];
    //Exclude piv element itself, it has already been sorted in place
    //Including piv might lead to an infinite loop
}

int partition(int lb,int ub){
    //printf("-----%d-----(lb:%d,ub:%d)\n",counter++,lb,ub);//debug line
    int start=lb,end=ub;
    int piv=lb;
    int temp;
    while(start<end){
        while(A[start]<=A[piv] && start<ub) start++;
        while(A[end]>A[piv]) end--;
        if(start<=end){
            temp=A[start];
            A[start]=A[end];
            A[end]=temp;
        }
    }
    temp=A[piv];
    A[piv]=A[end];
    A[end]=temp;
    return end;
}
/*MERGE - SORT
divide array into subarrays and merge them back in a sorted manner
msort() is the driving function for sorting.
It recursivly divides arraay in halves till subarray size becomes 1
Then they are merged back using merge() function
Merge sort uses external space

*/
void merge(int lb, int mid, int ub);



void msort(int lb, int ub){//O(n*log(n))
    if (!(lb < ub)) return;

    // int mid=(lb+ub)/2;
    msort(lb, (lb + ub) / 2);//merge sort first half of array
    msort((lb + ub) / 2 + 1, ub);//merge sort the other half
    merge(lb, (lb + ub) / 2, ub);//merge the arrays back
}
void merge(int lb, int mid, int ub){//merges subarray A[lb:mid] and subarray A[mid+1:ub]
    int *B = (int *)malloc((ub - lb + 1) * sizeof(int));//create temporary array to contain values of A
    for (int i = 0; i <= ub - lb; i++){
        B[i] = A[lb + i];
    }
    /*i keeps count for for B[lb:mid]
    j keeps count for B[mid=1:ub]
    k keeps count for A[]*/
    int i = 0; // lb-lb
    int j = mid + 1 - lb;
    int k = lb;
    /*Traverse each half of the array B with i,j*/
    while ((j <= ub-lb) && (i <= mid-lb)){
        //Push in the smaller element out of ith and jth index of B into A 
        if (B[i] <= B[j]){
            A[k] = B[i];
            i++;k++;
        }
        else{
            A[k] = B[j];
            j++;k++;
        }
        //repeat till an end of either subarray is reached 
    }
    //then push all remaining elements of the subarray whose end has'nt been reached into A
    if (j > ub - lb){
        while (i <= mid - lb){
            A[k] = B[i];
            i++;k++;
        }
    }
    if (i > mid - lb){
        while (j <= ub - lb){
            A[k] = B[j];
            j++;k++;
        }
    }
    free(B);//free the temporary array B
}

int main(){
    int N = size();
    int i;
    printf("%d",N);//Array has N number of elements (N+1 if you include sentinel "-1")
    // insort();
    int choice;
    printf("\n\nENTER 1 FOR BUBBLE SORT\nENTER 2 FOR QUICKSORT\nENTER 3 FOR MERGE SORT\n");
    scanf("%d",&choice);
    printf("\n\n");
    clock_t begin=clock();
    switch (choice){
    case 1:
        bsort();
        break;
    case 2:
        quicksort(0,N-1);
        break;
    case 3:
        msort(0,N-1);
        break;
    default:
        //printf("enter valid number \n");
        //return 0;
        break;
    }

    clock_t end=clock();

    //bsort();
    // msort(0,N-1);
    // insort();
    double timetaken=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("time taken is %lf second\n\n",timetaken);
    printf("\nenter 1 to deiplay sorted array\nenter 2 to not");
    scanf("%d",&choice);
    if(choice>1) return 0;
    printf("{");
    for (i = 0; i < N; i++){
        printf("%d,", A[i]);
    }
    printf("\b}\n");
    //printf("time taken is %lf second\n\n",timetaken);

    return 0;
}
