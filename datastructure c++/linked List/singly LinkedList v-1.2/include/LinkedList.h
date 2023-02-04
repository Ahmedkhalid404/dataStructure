#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
template<class Type>
class singlyLinkedList
{
private:
    struct node{
        Type value;
        node *next;
    };
    node *head,*cur;
    int siz;
    void resetValues(){
        siz = 0;
        head = NULL;
    }
public:
    //start constructor
    singlyLinkedList(){
        resetValues();
    }
    //end constructor
    //destructor
    ~singlyLinkedList(){
        clear();
    }
    //**********************************************************
    //start functions
    bool isEmpty(){
        return !siz;
    }
    //**********************************
    //**********************************
    bool isFull(){
        return 0;
    }
    //**********************************
    //**********************************
    int size(){
        return siz;
    }
    //**********************************
    //**********************************
    bool add(Type value,int pos){
        if( pos < 0 || pos > siz )
            return false;
        node *pNewNode = new node;
        pNewNode->value = value;
        cur = head;
        if( !pos )
        {
            head = pNewNode;
            pNewNode->next = cur;
        }
        else
        {
            for(int i = 0 ; i < (pos-1) ; i++){
                cur = cur->next;
            }
            pNewNode->next = cur->next;
            cur->next = pNewNode;
        }
        siz++;
        return true;
    }
    //**********************************
    //**********************************
    bool push_front(Type value){
        node *pNewNode = new node;
        pNewNode->value = value;
        cur = head;
        head = pNewNode;
        pNewNode->next = cur;
        siz++;
        return true;
    }
    //**********************************
    //**********************************
    bool remove(Type &value , int pos ){
        if( isEmpty() )
            return false;
        if( ( pos < 0 )|| ( pos > (siz-1) ) )
            return false;

        cur = head;
        if( !pos ){
            head = head->next;
            delete cur;
        }
        else{
            int newPos = pos - 1;
            for(int i= 0 ; i < newPos ; i++){
                cur = cur->next;
            }
            node *temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
        siz--;
        return true;

    }
    //**********************************
    //**********************************
    bool pop_front(Type &value){
        if( isEmpty() )
            return false;
        cur = head;
        head = head->next;
        delete cur;
        siz--;
        return true;
    }
    //**********************************
    //**********************************
    void print(string split = ",",string start = "[",string end = "]"){
        cout<<start;
        if( !isEmpty() )
        {
            cur = head;
            int newSize = siz - 1;
            for(int i=0 ; i < newSize ; i++ ){
                cout<<cur->value<<split;
                cur = cur->next;
            }
            cout<<cur->value;
        }
        cout<<end;
    }
    //**********************************
    //**********************************
    void reverse(){
        if( siz <= 1 )
            return ;
        cur = head;
        node *n = head,*prev = NULL;
        while( n->next ){
            n = n->next;
            cur->next = prev;
            prev = cur;
            cur = n;
        }
        cur->next = prev;
        head = cur;
        return ;
    }
    //**********************************
    //**********************************
    bool find(Type value,int &pos){
        if( isEmpty() )
            {
                pos = -1;
                return false;
            }
        cur = head;
        int i=0;
        while( cur->next ){
            if(cur->value == value)
            {
                pos = i;
                return true;
            }
            cur = cur->next;
            i++;
        }
        if( cur->value == value )
        {
            pos = i;
            return true;
        }
        pos = -1;
        return false;
    }
    //**********************************
    //**********************************
    bool at(Type &value , int pos){
        if( ( isEmpty() ) || ( pos < 0 )|| ( pos > size()-1 ) )
            {
                value = *(new Type);
                return false;
            }
        cur = head;
        int i=0;
        while( cur->next ){
            if( i == pos )
            {
                value = cur->value;
                return true;
            }
            cur = cur->next;
            i++;
        }
        value = cur->value;
        return true;
    }
    //**********************************
    //**********************************
    void clear(){
        cur = head;
        while( cur )
        {
            head = head->next;
            delete cur;
            cur = head;
        }
        head = NULL;
        siz = 0;
    }
    //**********************************
    //**********************************
    void sort(const int gre = 0){//if gre == 0 sort will inc ----  otherwise dec
        int s = size();
        cur = head;
        for(int i=0;i<s;i++){
            Type minNumbers;
            node *minNode,*m = cur;
            for( int j = i ; j < s ; j++ ){
                if( i == j )
                {
                    minNumbers = cur->value;
                    minNode    = cur;
                }
                else{
                    if( !gre )
                    {
                        if( minNumbers > m->value ){
                            minNumbers = m->value;
                            minNode    = m;
                        }
                    }
                    else
                    {
                        if( minNumbers < m->value ){
                            minNumbers = m->value;
                            minNode    = m;
                        }
                    }

                }
                m = m->next;
            }
            Type temp = minNode->value;
            minNode->value = cur->value;
            cur->value = temp;
            cur = cur->next;
        }
    }
    //**********************************
    //**********************************
    void max_element(Type &value){
        if( isEmpty() )
            {
                value = *(new Type);
                return;
            }
        cur = head;
        value = cur->value;
        while( cur->next )
        {
            cur = cur->next;
            if( value < cur->value )
                    value = cur->value;
        }
    }
    //**********************************
    //**********************************
    void min_element(Type &value){
        if( isEmpty() )
            {
                value = *(new Type);
                return;
            }
        cur = head;
        value = cur->value;
        while( cur->next )
        {
            cur = cur->next;
            if( value > cur->value )
                    value = cur->value;
        }
    }
    //**********************************
    //**********************************
    void traverse(void(*operation)(Type&)){
        int s = size();
        cur = head;
        for(int i=0;i<s;i++){
            (*operation)(cur->value);
            cur  = cur->next;
        }
    }
    //**********************************
    //**********************************
    bool updateAt(Type value,int pos){
        if( ( isEmpty() ) || ( pos < 0 )|| ( pos > size()-1 ) )
            {
                value = *(new Type);
                return false;
            }
        int s = size();
        cur = head;
        for(int i=0;i<s;i++){
            if( pos == i )
                return cur->value = value,true;
            cur = cur->next;
        }
    }
    //**********************************
    //**********************************
    void operator = (singlyLinkedList a){
        if( this == (&a) )
        {
            cout<<"here";
            return;
        }
        int i = 0;
        int thisSize = size();
        int Asize    = a.size();

        if( thisSize > Asize )
            clear() , thisSize = 0 ;

        node * thisPointer = head , *Apointer = a.head;
        for( ; i < thisSize ; i++ ){
            thisPointer->value = Apointer->value;
            thisPointer = thisPointer->next;
            Apointer = Apointer->next;
        }
        for( ; i < Asize ; i++ )
        {
            add( Apointer->value , i );
            Apointer = Apointer->next;
        }
    }
    //**********************************
    //**********************************

    //end functions

};

#endif // LINKEDLIST_H
