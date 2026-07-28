class Solution {
public:
static bool comparator(pair<char,int>&p1, pair<char,int>&p2){
    return p1.second>p2.second;
}
    string frequencySort(string s) {
        vector<pair<char,int>>vec;
        unordered_map<char,int>mpp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        for(auto &it :mpp){
            char ch=it.first;
            int f=it.second;
            vec.push_back({ch,f});

        }
        sort(vec.begin(),vec.end(),comparator);
        string result;
        for(auto it:vec){
            int ch=it.first;
            int num=it.second;
            string temp=string(num,ch);
            result+=temp;
        }
        return result;


        
        
    }
};