#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> final;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> res;
        Backtrack(nums, res);
        return final;
    }

    void Backtrack(vector<int>& nums, vector<int>& res) {
        
        if(nums.size() == 0) {
            final.push_back(res);
            return;
        }
        else {
            for(int i = 0; i < nums.size(); ++i) {
                int temp = nums[i];
                res.push_back(temp);
                nums.erase(nums.begin()+i);
                Backtrack(nums, res);
                res.pop_back();
                nums.insert(nums.begin()+i, temp);
            }
        }
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