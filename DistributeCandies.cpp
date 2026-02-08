// Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor.

// The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.

// Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

 

// Example 1:

// Input: candyType = [1,1,2,2,3,3]
// Output: 3
// Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.
// Example 2:

// Input: candyType = [1,1,2,3]
// Output: 2
// Explanation: Alice can only eat 4 / 2 = 2 candies. Whether she eats types [1,2], [1,3], or [2,3], she still can only eat 2 different types.
// Example 3:

// Input: candyType = [6,6,6,6]
// Output: 1
// Explanation: Alice can only eat 4 / 2 = 2 candies. Even though she can eat 2 candies, she only has 1 type.
 

// Constraints:

// n == candyType.length
// 2 <= n <= 104
// n is even.
// -105 <= candyType[i] <= 105

// give according above problem statement, here is the C++ code implementation:
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of candies (even number): "; //already aboove have 
    cin >> n;
    vector<int> candyType(n);
    cout << "Enter the types of candies: ";
    for (int i = 0; i < n; ++i) {
        cin >> candyType[i];
    }

    unordered_set<int> uniqueTypes(candyType.begin(), candyType.end());
    int maxTypesAliceCanEat = min(static_cast<int>(uniqueTypes.size()), n / 2);

    cout << "Maximum number of different types of candies Alice can eat: " << maxTypesAliceCanEat << endl;
    return 0;
}

//output example:
// Enter the number of candies (even number): 6
// Enter the types of candies: 1 1 2 2 3 3
