// Given an integer array nums, find a subarray that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// Note that the product of an array with a single element is the value of that element.

 

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

// Constraints:

// 1 <= nums.length <= 2 * 104
// -10 <= nums[i] <= 10
// The product of any subarray of nums is guaranteed to fit in a 32-bit intege

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n; //n=4
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];// nums=[2,3,-2,4]
    }
    int max_product = nums[0];// max_product=2
    int min_product = nums[0];// min_product=2
    int result = nums[0];// result=2

    for (int i = 1; i < n; i++) { // for(i=1; i<4; i++)
        if (nums[i] < 0) { // if(3<0) false; if(-2<0) true; if(4<0) false
            swap(max_product, min_product);// swap(max_product, min_product)
        }

        max_product = max(nums[i], max_product * nums[i]);
        min_product = min(nums[i], min_product * nums[i]);
        result = max(result, max_product);
    }

    cout << result << endl;// output: 6

    return 0;
}

//n=4
//nums=[2,3,-2,4]
//max_product=2
//min_product=2
//result=2
//i=1
//nums[1]=3
//if(3<0) false
//max_product=max(3,2*3)=6
//min_product=min(3,2*3)=3
//result=max(2,6)=6
//i=2
//nums[2]=-2
//if(-2<0) true
//swap(max_product, min_product) max_product=3; min_product=6
//max_product=max(-2,3*(-2))=max(-2,-6)=-2
//min_product=min(-2,6*(-2))=min(-2,-12)=-12
//result=max(6,-2)=6
//i=3
//nums[3]=4
//if(4<0) false
//max_product=max(4,-2*4)=max(4,-8)=4
//min_product=min(4,-12*4)=min(4,-48)=-48
//result=max(6,4)=6
//output: 6
