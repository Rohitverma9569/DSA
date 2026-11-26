class Solution {
public:
    long long solve(vector<int>& piles,int h){
        int n=piles.size();
        long long totalHour=0;
        for(int i=0;i<n;i++){
            totalHour+=ceil((double)piles[i]/(double)h);
        }
        return totalHour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long totalHour=solve(piles,mid);
            if(totalHour<=h){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }

        }
        return ans;
        
        
    }
};
