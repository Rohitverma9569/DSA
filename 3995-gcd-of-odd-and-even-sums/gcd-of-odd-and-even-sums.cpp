class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int evenGcd=0;
        int oddGcd=0;
        for(int i=1;i<=2*n;i++){
            if(i%2==0){
                evenGcd+=i;
            }else{
                oddGcd+=i;
            }
        }
    
        int result=__gcd(evenGcd,oddGcd);
        return result;
    }
};