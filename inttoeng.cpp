// Integer to English Words
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Convert a non-negative integer num to its English words representation.

 

// Example 1:

// Input: num = 123
// Output: "One Hundred Twenty Three"
// Example 2:

// Input: num = 12345
// Output: "Twelve Thousand Three Hundred Forty Five"
// Example 3:

// Input: num = 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 

// Constraints:

// 0 <= num <= 231 - 1
#include <bits/stdc++.h>
using namespace std;

string below20[]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};

string tens[]={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

string helper(int num){
    string res="";

    if(num>=100){
        res+=below20[num/100]+" Hundred ";
        num%=100;
    }

    if(num>=20){
        res+=tens[num/10]+" ";
        num%=10;
    }

    if(num>0){
        res+=below20[num]+" ";
    }

    return res;
}

int main(){

    long long num;
    cout<<"Enter number: ";
    cin>>num;

    if(num==0){
        cout<<"Zero";
        return 0;
    }

    string result="";

    if(num>=1000000000){
        result+=helper(num/1000000000)+"Billion ";
        num%=1000000000;
    }

    if(num>=1000000){
        result+=helper(num/1000000)+"Million ";
        num%=1000000;
    }

    if(num>=1000){
        result+=helper(num/1000)+"Thousand ";
        num%=1000;
    }

    if(num>0){
        result+=helper(num);
    }

    // remove trailing space
    while(result.back()==' ')
        result.pop_back();

    cout<<"In words: "<<result;
    return 0;
}
