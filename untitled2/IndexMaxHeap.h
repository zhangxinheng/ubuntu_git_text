//
// Created by scrapy on 19-5-20.
//

#ifndef UNTITLED2_INDEXMAXHEAP_H
#define UNTITLED2_INDEXMAXHEAP_H
#include <iostream>
#include <stdlib.h>
using namespace std;
template <typename Item>
class IndexMaxHeap{
private:
    Item*data;
    int* indexs;
    int count;
    int capacity;
    void shiftUp(int k){
        while(k>1&&data[indexs[k/2]]<data[indexs[k]]){
            swap(indexs[k/2],indexs[k]);
            k/=2;
        }
    }
    void shiftDown(int k){
        while(2*k<=count){
            int j=2*k;
            if(j+1<=count&&data[indexs[j+1]]>data[indexs[j]]){
                j+=1;
            }
            if(data[indexs[k]]>data[indexs[j]]){
                break;
            }
            swap(indexs[k],indexs[j]);
            k=j;
        }
    }
public:
    IndexMaxHeap(int capacity){
        data=new Item[capacity];
        count=0;
        indexs=new int[capacity+1];
        this->capacity=capacity;
    }
    IndexMaxHeap(Item arr[],int n){
        data=new Item[n+1];
        capacity=n;
        for(int i=0;i<n;i++){
            data[i+1]=arr[i];
        }
        count=n;
        for(int i=count/2;i>=1;i--){//count/2是最后一个不是叶子节点的节点
            shiftDown(i);
        }
    }
    ~IndexMaxHeap(){
        delete [] data;
        delete [] indexs;
    }
    int size(){
        return count;
    }
    bool isEmpty(){
        return count==0?true:false;
    }
    void insert(int i,Item item){//传入的i对用户而言是从0开始的
        assert(count+1<=capacity);
        assert(i+1>=1&&i+1<=capacity);
        data[i]=item;
        indexs[count+1]=i;
        count++;
        shiftUp(count);
    }
    void printnum(int capa){
        for(int i=1;i<=capa;i++){
            cout<<this->data[i]<<"--";
        }

    }
    Item extracMax(){
        assert(count>0);
        Item ret=data[indexs[1]];
        swap(indexs[1],indexs[count]);
        count--;
        shiftDown(1);
        return ret;
    }

    int extracMaxIndex(){//返回最大元素的索引，
        assert(count>0);
        int ret=indexs[1]-1;//对于用户来说索引是从0开始的
        swap(indexs[1],indexs[count]);
        count--;
        shiftDown(1);
        return ret;
    }
    Item getItem(int i){
        return data[i+1];
    }

    void change(int i,Item newItem){
        i+=1;
        data[i]=new Item;
        for(int j=1;j<+count;j++){
            if(indexs[j]==i){
                shiftUp(j);
                shiftDown(j);
                return;;
            }
        }
    }


};
#endif //UNTITLED2_INDEXMAXHEAP_H
