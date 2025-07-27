#include <bits/stdc++.h>
using namespace std;

// +++++++++++++++++++++++ BRUTE FORCE +++++++++++++++++++++++++++++++++
// Approach:
// We can take another dummy array of the same length and then shift all elements in the array toward the left
// and then at the last element store the index of 0th index of the array and print it.

void leftRotatebyOne(int arr[], int n)
{
    int temp[n];
    for (int i = 1; i < n; i++)
    {
        temp[i - 1] = arr[i];
    }
    temp[n - 1] = arr[0];

    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}

// Time Complexity: O(n), as we iterate through the array only once.

// Space Complexity: O(n) as we are using another array of size, same as the given array.

//

// +++++++++++++++++++++++++++ OPTIMAL APPROACH +++++++++++++++++++++++++++++

void OptimalSol(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Time Complexity: O(n), as we iterate through the array only once.

// Space Complexity: O(1) as no extra space is used

int main()
{
    int n = 5;

    int arr[] = {1, 2, 3, 4, 5};
    leftRotatebyOne(arr, n);
    OptimalSol(arr, n);
}