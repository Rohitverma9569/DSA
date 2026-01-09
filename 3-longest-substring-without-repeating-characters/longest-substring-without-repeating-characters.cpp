class Solution {
    private:
    
public:

    int lengthOfLongestSubstring(string s) {
        int hash[256];
        std::fill(hash,hash+256,-1);
        int n=s.size();
        int l=0,r=0,maxLen=0;
        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            hash[s[r]]=r;
            int len=r-l+1;
            maxLen=max(len,maxLen);
            r++;
        }
        return maxLen;      
    }
};