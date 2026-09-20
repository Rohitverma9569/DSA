class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            int k=ch-'a'+1;
            int a=27-k;
            ans+=a*(i+1);
        }
        return ans;
        
    }
};