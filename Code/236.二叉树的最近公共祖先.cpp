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
    vector<int> route_p;
    vector<int> route_q;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> route;
        findRoute(root, route, p, q);

        TreeNode *res = root;
        int i = 0;
        while(1) {
            if((i == route_p.size()) || (i == route_q.size()) || (route_p[i] != route_q[i]))
                break;
            else if(1 == route_p[i])
                res = res->left;
            else
                res = res->right;
            
            ++i;
        }
        return res;
    }

    void findRoute(TreeNode* node, vector<int>& route, TreeNode* p, TreeNode* q) {
        if(node == p) {
            route_p = route;
        }
        if(node == q) {
            route_q = route;
        }
        if(NULL == node->left && NULL == node->right) {
            return;
        }

        if(node->left != NULL) {
            route.push_back(1);
            findRoute(node->left, route, p, q);
            route.pop_back();
        }
        if(node->right != NULL) {
            route.push_back(0);
            findRoute(node->right, route, p, q);
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