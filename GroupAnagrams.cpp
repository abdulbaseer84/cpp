// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]

// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Explanation:

// There is no string in strs that can be rearranged to form "bat".
// The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
// The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
// Example 2:

// Input: strs = [""]

// Output: [[""]]

// Example 3:

// Input: strs = ["a"]

// Output: [["a"]]

 

// Constraints:

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
    int n; //n=6
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];// strs=["eat","tea","tan","ate","nat","bat"]
    }
    unordered_map<string, vector<string>> anagram_groups;//

    for (const string& str : strs) { // str="eat"; str="tea"; str="tan"; str="ate"; str="nat"; str="bat"
        string sorted_str = str; // sorted_str="eat"
        sort(sorted_str.begin(), sorted_str.end()); // sorted_str="aet"
        anagram_groups[sorted_str].push_back(str); // anagram_groups["aet"]=["eat"]; 
    }

    vector<vector<string>> result;
    for (const auto& pair : anagram_groups) {
        result.push_back(pair.second); // result=[["eat","tea","ate"], ["tan","nat"], ["bat"]]
    }

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << "\"" << result[i][j] << "\"";
            if (j != result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}