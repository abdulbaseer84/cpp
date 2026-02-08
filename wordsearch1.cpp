// Word Search II
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given an m x n board of characters and a list of strings words, return all words on the board.

// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

// Example 1:


// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]
// Example 2:


// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []
 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 12
// board[i][j] is a lowercase English letter.
// 1 <= words.length <= 3 * 104
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// All the strings of words are unique.
#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* child[26];
    string word="";

    TrieNode(){
        for(int i=0;i<26;i++) child[i]=NULL;
    }
};

void insert(TrieNode* root, string word){
    TrieNode* node=root;
    for(char c:word){
        int i=c-'a';
        if(!node->child[i])
            node->child[i]=new TrieNode();
        node=node->child[i];
    }
    node->word=word;
}

void dfs(vector<vector<char>>& board,int r,int c,TrieNode* node,vector<string>& ans){

    char ch=board[r][c];
    if(ch=='#' || !node->child[ch-'a'])
        return;

    node=node->child[ch-'a'];

    if(node->word!=""){
        ans.push_back(node->word);
        node->word=""; // avoid duplicate
    }

    board[r][c]='#';

    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

    for(auto &d:dir){
        int nr=r+d[0];
        int nc=c+d[1];

        if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size())
            dfs(board,nr,nc,node,ans);
    }

    board[r][c]=ch;
}

int main(){

    int m,n;
    cout<<"Enter rows and columns: ";
    cin>>m>>n;

    vector<vector<char>> board(m,vector<char>(n));

    cout<<"Enter board:\n";
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>board[i][j];

    int w;
    cout<<"Enter number of words: ";
    cin>>w;

    vector<string> words(w);
    cout<<"Enter words:\n";
    for(int i=0;i<w;i++)
        cin>>words[i];

    TrieNode* root=new TrieNode();

    for(string word:words)
        insert(root,word);

    vector<string> ans;

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            dfs(board,i,j,root,ans);

    cout<<"Words found:\n";
    for(string s:ans)
        cout<<s<<" ";

    return 0;
}
