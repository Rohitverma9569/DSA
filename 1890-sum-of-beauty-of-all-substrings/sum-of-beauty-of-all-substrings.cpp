class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mpp;
            
            for(int j=i;j<n;j++){
                
                mpp[s[j]]++;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                for(auto it:mpp){
                    int freq=it.second;
                    if(freq>maxi){
                        maxi=freq;
                    }
                    if(freq<mini){
                        mini=freq;
                    }
                }
                int beauty=maxi-mini;
                ans+=beauty;           
            }
        }
        return ans;

        
    }
};