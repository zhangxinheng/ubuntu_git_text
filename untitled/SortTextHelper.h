//
// Created by scrapy on 19-5-15.
//
#include<iostream>
#include<ctime>
#include<cassert>
#include<stdlib.h>
#include <time.h>
using namespace std;
#ifndef UNTITLED_SORTTEXTHELPER_H
#define UNTITLED_SORTTEXTHELPER_H
namespace SortTextHelper{
    int * generateRandomArray(int n,int rangeL,int rangeR)
    {
        assert(rangeL<=rangeR);//　assert的作用是先计算表达式 expression ，如果其值为假（即为0），那么它先向stderr打印一条出错信息，然后通过调用 abort 来终止程序运行
        int *arr=new int[n];
        srand((unsigned )time(NULL));//以时间作为随机数的种子
        for(int i=0;i<n;i++)
        {
            arr[i]=rand() % (rangeR-rangeL+1)+rangeL;//使得生成的随机数在rangeL和rangeR之间
            return arr;
        }
    }
    template<typename T>
    void printArray(T arr[],int n)
    {
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        return;
    }
    template<typename T>
    bool isSorted(T arr[],int n)
    {
        for(int i=0;i<n-1;i++)
            if(arr[i]>arr[i+1])
                return false;
         return true;
    }
    template<typename T>
    void textSort(string sortName,void(*sort)(T[],int),T arr[],int n)
    {
        clock_t starttime=clock();
        sort(arr,n);
        clock_t endtime=clock();
        assert(isSorted(arr,n));
        cout<<sortName<<" : "<<double(endtime-starttime)/CLOCKS_PER_SEC<<"s"<<endl;
        return;
    }
    int* copyIntArray(int a[],int n)
    {
        int *arr=new int[n];
        copy(a,a+n,arr);
        return arr;
    }
}
#endif //UNTITLED_SORTTEXTHELPER_H
