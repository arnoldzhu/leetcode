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
 
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(NULL == root)
            return {};

        vector<vector<int>> res;
        vector<int> route = {root->val};

        Backtrack(res, route, root, sum, root->val);
        return res;
    }

    void Backtrack(vector<vector<int>>& res, vector<int>& route, TreeNode* node, int sum, int temp) {
        if(NULL == node->left && NULL == node->right) {
            if(sum == temp)
                res.push_back(route);
            return;
        }
        if(node->left != NULL) {
            route.push_back(node->left->val);
            Backtrack(res, route, node->left, sum, temp + node->left->val);
            route.pop_back();
        }
        if(node->right != NULL) {
            route.push_back(node->right->val);
            Backtrack(res, route, node->right, sum, temp + node->right->val);
            route.pop_back();
        }
    }
};

int main()
{
    Solution s;

    // write test code here

    vector<vector<int>> input = {{1,1,0},{1,1,0},{0,0,1}};

    int res = s.findCircleNum(input);

    cout << res << endl;

    // end of test code

    system("pause");
    return 0;
}