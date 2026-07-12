class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({arr[i],i});
        }
        int rank=0;
        vector<int>ans(n);
        int prev=INT_MIN;
        while(pq.size()>0){
            int ele=pq.top().first;
            int ind=pq.top().second;
            if(ele!=prev){
                prev=pq.top().first;
                rank++;
                ans[ind]=rank;
            }
            else{
                ans[ind]=rank;
            }
            pq.pop();
        }
        return ans;     
    }
};