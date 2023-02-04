#include <iostream>
#include "stack_Array.h"
using namespace std;

void print(long long &el){
    cout<<el<<endl;
}

int main()
{
    stack_Array<long long> s;
    s.push(45);
    s.push(50);
    s.push(55);
    s.push(60);
    s.push(65);
    s.push(70);
    s.push(75);
    long long value ;
    s.min_element(value);
    cout<<value;
    return 0;
}
