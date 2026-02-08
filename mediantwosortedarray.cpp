// Median of Two Sorted Arrays
// Hard
// Topics
// premium lock icon
// Companies
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106
#include <bits/stdc++.h>
using namespace std;

int main() {

    int m, n;
    cout << "Enter size of first array: ";
    cin >> m;
    vector<int> a(m);
    cout << "Enter elements of first sorted array: ";
    for(int i=0;i<m;i++) cin>>a[i];

    cout << "Enter size of second array: ";
    cin >> n;
    vector<int> b(n);
    cout << "Enter elements of second sorted array: ";
    for(int i=0;i<n;i++) cin>>b[i];

    // Always binary search on smaller array
    if(m > n){
        swap(a,b);
        swap(m,n);
    }

    int low = 0, high = m;

    while(low <= high){

        int cut1 = (low + high) / 2;
        int cut2 = (m + n + 1)/2 - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : a[cut1-1];
        int r1 = (cut1 == m) ? INT_MAX : a[cut1];

        int l2 = (cut2 == 0) ? INT_MIN : b[cut2-1];
        int r2 = (cut2 == n) ? INT_MAX : b[cut2];

        if(l1 <= r2 && l2 <= r1){

            // odd length
            if((m+n)%2==1){
                cout<<"Median: "<< max(l1,l2);
            }
            else{
                double median = (max(l1,l2) + min(r1,r2)) / 2.0;
                cout<<"Median: "<< median;
            }
            return 0;
        }
        else if(l1 > r2){
            high = cut1 - 1;
        }
        else{
            low = cut1 + 1;
        }
    }

    return 0;
}
