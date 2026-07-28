class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int k=strs[0].size();
        string ans;
        for(int i=0;i<k;i++){
            char ch=strs[0][i];
            for(int j=1;j<n;j++){
                if( strs[j][i]!=ch){
                    return ans;
                }
            }
            ans.push_back(ch);
        }
        return ans;   
    }
};