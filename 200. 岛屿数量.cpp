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

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        int rows = grid.size();
        if (rows == 0)
            return result;
        int cols = grid[0].size();
        if (cols == 0)
            return result;

        queue<pair<int, int>> q;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    result++;
                    q.push({i, j});
                    grid[i][j] = '0';

                    while (!q.empty()) {
                        auto cur = q.front();
                        q.pop();

                        int x = cur.first;
                        int y = cur.second;

                        if (x - 1 >= 0 && grid[x - 1][y] == '1') {
                            grid[x - 1][y] = '0';
                            q.push({x - 1, y});
                        }
                        if (y - 1 >= 0 && grid[x][y - 1] == '1') {
                            grid[x][y - 1] = '0';
                            q.push({x, y - 1});
                        }
                        if (x + 1 < rows && grid[x + 1][y] == '1') {
                            grid[x + 1][y] = '0';
                            q.push({x + 1, y});
                        }
                        if (y + 1 < cols && grid[x][y + 1] == '1') {
                            grid[x][y + 1] = '0';
                            q.push({x, y + 1});
                        }
                    }
                }
            }
        }

        return result;
    }
};
