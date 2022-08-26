#include <iostream>
#include <unordered_map>
using namespace std;
// Function to find the maximum length subarray with sum `S` present

// in a given array
void findMaxLenSubarray(int nums[], int n, int S)
{
    // create an empty map to store the ending index of the first subarray
    // having some sum
    unordered_map<int, int> map;
    // insert (0, -1) pair into the set to handle the case when a
    // subarray with sum `S` starts from index 0
    map[0] = -1;
    int target = 0;
    // `len` stores the maximum length of subarray with sum `S`
    int len = 0;
    // stores ending index of the maximum length subarray having sum `S`
    int ending_index = -1;
    // traverse the given array
    for (int i = 0; i < n; i++)
    {
        // sum of elements so far
        target += nums[i];
        // if the sum is seen for the first time, insert the sum with its
        // into the map
        if (map.find(target) == map.end())
        {
            map[target] = i;
        }

        // update length and ending index of the maximum length subarray
        // having sum `S`

        if (map.find(target - S) != map.end() && len < i - map[target - S])
        {
            len = i - map[target - S];
            ending_index = i;
        }
    }

    // print the subarray

    cout << "The largest subarray is ";
    cout << "{";
    for (int i = (ending_index - len + 1); i <= ending_index; i++)
    {
        cout << nums[i] << ",";
    }

   cout << "}";

    cout << " having length " << (ending_index - (ending_index - len + 1) + 1);

    // cout << "[" << nums[(ending_index - len + 1)] << "," << nums[ending_index] << "]";
}

int main()

{
    int n, target;
    cin>>n>>target;
     int nums[n];
     for(int i=0; i<n; i++){
        cin>>nums[i];
     }
    findMaxLenSubarray(nums, n, target);

    return 0;
}