#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <bits/stdc++.h>
using namespace std;

template<class Type>
class DoubleLinkedList
{
private:
    struct node{
        Type value;
        node *next;
        node *prev;
    };
    int siz;
    node *head;
    //helping function
    void setValues(){
        siz = 0;
        head = NULL;
    }
public:
    //start constructor
    DoubleLinkedList(){
        setValues();
    }
    //end constructor
    //distructor
    ~DoubleLinkedList(){
        clear();
    }
    //*************************************************
    //start functions
    bool isEmpty(){
        return !siz;
    }
    //**********************************
    //**********************************
    bool isFull(){
        return false;
    }
    //**********************************
    //**********************************
    int size(){
        return siz;
    }
    //**********************************
    //**********************************
    bool add(Type value , int pos){
        if( pos < 0 || pos > siz )
            return false;
        node *pNewNode = new node;
        pNewNode->value = value;

        if( isEmpty() ){
            head = pNewNode;
            pNewNode->next = pNewNode;
            pNewNode->prev = pNewNode;
        }
        else if( !pos ){
            head->prev->next = pNewNode;
            pNewNode->prev = head->prev;
            head->prev = pNewNode;
            pNewNode->next = head;
            head = pNewNode;
        }
        else{
            node *cur = head;
            for( int i = 0 ; i < ( pos - 1 ) ; i ++ ){
                cur = cur->next;
            }
            cur->next->prev = pNewNode;
            pNewNode->next = cur->next;
            pNewNode->prev = cur;
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
        if( isEmpty() )
        {
            head            = pNewNode;
            pNewNode->next  = pNewNode;
            pNewNode->prev  = pNewNode;
        }
        else{
            head->prev->next    = pNewNode;
            pNewNode->prev      = head->prev;
            head->prev          = pNewNode;
            pNewNode->next      = head;
            head                = pNewNode;
        }
        siz++;
        return true;
    }
    //**********************************
    //**********************************
    bool push_back(Type value){
        node *pNewNode = new node;
        pNewNode->value = value;
        if( isEmpty() )
        {
            head            = pNewNode;
            pNewNode->next  = pNewNode;
            pNewNode->prev  = pNewNode;
        }
        else{
            node *cur = head->prev;
            cur->next->prev = pNewNode;
            pNewNode->next = cur->next;
            pNewNode->prev = cur;
            cur->next = pNewNode;
        }
        siz++;
        return true;
    }
    //**********************************
    //**********************************
    bool front(Type &value){
        if( isEmpty() )
            return false;

        value = head->value;
        return true;
    }
    //**********************************
    //**********************************
    bool back(Type &value){
        if( isEmpty() )
            return false;
        value = head->prev->value;
        return true;
    }
    //**********************************
    //**********************************
    void print_forward( string split = "," , string start = "[" , string end = "]" ){
        cout<<start;
        node *cur = head;
        for(int i=0 ; i < (siz - 1) ; i++){
            cout<<cur->value<<split;
            cur = cur->next;
        }
        if( !isEmpty() )
            cout<<head->prev->value;
        cout<<end;
    }
    //**********************************
    //**********************************
    void print_backward( string split = "," , string start = "[" , string end = "]",int ln = 0 ){
        cout<<start;
        node *cur = head->prev;
        for(int i= siz - 1 ; i > 0 ; i--){
            cout<<cur->value<<split;
            cur = cur->prev;
        }
        if( !isEmpty() )
            cout<<head->value;
        cout<<end;
        if( ln )
            cout<<endl;z
    }
    //**********************************
    //**********************************
    bool remove(Type &value ,int pos){
        if( isEmpty() )
            return false;
        if( ( pos < 0 ) || ( pos > (siz -1) ) )
            return false;
        if( siz == 1 )
        {
            delete head;
            head = NULL;
        }
        else if( !pos ){
            node *cur = head;
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head             = head->next;
            cur->next = NULL;
            cur->prev = NULL;
            delete cur;
        }
        else if( pos == ( siz - 1 ) )
        {
            node *cur               = head->prev;
            head->prev->prev->next  = head;
            head->prev              = head->prev->prev;
            cur->next = NULL;
            cur->prev = NULL;
            delete cur;
        }
        else{
            node *cur = head;
            for(int i=0;i< ( pos - 1 ) ; i++ ){
                cur = cur->next;
            }
            node *temp = cur->next;
            cur->next->next->prev = cur;
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
        if( siz == 1 )
        {
            delete head;
            head = NULL;
        }
        else{
            node *cur = head;
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head             = head->next;
            cur->next = NULL;
            cur->prev = NULL;
            delete cur;
        }
        siz--;
        return true;
    }
    //**********************************
    //**********************************
    bool pop_back(Type &value){
        if( isEmpty() )
            return false;
        if( siz == 1 )
        {
            delete head;
            head = NULL;
        }
        else
        {
            node *cur               = head->prev;
            head->prev->prev->next  = head;
            head->prev              = head->prev->prev;
            cur->next = NULL;
            cur->prev = NULL;
            delete cur;
        }
        siz--;
        return true;
    }
    //**********************************
    //**********************************
    bool search(Type value , int & pos = -1){
        if( isEmpty() )
            return false;

        node *cur = head;
        for(int i=0 ; i < siz ; i++){
            if( value == cur->value )
            {
                pos = i;
                return true;
            }
            cur = cur->next;
        }
        pos = -1;
        return false;
    }
    //**********************************
    //**********************************
    bool reverse(){
        if( isEmpty() )
            return true;
        node *cur = head;
        node *temp,*last = head->prev;
        for(int i = 0;i < siz;i++){
            temp = cur->next;
            cur->next = cur->prev;
            cur->prev = temp;
            cur = cur->prev;
        }
        head = last;
    }
    //**********************************
    //**********************************
    void clear(){
        Type el;
        while( !isEmpty() )
        {
            pop_back( el );
        }
    }
    //**********************************
    //**********************************
    //end functions
};

#endif // DOUBLELINKEDLIST_H
