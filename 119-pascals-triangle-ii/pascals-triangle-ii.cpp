class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        long long prev = 1;
        for (int k = 1; k < rowIndex; ++k) {
            long long curr = prev * (rowIndex - k + 1) / k;
            row[k] = (int)curr;
            prev = curr;
        }
        return row;
    }
};