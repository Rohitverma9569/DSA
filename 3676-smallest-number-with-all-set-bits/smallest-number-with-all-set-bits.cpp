class Solution {
public:
    int smallestNumber(int n) {
        vector<int> num={1,3,7,15,31,63,127,255,511,1023};
        if(n==1) return 1;
        for(int i=0;i<10;i++){
            if(n>=num[i] && n<=num[i+1]){
                return num[i+1];
            }
        }
        return 0;
        
    }
};