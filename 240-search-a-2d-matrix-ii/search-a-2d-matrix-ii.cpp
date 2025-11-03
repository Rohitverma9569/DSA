class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=m-1;
        int col=0;
        while(col>=0 && col<n && row<m && row>=0){
            if(matrix[col][row]==target){
                return true;
            }else if(matrix[col][row]>target){
                row--;
            }else{
                col++;
            }
        }
        return false; 
    }
};