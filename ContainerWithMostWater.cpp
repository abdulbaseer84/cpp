// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

 

// Example 1:


// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1
 

// Constraints:

// n == height.length
// 2 <= n <= 105
// 0 <= height[i] <= 104
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;//
        int right = height.size() - 1;// right=8
        int max_area = 0;

        while (left < right) {// while(0<8)
            int width = right - left;// width=8-0=8; width=7-1=6; width=6-2=4; width=5-3=2; width=4-4=0
            int current_height = min(height[left], height[right]);// current_height=min(1,7)=1; current_height=min(8,7)=7; current_height=min(6,7)=6; current_height=min(2,7)=2; current_height=min(5,7)=5s
            int current_area = width * current_height;// current_area=8*1=8; current_area=6*7=42; current_area=4*6=24; current_area=2*2=4; current_area=0*5=0
            max_area = max(max_area, current_area);// max_area=max(0,8)=8; max_area=max(8,42)=42; max_area=max(42,24)=42; max_area=max(42,4)=42; max_area=max(42,0)=42

            if (height[left] < height[right]) {// if(1<7) true; if(8<7) false; if(6<7) true; if(2<7) true; if(5<7) true
                left++;// left=1; left=2; left=3; left=4
            } else {
                right--;// right=7; right=6; right=5; right=4;
            }
        }

        return max_area;
    }
};

int main() {
    Solution solution;
    vector<int> height;
    int n; //n=9
    cin >> n;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;//h=1; h=8; h=6; h=2; h=5; h=4; h=8; h=3; h=7
        height.push_back(h);//height=[1,8,6,2,5,4,8,3,7]
    }
    int result = solution.maxArea(height);
    cout << result << endl;
}