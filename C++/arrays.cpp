
#include <iostream>
#include <vector>
using namespace std;

/* Problem Statement:
   Given an array and an integer K, find the maximum for each and
   every contiguous subarray of size k.
   Ref: https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
*/
int sliding_window_max()
{
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
    cout << "--- Sum of subarrays ---" << endl;
    for(int i = 0; i < result.size();i++)
    {

        cout << result[i] << ",";
    }
    cout << endl;    

    return 1;
}

/* Problem Statement:
   Given two sorted arrays, the task is to merge them in a sorted manner.
   Ref: https://www.geeksforgeeks.org/merge-two-sorted-arrays/
*/
int merge_sorted_arrays()
{
    // Write C++ code here
    int arr1[] = { 1, 3, 4,5}, arr2[] = {2, 4, 6,8};
    vector<int> result;
    int i = 0, j = 0;
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    
    for(i = 0; (i < size1) && (j < size2);)
    {
        if(arr1[i] < arr2[j])
        {
            result.push_back(arr1[i]);
            i++;
        }
        else if(arr2[j] < arr1[i])
        {
            result.push_back(arr2[j]);
            j++;
        }
        else 
        {
            result.push_back(arr1[i]);
            result.push_back(arr2[j]);
            i++; j++;
        }
    }
    if(i == size1)
    {
        for(; j < size2; j++)
            result.push_back(arr2[j]);
    }
    if(j == size2)
    {
        for(; i < size1; i++)
            result.push_back(arr1[i]);
    }
    
    cout << "--- Merged Array ---" << endl;
    for(int i = 0 ; i < result.size();i++)
    {
        cout << result[i] << "," ;
    }
    cout << endl;    
}
/*
Input: 
{{1,11,12,13},
 {2,22,25,27,28},
 {3,33,34}}
Output:
Total size 12
1 11 2 22 3 33 12 13 25 27 34 28 
Total size 12
1 11 12 2 22 25 3 33 34 13 27 28 
*/
void mergeListOfArrays(vector<vector<int>> vv, vector<int> &result, size_t l)
{
    int iter = 0;
    int tot_size = 0;
                           
    for(int i = 0; i < vv.size();i++)
    {
        tot_size += vv[i].size();
    }
    cout << "Total size " << tot_size << endl;
    /* Traverse until all the elements are inserted */
    while( result.size() < tot_size)
    {
        /* Traverse each and every row */
        for(int j = 0; j < vv.size(); j++)
        {
            if(iter <= vv[j].size())
            {
                if( (iter + l) <= vv[j].size())
                    result.insert(result.begin()+result.size(),vv[j].begin()+iter,vv[j].begin()+iter+l);
                else /* Boundary condition */ 
                    result.insert(result.begin()+result.size(),vv[j].begin()+iter,vv[j].end());  
            }
        }
        iter += l;
    }    
    for(auto &c : result)
    {
        cout << c << " " ;
    }      
}
int main() {
    vector<int> result;
    vector<vector<int>> vv= {{1,11,12,13},
                             {2,22,25,27,28},
                             {3,33,34}};    
      
    sliding_window_max();
    merge_sorted_arrays();
    
    mergeListOfArrays(vv,result,2);
    result.clear();
    mergeListOfArrays(vv,result,3);   
    
    
    return 0;
}
