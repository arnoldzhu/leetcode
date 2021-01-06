#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res, temp, n, k, 1);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& temp, int n, int k, int cur) {
        if (temp.size() + (n - cur + 1) < k) {
            return;
        }
        if(temp.size() == k) {
            res.push_back(temp);
            return;
        }
        temp.push_back(cur);
        backtrack(res, temp, n, k, cur+1);
        temp.pop_back();
        backtrack(res, temp, n, k, cur+1);
    }
};

int main()
{
    Solution s;

    // write test code here

    vector<vector<int>> res = s.combine(4, 2);

    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }

    // end of test code

    system("pause");
    return 0;
}