class Solution {
public:
void applyMessageEvent(vector<string>it,vector<int>& ans,vector<int>& offline){
    int timeStamp=stoi(it[1]);
    vector<string>ids;
    stringstream ss(it[2]);
    string token;
    while(ss>>token){
        ids.push_back(token);
    }
    //process all ids
    for(string id:ids){
        if(id=="ALL"){
            for(int i=0;i<ans.size();i++){
                ans[i]++;
            }
        }
        else if(id=="HERE"){
            for(int i=0;i<ans.size();i++){
                if(offline[i]==0 || offline[i]+60<=timeStamp){
                    ans[i]++;
                }
            }
        }
        else{
            ans[stoi(id.substr(2))]++;
        }
    }

}
static bool comparator(vector<string>& vec1 ,vector<string>& vec2){
    int t1=stoi(vec1[1]);
    int t2=stoi(vec2[1]);
    if(t1==t2){
        return vec1[0][1]>vec2[0][1];
    }
    return t1<t2;
}
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(),events.end(),comparator);
        int n=numberOfUsers;
        vector<int>ans(n);
        vector<int>offline(n);
        for(auto it:events){
            auto operation=it[0];
            if(operation=="MESSAGE"){
                applyMessageEvent(it,ans,offline);

            }else if(operation=="OFFLINE"){
                int timeStamp=stoi(it[1]);
                int id=stoi(it[2]);
                offline[id]=timeStamp;
            }
        }
        return ans;

        
    }
};