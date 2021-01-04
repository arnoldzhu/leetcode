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
		unordered_map<int, int> hashtable;
        
        for(int i = 0; i < nums.size(); ++i) {
            auto place = hashtable.find(target - nums[i]);
            if(place != hashtable.end())
                return {place->second, i};
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

