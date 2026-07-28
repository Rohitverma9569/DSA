class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word="";
        string token;
        while(ss>>token){
             if(!word.empty()){
                word=token+" "+word;

             }
             else{
                word=token;

             }
        }
        return word;
        
    }
};