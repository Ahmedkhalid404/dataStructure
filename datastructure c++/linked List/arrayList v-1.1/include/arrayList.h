#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include<bits/stdc++.h>
#include<stdlib.h>
#include<malloc.h>
using namespace std;

template<class Type>
class arrayList
{
private:
    Type *items;
    int MAX_SIZE;
    int length;
public:
    //start constructor
    arrayList(int size = 100,int value = 0){
        length = -1;
        if( size <= 0 )
            size = 100;
        MAX_SIZE = size;
        items = new Type[ MAX_SIZE ];
        fill_n( items , size , value );// to set all indexes in array = value
    }
    //end constructor
    //***********************************************************************************
    //start function
    bool isEmpty(){
        return length == -1;
    }
    //****************************************
    //****************************************
    bool isFull(){
        return length == MAX_SIZE - 1;
    }
    //****************************************
    //****************************************
    int size(){
        return length + 1;
    }
    //****************************************
    //****************************************
    void print(string split = "," , string start = "[" ,string end = "]"){
        cout<<start;
        for(int i=0;i<length;i++)
        {
            cout<<items[i]<<split;
        }
        if( !isEmpty() )
            cout<<items[length];
        cout<<end;
    }
    //****************************************
    //****************************************
    void setValue( int len , Type value ){
        if( len <= length + 1 )
            fill_n( items , len , value );
    }
    //****************************************
    //****************************************
    void clear(){
        length = -1;
    }
    //****************************************
    //****************************************
    bool add( Type value , int pos )
    {
        if( isFull() )
            return false;
        if( pos < 0 || pos > length + 1 || pos > MAX_SIZE - 1 )
            return false;
        if( pos == length + 1 )
        {
            length++;
            items[ length ] = value;
            return true;
        }
        for( int i = length+1;i > pos ;i-- )
        {
            items[ i ] = items[ i - 1 ];
        }
        length++;
        items[ pos ] = value;
        return true;
    }
    //****************************************
    //****************************************
    bool add_No_Duplicate( Type value , int pos )
    {
        if ( !search( value , *( new Type ) ) )
        {
            add( value , pos );
            return true;
        }
        return false;
    }
    //****************************************
    //****************************************
    bool push_back(Type value){
        if( isFull() )
            return false;
        length++;
        items[ length ] = value;
        return true;
    }
    //****************************************
    //****************************************
    bool remove( Type &value , int pos ){
        if( isEmpty() )
            return false;
        if( pos > length )
            return false;
        if( pos < 0 )
            pos = pos + size();
        value = items[ pos ];
        for(int i = pos ; i < length ; i++){
            items[i] = items[i+1];
        }
        length--;
        return true;
    }
    //****************************************
    //****************************************
    bool pop_back( Type &value ){
        if( isEmpty() )
            return false;
        value  = items[ length ] ;
        length--;
        return true;
    }
    //****************************************
    //****************************************
    bool search( Type value , int & pos ){
        for( int i=0 ; i <= length ; i++ ){
            if( items[i] == value )
              return  pos = i ,true;
        }
        pos = -1;
        return false;
    }
    //****************************************
    //****************************************
    //random access
    Type operator[](int pos){
        if( pos <= length && pos >= 0 )
        {
            return items[pos];
        }
        return *(new Type);
    }
    //****************************************
    //****************************************
    bool updateAt( Type value , int pos )
    {
        if( pos >= 0 && pos <= length )
            return items[ pos ] = value,true;
        return false;
    }
    //****************************************
    //****************************************
    bool Sort(int len , int greater = 0 ){
        if( isEmpty() )
            return false;
        if( !greater )
        {
            sort( items , items + len );
        }
        else{
            sort( items , items + len );
            reverse( items , items + len );
        }
        return true;
    }
    //****************************************
    //****************************************
    bool Reverse(int len){
        if( isEmpty() )
            return false;
        reverse( items , items + len );
        return true;
    }
    //****************************************
    //****************************************
    ~arrayList(){
        delete[]items;
    }
    //end function

};

#endif // ARRAYLIST_H
