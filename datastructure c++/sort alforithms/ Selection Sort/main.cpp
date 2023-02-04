#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<long long> &numbers ,const bool great = false);
int main()
{
    vector<long long> numbers = {60,40,50,50,23,45,56,5,34,433,34,30,10,20};
    selectionSort(numbers );
    for(auto it : numbers)
        cout<<it<<" ";
    return 0;
}
//selectionSort
/*
    Time    : O(n^2)
    Space   : O(n)
*/
void selectionSort(vector<long long> &numbers ,const bool great){
    long long Idx ;
    for (int i = 0; i < numbers.size() - 1; ++i) {
        Idx = i;
        for (int j = i+1; j < numbers.size(); ++j) {
            if( !great )
            {
                if( numbers[j] < numbers[ Idx ] )
                {
                    Idx = j;
                }
            }
            else
            {
                if( numbers[j] > numbers[ Idx ] )
                {
                    Idx = j;
                }
            }
        }
        swap( numbers[i] , numbers[ Idx ] );
    }
}

