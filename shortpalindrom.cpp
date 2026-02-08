// Shortest Palindrome
// Hard
// Topics
// premium lock icon
// Companies
// You are given a string s. You can convert s to a palindrome by adding characters in front of it.

// Return the shortest palindrome you can find by performing this transformation.

 

// Example 1:

// Input: s = "aacecaaa"
// Output: "aaacecaaa"
// Example 2:

// Input: s = "abcd"
// Output: "dcbabcd"
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of lowercase English letters only.
#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cout<<"Enter string: ";
    cin>>s;

    string rev=s;
    reverse(rev.begin(),rev.end());

    string temp=s+"#"+rev;

    vector<int> lps(temp.size(),0);

    // build LPS array
    for(int i=1;i<temp.size();i++){
        int j=lps[i-1];

        while(j>0 && temp[i]!=temp[j])
            j=lps[j-1];

        if(temp[i]==temp[j])
            j++;

        lps[i]=j;
    }

    int palLen=lps.back();

    string add=rev.substr(0,s.size()-palLen);

    string result=add+s;

    cout<<"Shortest palindrome: "<<result;
    return 0;
}
