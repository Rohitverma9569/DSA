class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        int k=s.size();
        string p="";
        long long sum=0;
        for(int i=0;i<k;i++){
            if(s[i]=='0'){
                continue;
            }
            else{
                p+=s[i];
                long long m=s[i]-'0';
                sum+=m;
            }
        }
        if(p==""){
            return 0;
        }
        long long b=stoll(p);
        long long ans=sum*b;
        return ans;    
    }
};