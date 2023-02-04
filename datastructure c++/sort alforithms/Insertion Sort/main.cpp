#include <iostream>
#include <vector>
using namespace std;
void InsertionSort(vector<long long>&numbers);
int main()
{
    vector<long long> numbers = {4,3,345,34,6,56,5,675,76,76,546,00,566,4567,45,456,99};
    InsertionSort(numbers );
    for(auto it : numbers)
        cout<<it<<" ";
    return 0;
}
/*
    Time    :  O(n^2)
    Space   :  O(1)
*/
void InsertionSort(vector<long long>&numbers){
    for (int i = 1; i < numbers.size() ; ++i) {
        for (int j = i; j > 0; --j) {
            if(  numbers[j] >= numbers[j-1]  )
                break;

            swap( numbers[j] , numbers[j-1]  );
        }
    }
}
