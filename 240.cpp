// SEARCH A 2D MATRIX II

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()  == 0) return false;
        
        int m = matrix.size()-1, n = 0;
        
        while(m >= 0 && n < matrix[0].size()){
            if(matrix[m][n] == target) return true;
            
            else if(matrix[m][n] < target) n += 1;
            else m -= 1;
        }
        return false;
    }
};