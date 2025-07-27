#include <bits/stdc++.h>
using namespace std;

// +++++++++++++++++++++++++ BRUTE FORCE APPROACH ++++++++++++++++++++++++++++++++
// bool isSorted(vector<int> vec, int n){

//     for (int i = 0; i < n;i++){
//         for (int j = i + 1; j < n;j++){
//             if(vec[j]<vec[i]){
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// ++++++++++++++++++++++++ OPTIMAL APPROACH ++++++++++++++++++++++++++++++++
bool isSorted(vector<int> vec, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (vec[i - 1] > vec[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    vector<int> arr = {1, 2, 4, 3, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << isSorted(arr, size);
}