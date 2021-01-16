#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp;
        backtrack(res, temp, 0, 0, n);
        return res;
    }

    void backtrack(vector<string>& res, string& temp, int left, int right, int n) {
        if(left + right == 2*n) {
            res.push_back(temp);
            return;
        }
        if(left < n) {
            temp.push_back('(');
            backtrack(res, temp, left+1, right, n);
            temp.pop_back();
        }
        if(right < left) {
            temp.push_back(')');
            backtrack(res, temp, left, right+1, n);
            temp.pop_back();
        }
    }
};

int main()
{
    Solution s;

    // write test code here

    vector<string> res = s.generateParenthesis(3);

    for(int i = 0; i < res.size(); ++i)
        cout << res[i] << endl;

    // end of test code

    system("pause");
    return 0;
}