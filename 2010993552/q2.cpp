/*
   Name: Kavya Garg
   Roll No: 2010993552
   Set No:
*/

#include <iostream>

#include <unordered_map>

using namespace std;

// Function to print all subarrays with a zero-sum

// in a given array

void printAllSubarrays(int nums[], int n)

{

    // consider all subarrays starting from `i`

    for (int i = 0; i < n; i++)

    {

        int sum = 0;

        // consider all subarrays ending at `j`

        for (int j = i; j < n; j++)

        {

            // sum of elements so far

            sum += nums[j];

            // if the sum is seen before, we have found a subarray

            // with zero-sum

            if (sum == 0) {

                cout<<"{";

                for(int it=i;it<=j;it++)
                 {

                    cout<<nums[it]<<",";

                }

                cout<<"}";

                cout<<endl;

                // cout << "Subarray [" << i << "…" << j << "]\n";

            }

        }

    }

}

int main(){

    int n;
    cin>>n;
    int nums[n];
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    printAllSubarrays(nums, n);

    return 0;

}