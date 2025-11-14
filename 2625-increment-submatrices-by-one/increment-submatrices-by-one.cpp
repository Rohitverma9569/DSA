class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int k=queries.size();
        vector<vector<int>> ans(n,vector<int>(n,0));

        for(int i=0;i<k;i++){
            for(int l=queries[i][0];l<=queries[i][2];l++){
                for(int m=queries[i][1];m<=queries[i][3];m++){
                    ans[l][m]+=1;
                }
            }
        }
        return ans;
        
    }
};