#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 更快的解法，直接在原矩阵上操作
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int island_count = 0;

//         for(int i = 0; i < m; ++i)
//             for(int j = 0; j < n; ++j) {
//                 if(grid[i][j] == '1') {
//                     ++island_count;
//                     Backtrack(grid, i, j);
//                 }
//             }

//         return island_count;
//     }

//     void Backtrack(vector<vector<char>>& grid, int i, int j) {
//         grid[i][j] = '0';
        
//         if(i != 0 && grid[i-1][j] == '1')
//             Backtrack(grid, i-1, j);
//         if(j != 0 && grid[i][j-1] == '1')
//             Backtrack(grid, i, j-1);
//         if(i != grid.size() - 1 && grid[i+1][j] == '1')
//             Backtrack(grid, i+1, j);
//         if(j != grid[0].size() - 1 && grid[i][j+1] == '1')
//             Backtrack(grid, i, j+1);
//     }
// };
 
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n));
        int island_count = 0;

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(!visited[i][j] && (grid[i][j] == '1')) {
                    ++island_count;
                    Backtrack(grid, visited, i, j);
                }
            }

        return island_count;
    }

    void Backtrack(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if(grid[i][j] == '0')
            return;
        
        visited[i][j] = true;
        if(i != 0 && !visited[i-1][j])
            Backtrack(grid, visited, i-1, j);
        if(j != 0 && !visited[i][j-1])
            Backtrack(grid, visited, i, j-1);
        if(i != grid.size() - 1 && !visited[i+1][j])
            Backtrack(grid, visited, i+1, j);
        if(j != grid[0].size() - 1 && !visited[i][j+1])
            Backtrack(grid, visited, i, j+1);
    }
};

int main()
{
    Solution s;

    // write test code here
    vector<vector<char>> map = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};

    cout << s.numIslands(map);
    // end of test code

    system("pause");
    return 0;
}