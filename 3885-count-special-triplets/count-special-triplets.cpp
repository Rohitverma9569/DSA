class Solution {
public:
int mod=1000000007;
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        vector<long long >prefix(n,0);
        vector<long long>suffix(n,0);
        unordered_map<int,int >mpp;
        for(int i=0;i<n;i++){
            if(mpp.find(nums[i]*2)!=mpp.end()){
                prefix[i]=mpp[nums[i]*2];
                prefix[i]%=mod;
            }
            mpp[nums[i]]++;
        }
        unordered_map<int,int>mpp1;
        for(int i=n-1;i>=0;i--){
            if(mpp1.find(nums[i]*2)!=mpp1.end()){
                suffix[i]=mpp1[nums[i]*2];
                suffix[i]%=mod;
            }
            mpp1[nums[i]]++;

        }
        long long cnt=0;
        for(int i=0;i<n;i++){
            if(prefix[i]>0 && suffix[i]>0){
                long long k=prefix[i]*suffix[i];
                cnt=(cnt+k)%mod;
            }

        }
        return cnt;
        
    }
};