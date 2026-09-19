class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0;
        int j=0;
        int currSum=0;
        vector<int>minbestLentillIndex(n,INT_MAX);
        int result=INT_MAX;
        int bestMinLength=INT_MAX;
        while(j<n){
            currSum+=arr[j];
            while(i<j && currSum>target){
                currSum-=arr[i];
                i=i+1;
            }
            if(currSum==target){
                int len=j-i+1;
                if(i>0 && minbestLentillIndex[i-1]!=INT_MAX){
                    result=min(result,len+minbestLentillIndex[i-1]);
                }
                bestMinLength=min(bestMinLength,len);
            }
            minbestLentillIndex[j]=bestMinLength;
            j++;

        }
        return result==INT_MAX?-1:result;
    }
};