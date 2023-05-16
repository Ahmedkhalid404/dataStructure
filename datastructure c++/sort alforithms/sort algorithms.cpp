#include <bits/stdc++.h>
using namespace std;
#define HelloWorld(x)           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<< fixed <<showpoint <<setprecision(7)
#define ln                      '\n'
typedef long long               ll;

/*
 * BubbleSort
                Time :
                            Best    : Ω( n ) "when array is sorted"
                            Average : Θ( n ^ 2 )
                            Worst   : O( n ^ 2 )
                Memory :    1
                Stable :    YES
 */
void BubbleSort(vector<ll>&numbers){
    ll size = numbers.size();
    ll cnt = 0;
    for (int i = 0; i < size; ++i) {
        bool isSwap = false;
        for (int j = 0; j < size - 1 - cnt; ++j) {
            if( numbers[j] > numbers[j+1] )
            {
                isSwap = true;
                swap( numbers[j] , numbers[j + 1] );
            }
        }
        if( !isSwap )
            break;
        cnt++;
    }
}

/*
 * SelectionSort
                Time :
                            Best    : Ω( n ^ 2 )
                            Average : Θ( n ^ 2 )
                            Worst   : O( n ^ 2 )
                Memory :    1
                Stable :    NO
 */
void SelectionSort(vector<ll>&numbers){
    ll size = numbers.size();
    for (int i = 0; i < size; ++i) {
        ll mn = i;
        for (int j = i + 1; j < size; ++j) {
            if( numbers[j] < numbers[ mn ] )
            {
                mn = j;
            }
        }
        swap( numbers[mn] , numbers[i] );
    }
}


/*
 * InsertionSort
                Time :
                            Best    : Ω( n ) "when array is sorted"
                            Average : Θ( n ^ 2 )
                            Worst   : O( n ^ 2 )
                Memory :    1
                Stable :    YES
 */
void InsertionSort(vector<ll>&numbers){
    ll size = numbers.size();
    for (int i = 1; i < size; ++i) {
        for (int j = i; j > 0; --j) {
            if( numbers[j] < numbers[j - 1] )
                swap( numbers[j] , numbers[j - 1] );
            else
                break;
        }
    }
}


/*
 * MergeSort
                Time :
                            Best    : Ω( n log( n ) )
                            Average : Θ( n log( n ) )
                            Worst   : O( n log( n ) )
                Memory :    O( n )
                Stable :    YES
 */

void Merg(vector<ll>&numbers,ll l,ll md,ll r)
{
    ll sizeLeftSide = md - l + 1;
    ll sizeRightSide = r - md;
    vector<ll>leftSide( sizeLeftSide ) , rightSide( sizeRightSide );
    for (int i = l; i <= md; ++i) {
        leftSide[i - l] = numbers[i];
    }
    for (int i = md + 1; i <= r; ++i) {
        rightSide[i - ( md + 1 )] = numbers[i];
    }
    ll idxOfLeftSide = 0 , idxOfRightSide = 0;
    ll idxOfOriginArr  = l;
    while( (idxOfLeftSide < sizeLeftSide) && (idxOfRightSide < sizeRightSide) )
    {
        if( leftSide[ idxOfLeftSide ] < rightSide[ idxOfRightSide ] )
        {
            numbers[ idxOfOriginArr ] = leftSide[ idxOfLeftSide ];
            idxOfLeftSide++;
        }
        else
        {
            numbers[ idxOfOriginArr ] = rightSide[ idxOfRightSide ];
            idxOfRightSide++;
        }
        idxOfOriginArr++;
    }
    while( idxOfLeftSide < sizeLeftSide )
    {
        numbers[ idxOfOriginArr ] = leftSide[ idxOfLeftSide ];
        idxOfLeftSide++;
        idxOfOriginArr++;
    }
    while( idxOfRightSide < sizeRightSide )
    {
        numbers[ idxOfOriginArr ] = rightSide[ idxOfRightSide ];
        idxOfRightSide++;
        idxOfOriginArr++;
    }
}
void MergeSort(vector<ll>&numbers,ll l,ll r){
    if( l < r )
    {
        ll md = (l + r) / 2;
        MergeSort(numbers,l,md);
        MergeSort(numbers,md+1,r);
        Merg(numbers,l,md,r);
    }
}


/*
 * Quicksort
                Time :
                            Best    : Ω( n log( n ) )
                            Average : Θ( n log( n ) )
                            Worst   : O( n ^ 2 ) "when array is sorted"
                Memory :    1
                Stable :    NO
 */

//std::random_device rd;
//std::mt19937 gen(rd());
//ll random(int low, int high)
//{
//    std::uniform_int_distribution<> dist(low, high);
//    return dist(gen);
//}
void Quicksort(vector<ll>&numbers,ll l,ll r){
    if( l < r )
    {
//        ll pivot = numbers[random(l,r)]; //can use random pivot to avoid worst case

//        ll pivot = numbers[ ( l + r ) / 2 ] //can use middle pivot to avoid worst case
        ll pivot = numbers[ l ];
        ll i = l;
        ll j = r;
        while( i != j )
        {
            if( numbers[ i ] != pivot )
            {
                if( numbers[i] > numbers[j] )
                {
                    swap( numbers[i] , numbers[j] );
                }
                else
                    i++;
            }
            else
            {
                if( numbers[i] > numbers[j] )
                {
                    swap( numbers[i] , numbers[j] );
                }
                else
                    j--;
            }
        }
        Quicksort(numbers,0,i);
        Quicksort(numbers,i + 1,r);
    }
}

int main() {
    HelloWorld('♡');
    vector<ll>numbers = {90,80,70,60,50,40,87,90,0,-55,30,20,10,-5,66};
    //BubbleSort( numbers );
    //SelectionSort( numbers );
    //InsertionSort( numbers );
    //MergeSort( numbers , 0 , numbers.size() - 1 );
    Quicksort(numbers , 0 ,numbers.size() - 1 );
    for(auto it : numbers)
        cout<<it<<" ";

    return 0 ;
}
