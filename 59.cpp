// SPIRAL MATRIX II

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n,std::vector<int>(n,0));
        int i = -1, j = 0, current = 1, last = n*n;
        
        while(current <= last){
            while(i+1 < n && matrix[j][i+1] == 0){
                matrix[j][i+1] = current++;
                ++i;
            }
            while(j+1 < n && matrix[j+1][i] == 0){
                matrix[j+1][i] = current++;
                ++j;
            }
            while(i-1 >= 0 && matrix[j][i-1] == 0){
                matrix[j][i-1] = current++;
                --i;
            }
            while(j-1 >= 0 && matrix[j-1][i] == 0){
                matrix[j-1][i] = current++;
                --j;
            }
        }
        return matrix;
    }
};