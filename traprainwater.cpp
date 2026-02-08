// Trapping Rain Water
// Hard
// Topics
// premium lock icon
// Companies
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

// Example 1:


// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9
 

// Constraints:

// n == height.length
// 1 <= n <= 2 * 104
// 0 <= height[i] <= 105
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter heights: ";
    for(int i=0;i<n;i++)
        cin>>height[i];

    int left = 0;
    int right = n - 1;

    int leftMax = 0, rightMax = 0;
    int water = 0;
    //4 2 0 3 2 5
    while(left < right){ //0<5 T

        if(height[left] < height[right]){//4<5 T | 2<5 T

            if(height[left] >= leftMax) //4>=0 T| 
                leftMax = height[left]; //LM=4
            else
                water += leftMax - height[left]; // W=0+0+4=4

            left++;// l=1
        }
        else{

            if(height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax - height[right];

            right--;
        }
    }

    cout << "Total trapped water: " << water;
    return 0;
}
