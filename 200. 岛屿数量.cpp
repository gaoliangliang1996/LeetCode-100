class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;

        int row = grid.size();
        if (row == 0) {
            return result;
        }
        int col = grid[0].size();
        if (col == 0) {
            return result;
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    result++;
                    dfs(grid, i, j, row, col);
                }
            }
        }

        return result;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, int row, int col) {
        if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        dfs(grid, i - 1, j, row, col);
        dfs(grid, i + 1, j, row, col);
        dfs(grid, i, j - 1, row, col);
        dfs(grid, i, j + 1, row, col);
    }
};
