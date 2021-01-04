/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include<vector>

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a, b;

        for(int i = 0; i < nums.size(); ++i)
            for(int j = i + 1; j < nums.size(); ++j) {
                target -= nums[i];
                target -= nums[j];

                if(target == 0) {
                    a = i;
                    b = j;
                }
            }
        vector<int> res;
        res.push_back(a);
        res.push_pack(b);
        return res;
    }
};
// @lc code=end

