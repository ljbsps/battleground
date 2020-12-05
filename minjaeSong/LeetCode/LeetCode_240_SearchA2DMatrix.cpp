class Solution {
public:    
   bool row_binary_search(vector<vector<int>>& matrix, int target, int i) { 
        int low = 0, high = matrix.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (target == matrix[mid][i])
                return true;
            if (target < matrix[mid][i]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return false;
    }

    bool col_binary_search(vector<vector<int>>& matrix, int target, int i) {
        int low = 0, high = matrix[0].size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (target == matrix[i][mid])
                return true;
            if (target < matrix[i][mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();  // row size
        int n = matrix[0].size();  // col size
        bool ans = false;
        if (m > n) {
            for (int i = 0; i < n; i++) {
                ans = row_binary_search(matrix, target, i); // row binary
                if (ans) return true;
            }
        }
        else {
            for (int i = 0; i < m; i++) {
                ans = col_binary_search(matrix, target, i);  // col binary
                if (ans) return true;
            }
        }
        return ans;
    }
};