class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n=operations.size();
        unordered_map<string,int> mpp;
        mpp["++X"]=1;
        mpp["X++"]=1;
        mpp["X--"]=-1;
        mpp["--X"]=-1;
        int x=0;
        for(int i=0;i<n;i++){
            x+=mpp[operations[i]];
        }
        return x;
        
    }
};