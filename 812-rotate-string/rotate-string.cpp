class Solution {
public:
    bool rotateString(string s, string goal) {
        string s2=s+s;
        if(s.size()!=goal.size()) return false;
        if(s2.find(goal)!=string::npos){
            return true;
        }
        else{
            return false;
        }
        
    }
};