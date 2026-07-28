class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m){
            return false;
        }
        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;
        for(int i=0;i<n;i++){
            if (mp1.count(s[i])) {
                if (mp1[s[i]] != t[i])
                    return false;
            } else {
                mp1[s[i]] = t[i];
            }

            if (mp2.count(t[i])) {
                if (mp2[t[i]] != s[i])
                    return false;
            } else {
                mp2[t[i]]=s[i];
                }
        }
        return true;
        
    }
};