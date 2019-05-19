//
// Created by scrapy on 19-5-19.
//

#ifndef UNTITLED2_HEAP_H
#define UNTITLED2_HEAP_H

#include <iostream>
#include <stdlib.h>
using namespace std;
template <typename Item>
class MaxHeap{
private:
    Item*data;
    int count;
    int capacity;
    void shiftUp(int k){
        while(k>1&&data[k/2]<data[k]){
            swap(data[k/2],data[k]);
            k/=2;
        }
    }
    void shiftDown(int k){
        while(2*k<=count){
            int j=2*k;
            if(j+1<=count&&data[j+1]>data[j]){
                j+=1;
            }
            if(data[k]>data[j]){
                break;
            }
            swap(data[k],data[j]);
            k=j;
        }
    }
public:
    MaxHeap(int capacity){
        data=new Item[capacity];
        count=0;
        this->capacity=capacity;
    }
    MaxHeap(Item arr[],int n){
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
    ~MaxHeap(){
        delete [] data;
    }
    int size(){
        return count;
    }
    bool isEmpty(){
        return count==0?true:false;
    }
    void insert(Item item){
        assert(count+1<=capacity);
        data[count+1]=item;
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
        Item ret=data[1];
        swap(data[1],data[count]);
        count--;
        shiftDown(1);
        return ret;
    }


};
#endif //UNTITLED2_HEAP_H
