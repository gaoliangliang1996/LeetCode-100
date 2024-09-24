class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> matrix_bak = matrix;

        for (int i = 0; i < matrix.size(); ++i) { // i 是行
            for (int j = 0; j < matrix[i].size(); ++j) { // j 是列
                if (matrix[i][j] == 0) {
                    for (int x = 0; x < matrix[i].size(); ++x)
                        matrix_bak[i][x] = 0;
                    
                    for (int y = 0; y < matrix.size(); ++y)
                        matrix_bak[y][j] = 0;
                }
            }
        }

        matrix = matrix_bak;
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<bool> rows(m, false);
        vector<bool> cols(n, false);

        for (int i = 0; i < m; ++i) { // i 是行
            for (int j = 0; j < n; ++j) { // j 是列
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for (int i = 0; i < m; ++i) { // i 是行
            for (int j = 0; j < n; ++j) { // j 是列
                if (rows[i] || cols[j])
                    matrix[i][j] = 0;
            }
        }
    }
};
