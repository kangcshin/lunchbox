// SPIRAL MATRIX
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n,std::vector<int>(n,0));
        
        int i = -1, j = 0, cur_num = 1, last_num = n*n;
        
        while(cur_num <= last_num)
        {
            while(i+1 < n && matrix[j][i+1] == 0){
                matrix[j][i+1] = cur_num;
                cur_num += 1;
                i += 1;
            }
            while(j+1 < n && matrix[j+1][i] == 0){
                matrix[j+1][i] = cur_num;
                cur_num += 1;
                j += 1;
            }
            while(i-1 >= 0 && matrix[j][i-1] == 0){
                matrix[j][i-1] = cur_num;
                cur_num += 1;
                i -= 1;
            }
            while(j-1 >= 0 && matrix[j-1][i] == 0){
                matrix[j-1][i] = cur_num;
                cur_num += 1;
                j -=1;
            }
        }
        
        return matrix;
    }
};