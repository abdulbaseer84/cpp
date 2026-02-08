// Create Maximum Number
// Hard
// Topics
// premium lock icon
// Companies
// You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.

// Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.

// Return an array of the k digits representing the answer.

 

// Example 1:

// Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
// Output: [9,8,6,5,3]
// Example 2:

// Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
// Output: [6,7,6,0,4]
// Example 3:

// Input: nums1 = [3,9], nums2 = [8,9], k = 3
// Output: [9,8,9]
 

// Constraints:

// m == nums1.length
// n == nums2.length
// 1 <= m, n <= 500
// 0 <= nums1[i], nums2[i] <= 9
// 1 <= k <= m + n
// nums1 and nums2 do not have leading zeros.
#include <bits/stdc++.h>
using namespace std;

// pick maximum subsequence of size k
vector<int> maxSubsequence(vector<int>& nums, int k){
    vector<int> st;
    int drop = nums.size() - k;

    for(int num: nums){
        while(!st.empty() && drop>0 && st.back()<num){
            st.pop_back();
            drop--;
        }
        st.push_back(num);
    }

    st.resize(k);
    return st;
}

// compare remaining sequences
bool greaterVec(vector<int>& a,int i,vector<int>& b,int j){
    while(i<a.size() && j<b.size() && a[i]==b[j]){
        i++; j++;
    }
    return j==b.size() || (i<a.size() && a[i]>b[j]);
}

// merge two sequences to form largest number
vector<int> mergeVec(vector<int> a, vector<int> b, int k){
    vector<int> res;
    int i=0,j=0;

    while(res.size()<k){
        if(greaterVec(a,i,b,j))
            res.push_back(a[i++]);
        else
            res.push_back(b[j++]);
    }
    return res;
}

int main(){

    int m,n,k;

    cout<<"Enter size of nums1: ";
    cin>>m;
    vector<int> nums1(m);
    cout<<"Enter digits of nums1: ";
    for(int i=0;i<m;i++)
        cin>>nums1[i];

    cout<<"Enter size of nums2: ";
    cin>>n;
    vector<int> nums2(n);
    cout<<"Enter digits of nums2: ";
    for(int i=0;i<n;i++)
        cin>>nums2[i];

    cout<<"Enter k: ";
    cin>>k;

    vector<int> best(k,0);

    // try all splits
    for(int i=max(0,k-n); i<=min(k,m); i++){
        vector<int> part1=maxSubsequence(nums1,i);
        vector<int> part2=maxSubsequence(nums2,k-i);

        vector<int> candidate=mergeVec(part1,part2,k);

        if(greaterVec(candidate,0,best,0))
            best=candidate;
    }

    cout<<"Maximum number: ";
    for(int d:best)
        cout<<d<<" ";

    return 0;
}
