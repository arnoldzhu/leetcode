class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty())
            return false;

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited;
        for(int i = 0; i < m; ++i)
            visited.push_back({});
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                visited[i].push_back(false);

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == word[0]) {
                    if(Backtrack(board, word, visited, i, j, 0))
                        return true;
                }
            }

        return false;
    }

    bool Backtrack(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int i, int j, int t) {
        if(word[t] != board[i][j])
            return false;
        if(t == word.length() - 1)
            return true;

        visited[i][j] = true;
        bool res = false;
        if(i != 0 && !visited[i-1][j])
            res = Backtrack(board, word, visited, i - 1, j, t + 1);
        if(j != 0 && res == false && !visited[i][j-1])
            res = Backtrack(board, word, visited, i, j - 1, t + 1);
        if(i != board.size() - 1 && res == false && !visited[i+1][j])
            res = Backtrack(board, word, visited, i + 1, j, t + 1);
        if(j != board[0].size() - 1 && res == false && !visited[i][j+1])
            res = Backtrack(board, word, visited, i, j + 1, t + 1);
        visited[i][j] = false;
        return res;
    }
};