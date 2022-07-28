
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
Problem Statement:
Find Second largest element in an array

Ref: https://www.geeksforgeeks.org/find-second-largest-element-array/
Output:
Second Max Element: 34
Second Max Element: 5 
*/
void findSecondMaxElement(vector<int> a)
{
    int max1 = 0 , max2 = 0;
    
    for(int i = 0 ; i < a.size();i++)
    {
        if(max1 < a[i])
        {
            max2 = max1;
            max1 = a[i];
        }
        else if((a[i] < max1) && ( max2 < a[i]))
        {
            max2 = a[i];
        }
    }
    cout << "Second Max Element: " << max2 << endl; 
}
int main() {
    sliding_window_max();
    merge_sorted_arrays();
   
    vector<int> a = {12, 35, 1, 10, 34, 1};
    vector<int> b = {10,5,10};
    findSecondMaxElement(a);
    findSecondMaxElement(b);   

    return 0;
}
