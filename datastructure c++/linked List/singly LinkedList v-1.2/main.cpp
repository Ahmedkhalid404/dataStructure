#include <iostream>
#include "LinkedList.h"
using namespace std;
int main()
{
    singlyLinkedList<int> a;
    a.add(1,a.size());
    a.add(2,a.size());
    a.add(3,a.size());
    a.add(4,a.size());
    a.add(5,a.size());
    a.add(6,a.size());
    a.add(7,a.size());
    a.remove( *(new int) , a.size() - 1 );
    a.print();
    cout<<endl;
    a.remove( *(new int) , 4 );
    a.print();
    return 0;
}
