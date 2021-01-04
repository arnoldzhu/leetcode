#include<iostream>
#include<cstdlib>

using namespace std;
#include<vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a, b;
        int temp = target;
        int flag = 1;

        for(int i = 0; i < nums.size() && flag == 1; ++i)
            for(int j = i + 1; j < nums.size() && flag == 1; ++j) {
                temp -= nums[i];
                temp -= nums[j];

                cout << temp << endl;

                if(temp == 0) {
                    a = i;
                    b = j;
                    flag = 0;
                }
                temp = target;
            }
        vector<int> res;
        res.push_back(a);
        res.push_back(b);
        return res;
    }
};


int main()
{
    vector<int> b = {0,3,-3,4,-1};
    Solution s;

    vector<int> a = s.twoSum(b, -1);

    for(vector<int>::iterator i=a.begin(); i != a.end(); ++i)
        cout << *i << ' ';
    cout << endl;

    system("pause");
    return 0;
}