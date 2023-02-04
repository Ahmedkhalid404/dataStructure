#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;

template<class Type>
class queue_
{
private:
    struct node{
        Type value;
        node *next;
    };
    node *front;
    node *rear;
    node *cur;
    int siz;
    //helping function
    void resetValues(){
        front   = NULL;
        rear    = NULL;
        siz     = 0;
    }
public:
    //start constructor
    queue_(){
        resetValues();
    }
    queue_(int size,Type value){
        resetValues();
        if( size <= 0 )
            size = 16;
        for(int i=0;i<size;i++)
        {
            enque(value);
        }
    }
    //end constructor
    //************************************************************
    //start functions
    bool isEmpty(){
        return !siz;
    }
    //********************************
    //********************************
    bool isFull(){
        return false;
    }
    //********************************
    //********************************
    int size(){
        return siz;
    }
    //********************************
    //********************************
    //int maxSize(){
    //  return MAX_SIZE;
    //}
    //********************************
    /* we don't have max size */
    //********************************
    bool enque( Type value ){
        node *pNewNode = (node*) malloc(sizeof(node));
        pNewNode->value = value;

        if( isEmpty() )
            front = pNewNode;

        else
            rear->next = pNewNode;

        rear = pNewNode;
        pNewNode->next = NULL;
        siz++;
        return true;
    }
    //********************************
    //********************************
    bool deque(Type &value ){
        if( isEmpty() )
            return false;
        value = front->value;
        cur = front;
        front = front->next;

        if( siz == 1 )
            rear = NULL;

        delete cur;
        siz--;
        return true;
    }
    //********************************
    //********************************
    bool getFront(Type &value){
        if( isEmpty() )
            return false;

        value = front->value;
        return true;
    }
    //********************************
    //********************************
    bool getRear(Type &value){
        if( isEmpty() )
            return false;

        value = rear->value;
        return true;
    }
    //********************************
    //********************************
    void print(string split = ",",string start = "[",string end = "]"){
        cout<<start;
        cur = front;
        while( cur != rear && cur ){
            cout<<cur->value<<split;
            cur = cur->next;
        }
        if(rear)
            cout<<rear->value;
        cout<<end;
    }
    //********************************
    //********************************
    void clear(){
        while( front ){
            cur = front;
            front = front->next;
            delete cur;
        }
        resetValues();
    }
    //********************************
    //********************************
    bool search(Type value,int &pos ){
        if( isEmpty() )
            pos = -1;
        int i = 0;
        cur = front;
        while( cur != rear && cur ){
            i++;
            if( cur->value == value )
            {
                pos = i;
                return true;
            }
            cur = cur->next;
        }
        if( rear->value == value )
        {
            pos = i + 1;
            return true;
        }
        pos = -1;
        return false;
    }
    //end functions
};
/*


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
#endif // QUEUE_H
