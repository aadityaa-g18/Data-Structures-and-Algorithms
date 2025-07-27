#include<bits/stdc++.h>
using namespace std;

/*  BRUTE FORCE --> only if there is no duplicates


int SecondLargestElement(vector<int> arr, int n){
    sort(arr.begin(), arr.end());
    return arr[n - 2];
}


*/

/* BETTER SOLUTION  Time Complexity: O(N), We do two linear traversals in our array
                    Space Complexity: O(1)


int SecondLargest(vector<int> arr, int n){
    int secondLargest = INT_MIN;
    int Largest = INT_MIN;

    for (int i = 0; i < n;i++){
        Largest = max(Largest, arr[i]);
    }

    for (int i = 0; i < n;i++){
        if(arr[i]>secondLargest && arr[i]!=Largest){
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}


*/



/* OPTIMAL SOLUTION  Time Complexity: O(N), Single-pass solution
                    Space Complexity: O(1)

*/

int SecondLargestEle(vector<int> arr, int n){
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n;i++){
        if(arr[i]>largest){
            secondLargest = largest;
            largest = arr[i];
        }else if(arr[i]<largest && arr[i]>secondLargest){
            secondLargest = arr[i];
        }

    }
    return secondLargest;
}





int main()
{
    vector<int> vec = {2, 5, 1, 7, 3, 0};
    int size = sizeof(vec) / sizeof(vec[0]);

    // cout << SecondLargestElement(vec, size) << endl;
    // cout << SecondLargest(vec, size) << endl;
    cout << SecondLargestEle(vec, size) << endl;

}