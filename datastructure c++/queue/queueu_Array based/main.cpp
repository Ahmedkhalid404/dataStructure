#include <iostream>
#include<vector>
#include "queueu_Array.h"
using namespace std;

int main()
{
    queueu_Array<vector<int>> q(10);
    vector<int>n={1,2,3};
    q.enque( n );
    q.print();
    return 0;
}
