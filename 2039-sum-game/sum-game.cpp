class Solution {
public:
    bool sumGame(string num) {
        int n=num.length();
        int leftqnMark=0;
        int rightqnMark=0;

        int leftknownSum=0;
        int rightknownSum=0;

        for(int i=0;i<n;i++){
            if(num[i]=='?'){
            if(i<n/2){
                leftqnMark++;

            }else{
                rightqnMark++;

            }
            }else{
                if(i<n/2){
                leftknownSum+=num[i]-'0';

            }else{
                rightknownSum+=num[i]-'0';

            }

            }
        }
        int totalqnMark=leftqnMark+ rightqnMark;
        if(totalqnMark%2==1){
            return true;
        }
        int left=2*leftknownSum+ 9*leftqnMark;
        int right=2*rightknownSum+ 9*rightqnMark;
        if(left==right){
            return false;
        }else{
            return true;
        }


    }
};