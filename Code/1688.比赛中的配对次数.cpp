#include<iostream>
#include<cstdlib>

using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        if(n <= 2)
            return 1;
        else {
            int t = n % 2 == 0 ? n/2 : n/2+1;
            return (n/2 + numberOfMatches(t));
        }
    }
};
int main()
{
    Solution s;

    // write test code here
    int n;
    cin >> n;

    int res = s.numberOfMatches(n);

    cout << res << endl;

    // end of test code
    system("pause");
    return 0;
}