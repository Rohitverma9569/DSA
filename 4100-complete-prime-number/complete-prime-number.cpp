class Solution {
public:
bool isPrime(int num){
    if(num==2 || num==3) return true;
    if(num<=1) return false;
    if(num%2==0 || num%3==0) return false;
    for(int i=5;i*i<=num;i+=6){
        if(num%i==0 || num%(i+2)==0){
            return false;
        }
    }
    return true;

}
    bool completePrime(int num) {
        int last_num=0;
        if(num==1) return false;
        int l=1;

        while(num>0){
            int suffix;
            if(isPrime(num)==false){
                return false;
            }

                int last_digit=num%10;
                suffix=l*last_digit+last_num;
                
                if(isPrime(suffix)==false){
                    return false;
                }
                num=num/10;
                l=l*10;
                last_num=suffix;
        }
        return true;
        
    }
};