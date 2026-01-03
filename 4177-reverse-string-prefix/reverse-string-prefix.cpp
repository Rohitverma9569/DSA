class Solution {
public:
    string reversePrefix(string s, int k) {
        int n=s.size();
        string ans="";
        for(int i=k-1;i>=0;i--){
            ans+=s[i];

        }
        for(int i=k;i<n;i++){
            ans+=s[i];
        }
        return ans;

        
    }
};