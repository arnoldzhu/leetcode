#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> res;
        backtrack(res, temp, s);
        return res;
    }

    void backtrack(vector<vector<string>>& res, vector<string>& temp, string s) {
        if(s.length() == 0) {
            res.push_back(temp);
            return;
        }
        else
        {
            for(int i = 1; i <= s.length(); ++i) {
                string head = s.substr(0, i);
                string back = s.substr(i);
                if(isPalindrome(head)) {
                    temp.push_back(head);
                    backtrack(res, temp, back);
                    temp.pop_back();
                }
            }
        }
    }

    int isPalindrome(string str) {
        for(int i = 0; i < str.length()/2; ++i)
            if(str[i] != str[str.length() - i -1])
                return 0;
        return 1;
    }
};

int main()
{
    Solution s;

    // write test code here

    vector<vector<string>> res = s.partition("aab");

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