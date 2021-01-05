#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        Backtrack(res, nums, 0, (int)nums.size());
        return res;
    }

    void Backtrack(vector<vector<int>>& res, vector<int>& output, int first, int length) {
        if(first == length) {
            res.push_back(output);
            return;
        }
        else {
            for(int i = first; i < length; ++i) {
                swap(output[first], output[i]);
                Backtrack(res, output, first+1, length);
                swap(output[first], output[i]);
            }
        }
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};

int main()
{
    Solution s;

    // write test code here
    vector<int> a = {1, 2, 3};

    vector<vector<int>> res = s.permute(a);

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