// Trapping Rain Water II
// Hard
// Topics
// premium lock icon
// Companies
// Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

 

// Example 1:


// Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
// Output: 4
// Explanation: After the rain, water is trapped between the blocks.
// We have two small ponds 1 and 3 units trapped.
// The total volume of water trapped is 4.
// Example 2:


// Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
// Output: 10
 

// Constraints:

// m == heightMap.length
// n == heightMap[i].length
// 1 <= m, n <= 200
// 0 <= heightMap[i][j] <= 2 * 104
#include <bits/stdc++.h>
using namespace std;

struct Cell{
    int h,x,y;
    bool operator>(const Cell& other) const{
        return h>other.h;
    }
};

int main(){

    int m,n;
    cout<<"Enter rows and columns: ";
    cin>>m>>n;

    vector<vector<int>> height(m,vector<int>(n));
    cout<<"Enter height map:\n";
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>height[i][j];

    if(m<=2 || n<=2){
        cout<<"Water trapped: 0";
        return 0;
    }

    priority_queue<Cell,vector<Cell>,greater<Cell>> pq;
    vector<vector<bool>> vis(m,vector<bool>(n,false));

    // push boundary cells
    for(int i=0;i<m;i++){
        pq.push({height[i][0],i,0});
        pq.push({height[i][n-1],i,n-1});
        vis[i][0]=vis[i][n-1]=true;
    }

    for(int j=0;j<n;j++){
        pq.push({height[0][j],0,j});
        pq.push({height[m-1][j],m-1,j});
        vis[0][j]=vis[m-1][j]=true;
    }

    int water=0;
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

    while(!pq.empty()){

        Cell cur=pq.top();
        pq.pop();

        for(auto &d:dir){
            int nx=cur.x+d[0];
            int ny=cur.y+d[1];

            if(nx<0||ny<0||nx>=m||ny>=n||vis[nx][ny])
                continue;

            vis[nx][ny]=true;

            // water trapped
            if(height[nx][ny]<cur.h)
                water+=cur.h-height[nx][ny];

            pq.push({max(height[nx][ny],cur.h),nx,ny});
        }
    }

    cout<<"Water trapped: "<<water;
    return 0;
}
