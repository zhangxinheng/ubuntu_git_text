#include <iostream>
#include<stdlib.h>
#include"SortTextHelper.h"
#include"Student.h"
#include "Heap.h"
using namespace std;
template <typename T>
void heapSortOne(T arr[],int n){
    MaxHeap<T>  maxheap = MaxHeap<T>(n);
    for(int i=0;i<n;i++){
        maxheap.insert(arr[i]);
    }
    for(int i=n-1;i>=0;i--){
        arr[i]=maxheap.extracMax();
    }
}

template <typename T>
void heapSortTwo(T arr[],int n){
    MaxHeap<T> maxHeap=MaxHeap<T>(arr,n);
    for(int i=n-1;i>=0;i--){
        arr[i]=maxHeap.extracMax();
    }
}

template <typename T>
void __shiftDown(T arr[],int n,int k){
    while(2*k+1<n){
        int j=2*k+1;
        if(j+1<n&&arr[j+1]>arr[j]){
            j+=1;
        }
        if(arr[k]>arr[j]){
            break;
        }
        swap(arr[k],arr[j]);
        k=j;
    }
}
template <typename T>
void heapSort(T arr[],int n){
    for(int i=(n-1)/2;i>=0;i--){
        __shiftDown(arr,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        __shiftDown(arr,i,0);
    }
}
int main() {
    int n=100000;
    int *arr1= SortTextHelper::generateRandomArray(n, 0, 10);
    int *arr2=SortTextHelper::copyIntArray(arr1,n);
    int *arr3=SortTextHelper::copyIntArray(arr1,n);

//    MaxHeap<int> maxheap=MaxHeap<int>(100);
//    srand(time(NULL));
//    for(int i=0;i<15;i++){
//        maxheap.insert(rand()%100);
//    }
//    cout<<maxheap.size();
//    cout<<endl;
//    maxheap.printnum(15);
    SortTextHelper::textSort("heap SortOne",heapSortOne,arr1,n);
    SortTextHelper::textSort("heap Sort Two",heapSortTwo,arr2,n);
    SortTextHelper::textSort("heap Sort",heapSort,arr3,n);
    delete [] arr1;
    delete[] arr2;//qwer98@ke.Q
    delete [] arr3;
    return 0;
}