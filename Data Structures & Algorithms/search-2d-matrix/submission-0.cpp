class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = 0;
        int colum = 0;

        int row_max = matrix.size() - 1;
        int colum_max = matrix[0].size() - 1;

        int row_traverse = -1;

        // Find correct row
        while (row <= row_max) {

            int mid = row + (row_max - row) / 2;

            if (target >= matrix[mid][0] &&
                target <= matrix[mid][colum_max]) {

                row_traverse = mid;
                break;
            }
            else if (target < matrix[mid][0]) {
                row_max = mid - 1;
            }
            else {
                row = mid + 1;
            }
        }

        if (row_traverse == -1) return false;

        // Binary search in row
        while (colum <= colum_max) {

            int mid = colum + (colum_max - colum) / 2;

            if (matrix[row_traverse][mid] == target)
                return true;

            else if (matrix[row_traverse][mid] > target) {
                colum_max = mid - 1;
            }
            else {
                colum = mid + 1;
            }
        }

        return false;
    }
};