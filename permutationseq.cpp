// Permutation Sequence
// Hard
// Topics
// premium lock icon
// Companies
// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

 

// Example 1:

// Input: n = 3, k = 3
// Output: "213"
// Example 2:

// Input: n = 4, k = 9
// Output: "2314"
// Example 3:

// Input: n = 3, k = 1
// Output: "123"
 

// Constraints:

// 1 <= n <= 9
// 1 <= k <= n!
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;

    vector<int> numbers;
    for(int i=1;i<=n;i++)
        numbers.push_back(i);

    // factorial
    int fact = 1;
    for(int i=1;i<n;i++)
        fact *= i;

    k--; // convert to 0-index

    string answer = "";

    while(true){

        int index = k / fact;
        answer += to_string(numbers[index]);

        numbers.erase(numbers.begin()+index);

        if(numbers.size()==0)
            break;

        k = k % fact;
        fact = fact / numbers.size();
    }

    cout<<"Kth permutation: "<<answer;
    return 0;
}
