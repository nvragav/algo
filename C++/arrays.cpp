/* Problem Statement:
   Given an array and an integer K, find the maximum for each and
   every contiguous subarray of size k.
   Ref: https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> result;
    int a[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int i=0,j=0,k=3,max=0;
    int size = sizeof(a)/sizeof(a[0]);
    
    for(i = k-1; i < size ; i++)
    {
        max = a[i];
        for(j = i-1; (j-i < k) && (j >= 0); j--)
        {
            if(max < a[j])
                max = a[j];
        }
        result.push_back(max);
    }
    for(int i = 0; i < result.size();i++)
    {
        cout << result[i] << "," ;
    }
    cout << endl;
    

    return 0;
}
