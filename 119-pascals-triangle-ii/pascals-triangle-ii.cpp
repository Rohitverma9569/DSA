class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n=rowIndex+1;
        vector<int>nums;
    nums.push_back(1);
    long long res=1;
    for(int i=1;i<n-1;i++){
        res=res*(n-i);
        res=res/i;
        nums.push_back(res);
    }
    if(n>1) nums.push_back(1);
    return nums;
        
    }
};