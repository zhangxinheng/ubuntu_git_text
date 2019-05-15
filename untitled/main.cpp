#include <iostream>
#include<stdlib.h>
#include"SortTextHelper.h"
#include"Student.h"
using namespace std;
template<typename T>
void selectorSort(T arr[],int n)
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
    {
        for(int j=i;j>0&&arr[j]<arr[j-1];j--)
        {

                swap(arr[j],arr[j-1]);

        }
    }
}
int main() {
    int n=10000;
    int *arr=SortTextHelper::generateRandomArray(n,0,n);
    selectorSort(arr,n);
    SortTextHelper::printArray(arr,n);
    cout<<endl;
//    Student d[4]={{"D",90},{"B",80},{"C",100},{"A",50}};
//    selectorSort(d,4);
//    for(int i=0;i<4;i++)
//    {
//        cout<<d[i];
//    }
    int * arr2=SortTextHelper::copyIntArray(arr,n);
    SortTextHelper::textSort("Selection sort",selectorSort,arr,n);
    SortTextHelper::textSort("Insert sort",insertSort,arr2,n);

    delete [] arr;
    delete []arr2;
    return 0;
}