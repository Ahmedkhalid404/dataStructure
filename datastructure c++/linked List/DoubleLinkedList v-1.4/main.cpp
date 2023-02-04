#include <iostream>
#include "DoubleLinkedList.h"
using namespace std;

int main()
{
    int b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q;
    DoubleLinkedList<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    a.print_forward();cout<<endl;
    a.print_backward();

    return 0;
}
