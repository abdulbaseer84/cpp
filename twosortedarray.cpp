// Median of Two Sorted Arrays
// Hard
// Topics
// premium lock icon
// Companies
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if (m > n) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int imin = 0, imax = m, halfLen = (m + n + 1) / 2;
    while (imin <= imax) {
        int i = (imin + imax) / 2;
        int j = halfLen - i;

        if (i < m && nums2[j - 1] > nums1[i]) {
            imin = i + 1; // i is too small
        } else if (i > 0 && nums1[i - 1] > nums2[j]) {
            imax = i - 1; // i is too big
        } else {
            int maxLeft = 0;
            if (i == 0) {
                maxLeft = nums2[j - 1];
            } else if (j == 0) {
                maxLeft = nums1[i - 1];
            } else {
                maxLeft = max(nums1[i - 1], nums2[j - 1]);
            }

            if ((m + n) % 2 == 1) {
                return maxLeft; // Odd case
            }

            int minRight = 0;
            if (i == m) {
                minRight = nums2[j];
            } else if (j == n) {
                minRight = nums1[i];
            } else {
                minRight = min(nums1[i], nums2[j]);
            }

            return (maxLeft + minRight) / 2.0; // Even case
        }
    }

    return 0.0; // Should never reach here
}

int main() {
    int m, n;
    cout << "Enter size of first sorted array: ";
    cin >> m;
    vector<int> nums1(m);
    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    cout << "Enter size of second sorted array: ";
    cin >> n;
    vector<int> nums2(n);
    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median of the two sorted arrays: " << median << endl;

    return 0;
}