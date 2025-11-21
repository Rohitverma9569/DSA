class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(first[idx]==-1){
                first[idx]=i;
            }
            last[idx]=i;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(first[i]!=-1){
                if((last[i]-first[i])>=2){
                    set<char>st;
                    for(int j=first[i]+1;j<last[i];j++){
                        char ch=s[j];
                        st.insert(ch);
                    }
                    int k=st.size();
                    ans+=k;
                }
            }
        }
        return ans;     
    }
};