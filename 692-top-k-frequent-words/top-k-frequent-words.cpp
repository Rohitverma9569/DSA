class Solution {
public:
static bool cmp(pair<int,string>&p1,pair<int,string>& p2){
    if(p1.first==p2.first){
        return p1.second<p2.second;
    }
    else{
        return p1.first>p2.first;
    }
}
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mpp;
        for(auto it:words){
            mpp[it]++;
        }
        int n=mpp.size();
        vector<pair<int,string>>vec;
        for(auto it:mpp){
            vec.push_back({it.second,it.first});
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<string>ans;
        for(int i=0;i<k;i++){
            auto p=vec[i];
            ans.push_back(p.second);            
        }
        return ans;
        
    }
};