#ifndef QUEUEU_ARRAY_H
#define QUEUEU_ARRAY_H

#include<iostream>
#include<cassert>
using namespace std;

template<class Type>
class queueu_Array
{
private:
    int MAX_SIZE ;
    int     front;
    int     rear;
    int     siz;
    Type    *items;
    //helping functions
    void resetValues(){
        front = 0;
        rear = MAX_SIZE - 1;
        siz = 0;
    }
public:
    //start constructor
    queueu_Array(int size = 100){
        if( size <= 0 )
            size = 100;
        items = new Type[ size ];
        MAX_SIZE = size;
        resetValues();
    }
    //********************************
    //********************************
    queueu_Array(int size,Type value){
        if( size <= 0 )
            size = 100;
        resetValues();
        items = new Type[ size ];
        MAX_SIZE = size;
        for(int i=0;i<size;i++){
            enque(value);
        }
    }
    //en d constructor
    //**************************************************************
    //start functions
    bool isEmpty(){
        return !siz;
    }
    //********************************
    //********************************
    bool isFull(){
        return siz == MAX_SIZE;
    }
    //********************************
    //********************************
    int size(){
        return siz;
    }
    //********************************
    //********************************
    int maxSize(){
        return MAX_SIZE;
    }
    //********************************
    //********************************
    bool enque( Type value ){
        if( isFull() ){
            return false;
        }
        else{
            rear = (rear + 1) % MAX_SIZE;
            items[ rear ] = value;
            siz++;
            return true;
        }
    }
    //********************************
    //********************************
    bool deque( Type &value ){
        if( isEmpty() )
        {
            return false;
        }
        else{
            value = items[ front ];
            front = (front + 1) % MAX_SIZE;
            siz--;
            return true;
        }
    }
    //********************************
    //********************************
    bool getFront(Type &value){
        if( isEmpty() )
        {
            return false;
        }
        else{
            value = items[ front ];
            return true;
        }
    }
    //********************************
    //********************************
    bool getRear(Type &value){
        if( isEmpty() )
        {
            return false;
        }
        value = items[ rear ];
    }
    //********************************
    //********************************
    void print(string split = ",",string start = "[",string end = "]"){
        cout<<start;
        if( !isEmpty() ){
            for(int i = front; i != rear ;i = (i+1)%MAX_SIZE  ){
                    cout<<items[i]<<split;
            }
            cout<<items[ rear ];
        }
        cout<<end;
    }
    //********************************
    //********************************
    void clear(){
        resetValues();
    }
    //********************************
    //********************************
    bool search(Type value,int &pos ){
        if( isEmpty() )
            return pos = -1,false;
        for(int i = front,j = 1 ; j < MAX_SIZE ; i = (i + 1)% MAX_SIZE,j++){
            if( items[i] == value )
            {
                pos = j;
                return true;
            }
        }
        if( items[rear] == value )
            {
                pos = MAX_SIZE;
                return true;
            }
        pos = -1;
        return false;
    }
    //end functions
    //**************************************************************
};
/*
queueu_Array(int size = 100);
void resetValues();
queueu_Array(int size,Type value);
bool isEmpty();
    //********************************
    //********************************
    bool isFull();
    //********************************
    //********************************
    int size();
    //********************************
    //********************************
    int maxSize();
    //********************************
    //********************************
    bool enque( Type value );
    //********************************
    //********************************
    bool deque( Type &value );
    //********************************
    //********************************
    bool getFront(Type &value);
    //********************************
    //********************************
    bool getRear(Type &value);
    //********************************
    //********************************
    void print(string split = ",",string start = "[",string end = "]");
    //********************************
    //********************************
    void clear();
    //********************************
    //********************************
    bool search(Type value,int &pos );
*/
#endif // QUEUEU_ARRAY_H
