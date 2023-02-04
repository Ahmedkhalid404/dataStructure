#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<stdlib.h>
#include<malloc.h>

using namespace std;


template<class Type>
class stack
{
private:
    struct node{
        Type value;
        node *next;
    };
    node *top,*cur;
    int siz;

public:
    //start constructor
    stack(){
        top     = NULL;
        siz    = 0;
    }
    //end constructor
    //******************************************
    //start functions
    int size(){
        return siz;
    }
    //***********************
    //***********************
    bool isEmpty(){
        return !siz;
    }
    //***********************
    //***********************
    bool isFull(){
        return false;
    }
    //***********************
    //***********************
    bool push(Type value){
        node *New_Node = new node;
        if( New_Node == NULL )
            return false;
        New_Node->value = value;
        New_Node->next = top;
        top = New_Node;
        siz++;
        return true;
    }
    //***********************
    //***********************
    bool pop(Type & value){
        if( isEmpty() ){
            return false;
        }
        else{
            node *temp  = top;
            top         = top->next;
            value       = temp->value;
            temp->next = NULL;
            delete temp;
            siz--;
            return true;
        }
    }
    //***********************
    //***********************
    bool getTop(Type &value){
        if( isEmpty() ){
            return false;
        }
        else{
            value = top->value;
            return true;
        }
    }
    //***********************
    //***********************
    void traverse(void(*operation)(Type&)){
        cur = top;
        while(cur){
            (*operation)(cur->value);
            cur = cur->next;
        }
    }
    //***********************
    //***********************
    bool max_element(Type &value){
        if(!isEmpty())
        {
            value = top->value;
            if( top->next == NULL )
            {
                return true;
            }
            node *cur = top->next;
            while(cur){
                if( value < cur->value )
                    value = cur->value;
                cur = cur->next;
            }
            return true;
        }
        return false;
    }
    //***********************
    //***********************
    bool min_element(Type &value){
        if(!isEmpty())
        {
            value = top->value;
            if( top->next == NULL )
            {
                return true;
            }
            node *cur = top->next;
            while(cur){
                if( value > cur->value )
                    value = cur->value;
                cur = cur->next;
            }
            return true;
        }
        return false;
    }
    //***********************
    //***********************
    void print(string c = ","){
        cout<<"[";
        cur = top;
        while(cur){
            cout<<cur->value;
            cur = cur->next;
            if(cur)
                cout<<c;
        }
        cout<<"]";
    }
    //***********************
    //***********************
    static bool areBalanced(string exp){
        stack<char> s;
        for(int i=0;i<exp.size();i++)
        {
            if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[' )
                s.push(exp[i]);
            else
            {
                if( s.isEmpty() ){
                    return false;
                }
                char pracket = '*' ; s.getTop(pracket);
                if( exp[i] == ')' ){
                    if(pracket == '('){
                        s.pop( *(new char) );
                    }
                    else{
                        return false;
                    }

                }
                else if( exp[i] == '}' ){
                    if(pracket == '{'){
                        s.pop( *(new char) );
                    }
                    else{
                        return false;
                    }
                }
                else if( exp[i] == ']' ){
                    if(pracket == '['){
                        s.pop( *(new char) );
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return s.isEmpty();
    }
    //***********************
    //***********************
    //end functions
};

#endif // STACK_H
