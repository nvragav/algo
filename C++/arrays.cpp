#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    cout << "\n>>> " << __func__ << "() >>>" << endl;
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
    cout << "\n>>> " << __func__ << "() >>>" << endl;
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

    cout << "\n>>> " << __func__ << "() >>>" << endl;                           
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
    cout << "\n>>> " << __func__ << "() >>>" << endl;
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
/*
Problem Statement:
Find subarray with given sum
--- Finding subarray for the sum 36 ---
No of subarrays 1
(1,2)
--- Finding subarray for the sum 35 ---
No of subarrays 2
(1,1)
(4,5)
--- Finding subarray for the sum 20 ---
No of subarrays 0

*/
void findSubarrayWithGivenSum(vector<int> v,int k)
{
    int sum = 0;
    vector<pair<int,int>> result;
    
    cout << "\n>>> " << __func__ << "() >>>" << endl;
    cout << "--- Finding subarray for the sum " << k << " ---" << endl;
    for(int i = 0 ; i < v.size();i++)
    {
        for(int j = i ; (j < v.size()) && (j >= 0  );j--)
        {
            sum += v[j];
            if( sum == k)
            {
                result.push_back(make_pair(j,i));
            }
        }
        sum = 0;
    }
    cout << "No of subarrays " << result.size() << endl;
    for(auto r : result)
        cout << "("<< r.first << "," << r.second << ")" << endl;
    
}

/*
Problem Statement:
 Remove Duplicates from Sorted Array
Ref:
 https://leetcode.com/problems/remove-duplicates-from-sorted-array/

*/
int  removeDuplicates(vector<int> &nums)
{
    cout << "\n>>> " << __func__ << "() >>>" << endl;
    cout << "--- Original Array ---" << endl;
    for(auto n : nums)
    {
        cout << n << "," ;
    }    
    cout << endl;
    
    for(auto it = nums.begin(); it != nums.end();it++ )
    {
        auto dupIt = it+1;
        
        for(;dupIt != nums.end() && (*(dupIt) == *(it));)
        {
            nums.erase(dupIt);
            dupIt = it+1;
        }
    }
    cout << "--- Modified Array ---" << endl;
    for(auto n : nums)
    {
        cout << n << "," ;
    }
    cout << endl;
    
    return(nums.size());
}
/*
Problem Statement: 
k largest(or smallest) elements in an array
Ref: 
https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/

*/
void findKLargestElements(vector<int> nums,int k)
{
    vector<int> res;
    int min = 0;
    cout << "\n>>> " << __func__ << "() >>>" << endl;
    cout << "--- Original Array ---" << endl;
    for(auto n : nums)
    {
        cout << n << "," ;
    }
    cout <<  " :: " << "\t K = " << k << endl;
    //Selection sort method - O(N^2)
    for(int i = 0 ; i < nums.size();i++)
    {
        min = i;
        for(int j = i+1; j < nums.size();j++)
        {
            if(nums[i] > nums[j])
                min = j;
        }
        if(min != i)
            swap(nums[i],nums[min]);
    }
    cout << "--- Sorted Array ---" << endl;
    for(auto n : nums)
    {
        cout << n << ","; 
    }
    cout << endl;
    cout << "--- Largest Elements ---" << endl;
    for(int j = nums.size()-1; ((nums.size()-1)-j) < k;j--)
    {
        res.push_back(nums[j]);
        cout << nums[j] << "," ;
    }
    cout << endl;
}
void findKLargestElementsUsingPq(vector<int> nums, int k)
{
    priority_queue<int> pq;
    int i = 0;
    cout << "\n>>> " << __func__ << "() >>>" << endl;
    cout << "--- Original Array ---" << endl;
    for(auto n : nums)
    {
        cout << n << "," ;
    }
    cout <<  " :: " << "\t K = " << k << endl;
    //Priority Queue Method.
    for(auto n : nums)
    {
        pq.push(n);
    }
    cout << "--- Largest Elements ---" << endl;
    for(int i =0 ; i < k ; i++)
    {
        cout << pq.top() << ",";
        pq.pop();
    }
    cout << endl;
}

bool findNoUsingBstInSortedArray(vector<int> v, int no)
{
    int low =0 , mid = 0 , high = v.size()-1;
    bool flag = false;
    cout << "\n>>> " << __func__ << "() >>>" << endl;
    cout << "Finding " << no << endl;
    
    while(low <= high)
    {
        mid = (high + low) / 2;
        if(v[mid] == no)
        {
             flag = true;
             break;
        }
        else if(no < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return (flag);
}
/*
OUTPUT:
------
>>> sliding_window_max() >>>
--- Sum of subarrays ---
3,3,4,5,5,5,6,

>>> merge_sorted_arrays() >>>
--- Merged Array ---
1,2,3,4,4,5,6,8,

>>> mergeListOfArrays() >>>
Total size 12
1 11 2 22 3 33 12 13 25 27 34 28 

>>> mergeListOfArrays() >>>
Total size 12
1 11 12 2 22 25 3 33 34 13 27 28 

>>> findSecondMaxElement() >>>
Second Max Element: 34

>>> findSecondMaxElement() >>>
Second Max Element: 5

>>> findSubarrayWithGivenSum() >>>
--- Finding subarray for the sum 36 ---
No of subarrays 1
(1,2)

>>> findSubarrayWithGivenSum() >>>
--- Finding subarray for the sum 35 ---
No of subarrays 2
(1,1)
(4,5)

>>> findSubarrayWithGivenSum() >>>
--- Finding subarray for the sum 20 ---
No of subarrays 0

>>> removeDuplicates() >>>
--- Original Array ---
0,0,1,1,1,2,2,3,3,4,
--- Modified Array ---
0,1,2,3,4,

>>> findKLargestElements() >>>
--- Original Array ---
1,23,12,9,30,2,50, :: 	 K = 3
--- Sorted Array ---
1,2,9,12,23,30,50,
--- Largest Elements ---
50,30,23,

>>> findKLargestElementsUsingPq() >>>
--- Original Array ---
1,23,12,9,30,2,50, :: 	 K = 3
--- Largest Elements ---
50,30,23,
--- Sorted array ----
1,2,9,12,23,30,50,

>>> findNoUsingBstInSortedArray() >>>
Finding 9
Found

>>> findNoUsingBstInSortedArray() >>>
Finding 10
Not Found

*/
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
   
    vector<int> a = {12, 35, 1, 10, 34, 1};
    vector<int> b = {10,5,10};
    findSecondMaxElement(a);
    findSecondMaxElement(b);   

    findSubarrayWithGivenSum(a,36);
    findSubarrayWithGivenSum(a,35);    
    findSubarrayWithGivenSum(b,20);

    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    removeDuplicates(nums);

    vector<int> nums1 = {1, 23, 12, 9, 30, 2, 50};
    findKLargestElements(nums1,3);
    findKLargestElementsUsingPq(nums1,3);

     std::sort(nums1.begin(),nums1.end());
    cout << "--- Sorted array ----" << endl;
    for(auto n : nums1)
        cout << n << ","; 
    cout << endl;
    cout << ((findNoUsingBstInSortedArray(nums1,9)) ? "Found" : "Not Found" ) << endl ;
    cout << ((findNoUsingBstInSortedArray(nums1,10)) ? "Found" : "Not Found") << endl ;
    return 0;

}
