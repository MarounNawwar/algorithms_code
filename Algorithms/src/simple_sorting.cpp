#include <iostream>
using namespace std;

void swap(int* a,int* b);
void bubbleSort(int* a,int N);
void bubbleSortAdv(int*a ,int N);
void insertionSort(int* a,int N);
void selectionSort_asc(int* a,int N);
void selectionSort_desc(int* a,int N);

int main(){

    //Write the code to try a sorting algorithm
    return 0;

}

void swap(int* a,int* b){
    int tmp;
    tmp = *a; *a = *b; *b = tmp;
}

// Complexity : Teta(N^2)
void bubbleSort(int* a,int N){
    for(int i = 1; i <= N-1; i++)
        for(int j = 0; j < N-i; j++)
            if(a[j] >= a[j+1])
                swap(&a[j-1],&a[j]);
}

// Complexity : O(N^2) | Omega(N)
void bubbleSortAdv(int* a,int N){
    bool changed = false;
    for(int i = 1; i <= N-1; i++){
        for(int j = 0; j < N-i; j++){
            if(a[j] >= a[j+1]){
                changed = true;
                swap(&a[i-1],&a[i]);
            }
        }
        if(!changed) break;
    }        
}

// Complexity : Teta(N^2)
void selectionSort_asc(int* a,int N){
    int min;
    for(int i = 0; i < N; i++){
        min = i;
        for(int j = i+1; j < N; j++)
            if(a[j] < a[min])
                min = j;
        swap(&min,&a[i]);
    }
}

// Complexity : Teta(N^2)
void selectionSort_desc(int* a,int N){
    int min;
    for(int i = N-1; i > 0; i--){
        min = i;
        for(int j = i-1; j > 0; j--)
            if(a[j] < a[min])
                min = j;
        swap(&a[min],&a[i]);
    }
}

// Complexity : O(N), Teta(N^2), Omega(O^2)
void insertionSort(int* a,int N){
    for(int i = 1; i < N; i++){
        for(int j = i; j > 0; j--){
            if(a[j] < a[j-1]){
                swap(&a[j],&a[j-1]);
            }else{
                break;
            }
        }
    }
}