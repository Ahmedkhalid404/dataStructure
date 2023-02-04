#include <iostream>
#include "arrayList.h"

using namespace std;

int main()
{
    arrayList<int> a(10);
    a.push_back( 6 );
    a.push_back( 5 );
    a.push_back( 4 );
    a.push_back( 3 );
    a.push_back( 2 );
    a.push_back( 1 );
    cout<<a.add_No_Duplicate( 1 , a.size())<<endl;
    a.print();
    return 0;
}
