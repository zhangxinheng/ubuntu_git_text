#include <iostream>
#include<stdlib.h>
#include"SortTextHelper.h"
#include"Student.h"
using namespace std;
template<typename T>
void selectorSort(T arr[],int n)//选择排序
{
    for(int i=0;i<n;i++)
    {
        int minIndex=i;
        for(int j=i+1;j<n;j++)

            if(arr[j]<arr[minIndex])
                minIndex=j;

        swap(arr[i],arr[minIndex]);
    }
}
template<typename T>//插入排序
void insertSort(T arr[],int n)
{
    for(int i=1;i<n;i++)
    {//寻找元素arr【i】合适的插入位置
        T e=arr[i];
        int j;//j保存元素e应该插入的位置
        for(j=i;j>0&&arr[j-1]>e;j--)//提前终止是插入排序的一大优点，节省时间
        {

            arr[j]=arr[j-1];

        }
        arr[j]=e;
    }
}
template <typename T>
void insertionSort(T arr[],int l,int r)
{
    for(int i=l;i<=r;i++)
    {
        T e=arr[i];
        int j;
        for(j=i;j>l&&arr[j-1]>e;j--)
            arr[j]=arr[j-1];
        arr[j]=e;
    }
    return;
}
template <typename T>
void __merge(T arr[],int l,int mid,int r)//将arr【l，mid】和[min+1,r]两部分进行归并
{
    T aux[r-l+1];

    for(int i=l;i<=r;i++)
        aux[i-l]=arr[i];
    int i=l,j=mid+1;
    for(int k=l;k<=r;k++)
    {
        if(i>mid)
        {
            arr[k]=aux[j-l];
            j++;
        }
        else if(j>r)
        {
            arr[k]=aux[i-l];
            i++;
        }
        else if(aux[i-l]<aux[j-l])
        {
            arr[k]=aux[i-l];
            i++;
        }
        else
        {
            arr[k]=aux[j-l];
            j++;
        }
    }
}
template<typename T>
void __mergeSort(T arr[],int l,int r){//递归使用归并排序，对arr【l，r】的范围进行排序
//if(l>=r)
//  return;
    if(r-l<=16) {
        insertionSort(arr,l,r);
        return;
    }
    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    if(arr[mid]>arr[mid+1])
        __merge(arr, l, mid, r);



}

template<typename T>
void mergeSort(T arr[],int n)//归并排序
{
    __mergeSort(arr,0,n-1);

}
template <typename T>
void mergeSortBU(T arr[],int n){//自底向上进行归并排序
    for(int sz=1;sz<=n;sz+=sz)
        for(int i=0;i+sz<n;i+=sz+sz)
            __merge(arr,i,i+sz-1,min(i+sz+sz-1,n-1));

}

template <typename T>
int __partition(T arr[],int l,int r){//返回p，使得arr[p]>arr[l,p-1];arr[p+1,r]>arr[p]
   swap(arr[l],arr[rand()%(r-l+1)+l]);
    T v=arr[l];
    //arr[l+1...j]<v;arr[j+1...r)>v。i是当前考察的元素
    int j=l;
    for(int i=l+1;i<=r;i++)
    {
        if(arr[i]<v){
            swap(arr[j+1],arr[i]);
            j++;
        }
    }
    swap(arr[l],arr[j]);
    return j;
}

template <typename T>
void __quickSort(T arr[],int l,int r){
//    if(l>=r)
//        return;
    if(r-l<=15)
    {
        insertionSort(arr,l,r);
        return;
    }
    int p=__partition(arr,l,r);
    __quickSort(arr,l,p-1);
    __quickSort(arr,p+1,r);
}

template <typename T>
void quickSort(T arr[],int n)//快速排序
{
    srand(time(NULL));
    __quickSort(arr,0,n-1);
}

template <typename T>
int __partition2(T arr[],int l,int r){
    swap(arr[l],arr[rand()%(r-l+1)+l]);
    T v=arr[l];
    //arr[l+1...i)<=v;arr(j...r]>=v
    int i=l+1,j=r;
    while(true)
    {
        while(i<=r&&arr[i]<v)i++;
        while(j>=l+1&&arr[j]>v)j--;
        if(i>j)break;
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    swap(arr[l],arr[j]);
    return j;
}
template <typename T>
void __quickSort2(T arr[],int l,int r){
    if(r-l<=15){
        insertionSort(arr,l,r);
        return;
    }
    int p=__partition2(arr,l,r);
    __quickSort(arr,l,p-1);
    __quickSort(arr,p+1,r);
}
template <typename T>
void quickSort2(T arr[],int n){
    srand(time(NULL));
    __quickSort2(arr,0,n-1);
}

template <typename T>
void __quickSortWays(T arr[],int l,int r){
    if(r-l<=15){
        insertionSort(arr,l,r);
        return;
    }
    swap(arr[l],arr[rand()%(r-l+1)+l]);
    T v=arr[l];
    int lt=l;//arr[l+1,lt]<v
    int gt=r+1;//arr[gt...r]>v
    int i=l+1;//arr[lt+1...i]=v
    while(i<gt){
        if(arr[i]<v){
            swap(arr[i],arr[lt+1]);
            lt++;
            i++;
        }
        else if(arr[i]>v){
            swap(arr[i],arr[gt-1]);
            gt--;
        }
        else{
            i++;
        }
    }
    swap(arr[l],arr[lt]);
    __quickSortWays(arr,l,lt-1);
    __quickSortWays(arr,gt,r);
}
template <typename T>
void quickSortWays(T arr[],int n){//三路快速排序方法，>v,=v,<v
    srand(time(NULL));
    __quickSortWays(arr,0,n-1);
}
int main() {
    int n=100000;
    int *arr= SortTextHelper::generateRandomArray(n, 0, 10);
//    selectorSort(arr,n);
//    SortTextHelper::printArray(arr,n);
//    cout<<endl;
//    mergeSortBU(arr,n);
//    SortTextHelper::printArray(arr,n);
    int * arr2=SortTextHelper::copyIntArray(arr,n);
    int * arr3=SortTextHelper::copyIntArray(arr,n);

    SortTextHelper::textSort("merge sort",mergeSort,arr,n);
    SortTextHelper::textSort("quick sort",quickSortWays,arr2,n);
    //SortTextHelper::textSort("quick sort2",quickSort2,arr3,n);

    delete [] arr;
    delete []arr3;
    delete[] arr2;

    return 0;
}