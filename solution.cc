// Follow up for N-Queens problem.

// Now, instead outputting board configurations, return the total number of distinct solutions.


class Solution {
public:
    int totalNQueens(int n) {
        vector<string> sol(n, string(n, '.'));
        int total = 0;
        helper(n,0,sol,total);
        return total;
    }
    
    void helper(int n, int row, vector<string> &sol, int &total) {
        if(row == n) {
            ++total;
            return;
        }
        
        for(int col = 0; col < n; ++col) {
            if(check(row,col,sol)) {
                sol[row][col] = 'Q';
                helper(n, row+1, sol, total);
                sol[row][col] = '.';
            }
        }
    }
    
    bool check(int row, int col, const vector<string> &sol) {
        int n = sol.size();
        for(int i = -1; i <= 1; ++i) {
            for(int j = -1; j <= 1; ++j) {
                if(i == 0 && j == 0) continue;
                int curRow = row, curCol = col;
                while(curRow >= 0 && curRow < n && curCol >= 0 && curCol < n) {
                    if(sol[curRow][curCol] == 'Q') return false;
                    curRow += i;
                    curCol += j;
                }
            }
        }
        return true;
    }
};
