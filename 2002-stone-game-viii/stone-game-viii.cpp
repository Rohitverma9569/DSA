class Solution {
public:
int n;
int t[100001];

int solve(int i, vector<int>prefixSum){
    if(i==n-1){
        return prefixSum[n-1];
    }
    if(t[i]!=-1){
        return t[i];
    }
    int take=prefixSum[i]-solve(i+1,prefixSum);
    int notTake=solve(i+1,prefixSum);
    return t[i]=max(take,notTake);

}

    int stoneGameVIII(vector<int>& stones) {
        n=stones.size();
        memset(t,-1,sizeof(t));
        vector<int>prefixSum(n);
        prefixSum[0]=stones[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=stones[i]+prefixSum[i-1];
        }
        
        //return solve(1,prefixSum);
        t[n-1]=prefixSum[n-1];
        for(int i=n-2;i>=1;i--){
            int take=prefixSum[i]-t[i+1];
            int notTake=t[i+1];
            t[i]=max(take,notTake);
        }
        return t[1];
        
        
    }
};