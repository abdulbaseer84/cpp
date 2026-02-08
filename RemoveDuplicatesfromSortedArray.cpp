// //Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

// Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

// The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.
// Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4}; // Example input
    int n = nums.size();
    if (n == 0) return 0;

    int k = 1; // Initialize the count of unique elements

    for (int i = 1; i < n; ++i) {
        if (nums[i] != nums[i - 1]) { // Check for a new unique element
            nums[k] = nums[i]; // Place it at the k-th position
            k++; // Increment the count of unique elements
        }
    }

    // Output the number of unique elements and the modified array
    cout << "Number of unique elements: " << k << endl;
    cout << "Modified array: ";
    for (int i = 0; i < k; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

// Output:
// Number of unique elements: 5
// Modified array: 0 1 2 3 4

