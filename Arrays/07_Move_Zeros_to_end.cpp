#include <bits/stdc++.h>
using namespace std;

// +++++++++++++++++++++++++ BRUTE FORCE APPROACH ++++++++++++++++++++++++++++++
vector<int> moveZeros(int n, vector<int> arr)
{

    // temporary array:
    vector<int> temp;
    // copy non-zero elements
    // from original -> temp array:
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }
    // number of non-zero elements.
    int newSize = temp.size();

    // copy elements from temp
    // fill first nz fields of
    // original array:
    for (int i = 0; i < newSize; i++)
    {
        arr[i] = temp[i];
    }
    // fill rest of the cells with 0:
    for (int i = newSize; i < n; i++)
    {
        arr[i] = 0;
    }

    return arr;
}

// Time Complexity: O(N) + O(X) + O(N-X) ~ O(2*N), where N = total no. of elements,
// X = no. of non-zero elements, and N-X = total no. of zeros.
// Reason: O(N) for copying non-zero elements from the original to the temporary array.
// O(X) for again copying it back from the temporary to the original array.
// O(N-X) for filling zeros in the original array. So, the total time complexity will be O(2*N).

// Space Complexity: O(N), as we are using a temporary array to solve this problem and
// the maximum size of the array can be N in the worst case.
// Reason: The temporary array stores the non-zero elements.
// In the worst case, all the given array elements will be non-zero.

// +++++++++++++++++++++++++++++ OPTIMAL SOLUTION +++++++++++++++++++++++++++++++
vector<int> moveZeroestoEnd(int n, vector<int> arr)
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
    {
        return arr;
    }

    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return arr;
}

// Time Complexity: O(N), N = size of the array.
// Reason: We have used 2 loops and using those loops, we are basically traversing the array once.

// Space Complexity: O(1) as we are not using any extra space to solve this problem.

int main()
{
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;
    vector<int> ans = moveZeroestoEnd(n, arr);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}