class Solution {
public:
    string reversePrefix(string s, int k) {
        int n=s.size();
        reverse(s.begin(),s.begin()+k);
        return s;

        
    }
};