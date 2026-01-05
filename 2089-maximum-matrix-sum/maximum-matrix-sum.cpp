class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        long long neg=0;
        long long sum=0;
        int min=INT_MAX;
        vector<int>vec;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<=0){
                    neg++;
                    sum+=abs(matrix[i][j]);
                    

                }
                else{
                    sum+=matrix[i][j];
                }
                if(abs(matrix[i][j])<min){
                    min=abs(matrix[i][j]);
                }
            }
        }
        if(neg%2==0){
            return sum;
        }
        else{
            sum-=2*min;
        }
        return sum;
    }
};