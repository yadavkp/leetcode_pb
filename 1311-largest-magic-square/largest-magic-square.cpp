#define ll long long
class Solution {

    bool valid(int i, int n, int j, int m, vector<vector<int>>& mat) {
        // row sums
        ll sum1 = 0;
        for (int r = i; r <= n; r++) {
            ll temp = 0;
            for (int c = j; c <= m; c++) {
                temp += mat[r][c];
            }
            if (r == i) sum1 = temp;
            if (sum1 != temp) return false;
        }

        // column sums
        for (int c = j; c <= m; c++) {
            ll temp = 0;
            for (int r = i; r <= n; r++) {
                temp += mat[r][c];
            }
            if (sum1 != temp) return false;
        }

        // main diagonal
        ll sum2 = 0;
        int r = i, c = j;
        while (r <= n && c <= m) {
            sum2 += mat[r][c];
            r++, c++;
        }
        if (sum2 != sum1) return false;

        // anti-diagonal
        sum2 = 0;
        r = i, c = m;
        while (r <= n && c >= j) {
            sum2 += mat[r][c];
            r++, c--;
        }
        if (sum2 != sum1) return false;

        return true;
    }

public:
    int largestMagicSquare(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 1; i + k < n && j + k < m; k++) {
                    if (valid(i, i + k, j, j + k, mat)) {
                        ans = max(ans, k + 1);
                    }
                }
            }
        }
        return ans;
    }
};