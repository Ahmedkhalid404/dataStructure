#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
#include<iostream>
using namespace std;
template<class Type>
class stack_Array
{
private:
    static const int MAX_SIZE = 100;
    int top;    //semi pointer refer to last value pushed
    Type items[MAX_SIZE];

public:
    //start constructors
    stack_Array(){
        top = -1;
    }
    //end constructors
    //*********************************************
    //start functions
    bool push(Type value){
        if( isFull() )
        {
            return false;
        }
        else
        {
            top++;
            items[ top ] = value;
            return true;
        }
    }
    //**************************
    //**************************
    bool pop(Type & value){
        if( top < 0 )
        {
            return false;
        }
        else
        {
            value = items[ top ];
            top--;
            return true;
        }
    }
    //**************************
    //**************************
    bool getTop(Type &value){
        if( isEmpty() )
        {
            return false;
        }
        else
        {
            value = items[top];
            return true;
        }

    }
    //**************************
    //**************************
    bool isEmpty(){
        return (top == -1);
    }
    //**************************
    //**************************
    bool isFull(){
        return (top == MAX_SIZE-1);
    }
    //**************************
    //**************************
    int maxSize(){
        return MAX_SIZE;
    }
    //**************************
    //**************************
    int size()
    {
        return (top+1);
    }
    //**************************
    //**************************
    void print(){
        cout<<"[";
        for(int i= size()-1 ;i > 0; i--)
        {
            cout<<items[i]<<",";
        }
        cout<<items[0];
        cout<<"]";
    }
    //**************************
    //**************************
    void traverse(void (*operatio)(Type&))
    {
        for(int i = size()-1 ; i > -1 ; i--)
        {
            (*operatio)(items[i]);
        }
    }
    //**************************
    //**************************
    bool max_element(Type &value)
    {
        if( isEmpty() )
            return false;
        else
        {
            value = items[size()-1];
            for(int i = size()-2 ; i > -1 ; i--)
            {
                if( value < items[i] )
                    value = items[i];
            }
            return true;
        }

    }
    //**************************
    //**************************
    bool min_element(Type &value)
    {
        if( isEmpty() )
            return false;
        else
        {
            value = items[size()-1];
            for(int i = size()-2 ; i > -1 ; i--)
            {
                if( value > items[i] )
                    value = items[i];
            }
            return true;
        }

    }
    //**************************
    //**************************
    //end functions
    //*********************************************

};

#endif // STACK_ARRAY_H
