#include <iostream>
#include <vector>
using namespace std;
void BubbleSort(vector<long long>&numbers , const bool great = false );
int main()
{
    vector<long long> numbers = {4,3,345,34,6,56,5,675,76,76,546,00,566,4567,45,456,99};
    BubbleSort(numbers );
    for(auto it : numbers)
        cout<<it<<" ";
    return 0;
}
void BubbleSort(vector<long long>&numbers , const bool great ){
    for (int i = 0; i < numbers.size() - 1 ; ++i) {
        bool isSwap = false;
        for (int j = 0; j < numbers.size() - i - 1; ++j) {
            if( !great )
            {
                if( numbers[j] > numbers[j+1] )
                    swap( numbers[j] , numbers[j+1] ) , isSwap = true;
            }
            else
            {
                if( numbers[j] < numbers[j+1] )
                    swap( numbers[j] , numbers[j+1] ) , isSwap = true;
            }
        }
        if( !isSwap )
            break;
    }
}
