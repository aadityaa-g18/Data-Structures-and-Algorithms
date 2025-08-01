#include <bits/stdc++.h>
using namespace std;

// ++++++++++++++++ Hashing Using Map +++++++++++++++++++++++++

int getSingleElement(vector<int> arr)
{
    map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
    return 0;
}

// time complexity --> O(N*logM) + O(M) N --> inserting N elements, insertion in map take logM M --> size of map
// space complexity --> O(M); // using MAP

// ++++++++++++++++++ USING XOR +++++++++++++++++++++++

int removeDuplicates(vector<int> arr)
{
    int XOR = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        XOR = XOR ^ arr[i];
    }
    return XOR;
}

// Time Complexity: O(N), where N = size of the array.
// Reason: We are iterating the array only once.

// Space Complexity: O(1) as we are not using any extra space.

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    // int ans = getSingleElement(arr);
    int ans = removeDuplicates(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}