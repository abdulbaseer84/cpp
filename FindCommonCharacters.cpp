// Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

// Example 1:

// Input: words = ["bella","label","roller"]
// Output: ["e","l","l"]
// Example 2:

// Input: words = ["cool","lock","cook"]
// Output: ["c","o"]
 

// Constraints:

// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists of lowercase English letters.
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    vector<int> count(26, 0);// Count characters in the first word to initialize the count array 
    for (char c : words[0]) {
        count[c - 'a']++; // Increment the count for each character in the first word
    }
    for (int i = 1; i < n; i++) {
        vector<int> temp_count(26, 0);
        for (char c : words[i]) {
            temp_count[c - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            count[j] = min(count[j], temp_count[j]);
        }
    }
    vector<string> result;
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            result.push_back(string(1, 'a' + i));
            count[i]--;
        }
    }
    for (const string& s : result) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}