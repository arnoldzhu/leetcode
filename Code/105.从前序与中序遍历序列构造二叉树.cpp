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
    unordered_map<int, int> index;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < preorder.size(); ++i)
            index[inorder[i]] = i;
        
        return myBuild(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* myBuild(vector<int>& preorder, vector<int>& inorder, int pre_l, int pre_r, int in_l, int in_r)
    {
        if(pre_l > pre_r)
            return NULL;

        int pre_root = pre_l;
        int in_root = index[preorder[pre_root]];

        TreeNode *root = new TreeNode(preorder[pre_root]);
        int left_tree_length = in_root - in_l;

        root->left = myBuild(preorder, inorder, pre_l + 1, pre_l + left_tree_length, in_l, in_root - 1);
        root->right = myBuild(preorder, inorder, pre_l + left_tree_length + 1, pre_r, in_root + 1, in_r);

        return root;
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