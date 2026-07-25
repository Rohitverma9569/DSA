class Solution {
public:
    int maxProduct(int n) {
        int high=-1;
        int shigh=-1;
        while(n>0){
            int digit = n%10;
            if(digit>=high){
                
                shigh=high;
                high=digit;

            }
            if(digit>=shigh && digit<high){
                shigh=digit;
            }
            n=n/10;
        }
        return high*shigh;
        
    }
};