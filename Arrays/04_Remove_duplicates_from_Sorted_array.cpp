#include <bits/stdc++.h>
using namespace std;

// ++++++++++++++++++ BRUTE FORCE USING HASHSET ++++++++++++++++++++
/*
int removeDuplicates(int vec[], int n)
{
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(vec[i]);
    }

    int k = st.size();
    int j = 0;
    for (int x : st)
    {
        vec[j++] = x;
    }
    return k;
}
*/

// Time complexity: O(n*log(n))+O(n)

// Space Complexity: O(n) 

// ++++++++++++++++++++ OPTIMAL APPROACH TWO POINTERS +++++++++++++++++++++++++++

int removeDuplicates(int arr[], int n){
    int i = 0;
    for (int j = 1; j < n;j++){
        if(arr[i]!=arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }

    return i + 1;
}

// Time Complexity: O(N)

// Space Complexity: O(1)

int main()
{
    int arr[] = {1, 1, 2, 2, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = removeDuplicates(arr, n);
    cout << "The array after removing duplicate elements is " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
}