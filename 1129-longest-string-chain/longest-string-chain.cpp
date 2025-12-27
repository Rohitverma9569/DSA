class Solution {
public:
  bool compare(string str1,string str2){
    int n=str1.size();
    int m=str2.size();
    if(n!=m+1) return false;
    int i=0;
    int j=0;
    while(i<n){
        if(str1[i]==str2[j]){
            i++;
            j++;
        }else{
            i++;
        }       
    }
    if(i==n && j==m){
        return true;
    }
    else{
        return false;
    }
    
  }
   static bool comp(string s1,string s2){
    return s1.size()<s2.size();
  }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();

        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(compare(words[i],words[prev])==true && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
        
    }
};