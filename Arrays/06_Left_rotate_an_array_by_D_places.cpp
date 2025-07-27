#include <bits/stdc++.h>
using namespace std;

// +++++++++++++++++++ BRUTE FORCE +++++++++++++++++++++++++++++
/*
 Approach 1: Using a temp array

 For Rotating the Elements to right
 Step 1: Copy the last k elements into the temp array.

 Step 2: Shift n-k elements from the beginning by k position to the right

 Step 3: Copy the elements into the main array from the temp array.
*/
void Rotatetoright(int arr[], int n, int k)
{
    if (n == 0)
    {
        return;
    }
    k = k % n;
    if (k > n)
    {
        return;
    }
    int temp[k];
    for (int i = n - k; i < n; i++)
    {
        temp[i - n + k] = arr[i];
    }
    for (int i = n - k - 1; i >= 0; i--)
    {
        arr[i + k] = arr[i];
    }
    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
}

// Time Complexity: O(n)
// Space Complexity: O(k) since k array element needs to be stored in temp array

/*
For Rotating the Elements to left
Step 1: Copy the first k elements into the temp array.

Step 2: Shift n-k elements from last by k position to the left

Step 3: Copy the elements into the main array from the temp array.
*/

void RotatetoLeft(int arr[], int n, int k)
{
    if (n == 0)
    {
        return;
    }
    k = k % n;
    if (k > n)
    {
        return;
    }
    int temp[k];
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = 0; i < n - k; i++)
    {
        arr[i] = arr[i + k];
    }
    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - n + k];
    }
}

// +++++++++++++++++++++++++ BETTER APPROACH +++++++++++++++++++++++++++++
/*
Approach:

For Rotating Elements to right
Step 1: Reverse the last k elements of the array

Step 2: Reverse the first n-k elements of the array.

Step 3: Reverse the whole array.

For Eg , arr[]={1,2,3,4,5,6,7} , k=2
*/

// Function to Reverse the array
void reverseArr(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to Rotate k elements to right
void Rotateeletoright(int arr[], int n, int k)
{

    // Reverse first n-k elements
    reverseArr(arr, 0, n - k - 1);
    // Reverse last k elements
    reverseArr(arr, n - k, n - 1);
    // Reverse whole array
    reverseArr(arr, 0, n - 1);
}

// Time Complexity - O(N) where N is the number of elements in an array

// Space Complexity - O(1) since no extra space is required

// Same approach to rotate left

void RotateeletoLeft(int arr[], int n, int k)
{
    reverseArr(arr, 0, k - 1);
    reverseArr(arr, k, n - 1);
    reverseArr(arr, 0, n - 1);
}

int main()
{
    int n = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    Rotatetoright(arr, n, k);
    cout << "After Rotating the elements to right " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    RotatetoLeft(arr, n, k);
    cout << "After Rotating the elements to left " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    Rotateeletoright(arr, n, k);
    cout << "After Rotating the k elements to right " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << endl;

    RotateeletoLeft(arr, n, k);
    cout << "After Rotating the k elements to left " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}