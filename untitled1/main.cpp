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
void __merge(T arr[],int l,int mid,int r)//将arr【l，mid】和[min+1,r]两部分进行归并
{
    T aux[r-l+1];

    for(int i=l;i<=r;i++)
    {
        aux[i-l]=arr[i];
    }
    int i=l,j=mid+1;
    for(int k=l;k<=r;k++)
    {
        if(i>mid)
        {
            arr[k]=arr[j-l];
            j++;
        }
        else if(j>r)
        {
            arr[k]=arr[i-l];
            i++;
        }
        if(aux[i-l]<aux[j-l])
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
void __mergeSort(T arr[],int l,int r)//递归使用归并排序，对arr【l，r】的范围进行排序
{
    if(l>=r)
        return;
    int mid = (l + r)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    //if(arr[mid]>arr[mid+1])
        __merge(arr, l, mid, r);



}

template<typename T>
void mergeSort(T arr[],int n)//归并排序
{
    __mergeSort(arr,0,n-1);

}
int main() {
    int n=50000;
    int *arr=SortTextHelper::generateRandomArray(n,0,n);
//    selectorSort(arr,n);
//    SortTextHelper::printArray(arr,n);
//    cout<<endl;
//    mergeSort(arr,n);
//    SortTextHelper::printArray(arr,n);
    int * arr2=SortTextHelper::copyIntArray(arr,n);
    SortTextHelper::textSort("merge sort",mergeSort,arr,n);
    SortTextHelper::textSort("Insert sort",insertSort,arr2,n);

    delete [] arr;
    delete []arr2;
    return 0;
}