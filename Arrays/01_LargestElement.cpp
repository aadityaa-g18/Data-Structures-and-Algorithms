// Find Largest Element in an array

#include <bits/stdc++.h>
using namespace std;

/*  ------ BRUTE FORCE O(nlogn)

int sortArr(vector<int> arr){
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr.begin(), arr.end());
    return arr[arr.size()-1];
}
*/

// ---------- O(n) 
int LargestEle(vector<int> arr)
{
    int size = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    vector<int> arr1 = {2, 5, 1, 3, 0};
    vector<int> arr2 = {8, 10, 5, 7, 9};

    // cout << sortArr(arr1) << endl;
    cout << LargestEle(arr1) << endl;
}