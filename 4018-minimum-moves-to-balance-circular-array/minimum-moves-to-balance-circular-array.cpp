class Solution {
public:
    long long minMoves(vector<int>& balance) {
        
        int n=balance.size();
        long long totSum=0;
        int neg=-1;
        for(int i=0;i<n;i++){
            totSum+=balance[i];
            if(balance[i]<0){
                neg=i;
            }

        }
        if(neg==-1){
            return 0;
        }
        if(totSum<0){
            return -1;
        }
        long long need=-balance[neg];
        long long ans=0;
        for(int dis=1;dis<n && need>0;dis++){
            //right side
            int r=(neg+dis)%n;
            if(balance[r]>0){
                long long take=min((long long)balance[r],need);
                need-=take;
                balance[r]-=take;
                ans=ans+take*dis;

                
            }
            //left side
            int l=(neg-dis+n)%n;
            if(balance[l]>0 && need>0){
                long long take=min((long long)balance[l],need);
                balance[l]-=take;
                need-=take;
                ans=ans+take*dis;
            }
        }
        return ans;

    }
};
