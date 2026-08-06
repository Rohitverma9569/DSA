class Solution {
public:
    int smallestNumber(int n, int t) {
        int k=n+10;
        for(int i=n;i<=k;i++){
            int p=1;
            int m=i;
            while(m>0){
                int digit=m%10;
                m=m/10;
                p=p*digit;
            }
            if(p%t==0){
                return i;
            }
        }
        return 0;
        
    }
};