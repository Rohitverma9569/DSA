class Solution {
public:
static bool cmp(vector<int>inter1,vector<int>inter2){
    return inter1[0]<inter2[0];
}
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        priority_queue<int, vector<int>, greater<int>>pq;
        sort(intervals.begin(),intervals.end(),cmp);

        for(auto interval:intervals){
            int start=interval[0];
            int end=interval[1];
            if(!pq.empty() && start>pq.top()){
                pq.pop();
            }
            pq.push(end);           
        }
        return pq.size();
        
        
    }
};